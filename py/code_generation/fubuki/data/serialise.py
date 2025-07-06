#
# BSD 2-Clause License
#
# Copyright (c) 2025, Erwan DUHAMEL
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

import xml.etree.ElementTree as xml_tree
import pathlib

from html.parser import HTMLParser

from . import registry

# WARNING: the order matters when parsing the registry.
# Dependencies:
#    - retrieve_vendors: none
#    - retrieve_structures: none
#    - retrieve_enums: none
#    - retrieve_formats: none
#    - retrieve_handles: vendors, structures
#    - retrieve_features: handles, structures, enums, formats
#    - retrieve_extensions: handles, structures, enums, formats
#
# To fully parse the registry, call these functions in the order specified above, or directly parse_registry_file().

def retrieve_commands(root: xml_tree.Element) -> dict:
#{
    result = dict()
    aliases = set()

    # Parameters indicating that the command is device-level if first argument
    device_level_indicators = {"VkDevice", "VkCommandBuffer", "VkQueue"}

    for command in root.find("commands").findall("command"):
    #{
        if("alias" in command.attrib):
        #{
            aliases.add(registry.alias(old=command.attrib["name"], new=command.attrib["alias"]))
            continue
        #}

        apis = set(command.attrib["api"].split(",")) if "api" in command.attrib else {"vulkan"}

        function = registry.command(name="", result="", args=[], level="", apis=apis)

        proto_node = command.find("proto")
        function.name = proto_node.find("name").text
        function.result = proto_node.find("type").text

        for param_node in command.iter("param"):
        #{
            type_node = param_node.find("type")

            if(type_node is None):
            #{
                # Can happen for <params/> in <implicitexternsyncparams/>
                continue
            #}

            function.args.append(registry.command.argument(type=type_node.text, name=param_node.find("name").text))
        #}

        # All arguments are required to determine the level of the function
        # Note that this is fixed separately in the top-level function for some commands, such as "vkDestroyDevice" or "vkGetDeviceProcAddr"
        function.level = "device" if (len(function.args) > 0 and function.args[0].type in device_level_indicators) else "instance"

        result.setdefault(function.name, function)
    #}

    # Corrections too painful or too slow to introduce in the parsing above
    for command in {"vkDestroyDevice", "vkGetDeviceProcAddr"}:
    #{
        result[command].level = "instance"
    #}

    for alias in aliases:
    #{
        core_function = result[alias.new]
        result.setdefault(alias.old, registry.command(name=alias.old,
                                                      result=core_function.result,
                                                      args=core_function.args,
                                                      level=core_function.level,
                                                      apis=core_function.apis))
    #}

    return result
#}

def retrieve_enums(root: xml_tree.Element, api_registry: registry.api):
#{
    result = dict()

    for enum_node in root.iter("enums"):
    #{
        enum_name = enum_node.attrib["name"]
        enum_type = enum_node.attrib["type"] if "type" in enum_node.attrib else "unknown"

        enum = registry.enum(name=enum_name, values=dict(), type=enum_type, provenance="", apis={"vulkan"})
        for value in enum_node.iter("enum"):
        #{
            # Provenance is updated later when needed, when parsing the <feature/> tags (<require/> to be precise)
            value_name = value.attrib["name"]
            alias = value.attrib.get("alias", "")
            protect = value.attrib.get("protect", "")

            enum.values.setdefault(value_name, registry.enum.value(name=value_name, provenance="VK_VERSION_1_0", protect=protect, alias_to=alias, apis={"vulkan"}))
        #}
        result.setdefault(enum_name, enum)
    #}

    api_registry.enums = result
#}

def retrieve_structures(structures: list, api_registry: registry.api):
#{
    result = dict()

    # Format {extended_structures: str, possible extensions: set} where the values for each key contain registry.pnext_element
    pnext_extensions = dict()

    for structure in structures:
    #{
        name : str = structure.attrib["name"]
        category     = structure.attrib["category"]
        members    = dict()
        allowed_in = set()

        if("structextends" in structure.attrib):
        #{
            extended_structures : list = structure.attrib["structextends"].split(",")
            allowed_in = set(extended_structures)

            for extended_structure in extended_structures:
            #{
                if(extended_structure not in pnext_extensions):
                #{
                    pnext_extensions.setdefault(extended_structure, set())
                #}

                # Unless otherwise specified, the structures must be unique
                unique: bool = True

                if("allowduplicate" in structure.attrib and structure.attrib["allowduplicate"] == "true"):
                #{
                    unique = False
                #}

                pnext_extensions[extended_structure].add(registry.pnext_element(name=name, unique=unique))
            #}
        #}

        structure_type = ""

        for member in structure.findall("member"):
        #{
            member_name = member.find("name").text
            member_type = member.find("type").text

            if (member_name == "sType" and "values" in member.attrib): # VkBaseInStructure/VkBaseOutStructure don't have a specified sType
            #{
                structure_type = member.attrib["values"]
            #}

            members[member_name] = registry.structure.member(name=member_name, type=member_type)
        #}

        alias = structure.attrib["alias"] if "alias" in structure.attrib else ""

        result.setdefault(name,
                          registry.structure(name=name,
                                             category=category,
                                             type_enum=structure_type,
                                             pnext=set(), # Done below, when all structures have been collected
                                             members=members,
                                             allowed_in=allowed_in, # Also done below
                                             provenance="VK_VERSION_1_0", # Done later too, when parsing extensions and features
                                             alias_to=alias,
                                             apis={"vulkan"})) # Again, updated later
    #}

    # Second pass for the pnext chains
    for name, structure in result.items():
    #{
        structure.pnext = pnext_extensions.get(name, set())
    #}

    api_registry.structures = result
#}

def retrieve_handles(handles: list, commands: list, api_registry: registry.api):
#{
    result = dict()

    create_function_prefix  : set = {"vkCreate", "vkAllocate"}
    destroy_function_prefix : set = {"vkDestroy", "vkFree"}
    create_struct_suffix    : set = {"CreateInfo", "AllocateInfo"}
    pfn_suffix              : set = {"", "s"} # Second try, some handles are allocated in "packs"

    def make_traits(handle_name: str, commands: list, structures: dict):
    #{
        vendor = ""
        name_short = name.removeprefix("Vk")

        for v in api_registry.vendors:
        #{
            if handle_name.endswith(v):
            #{
                vendor = v
                break
            #}
        #}

        create_struct = ""
        create_pfn    = ""
        destroy_pfn   = ""

        for prefix in create_function_prefix:
        #{
            for suffix in pfn_suffix:
            #{
                candidate = prefix + name_short.removesuffix(vendor) + suffix + vendor
                if(candidate in commands):
                #{
                    create_pfn = candidate
                    break
                #}
            #}
            else:
            #{
                continue
            #}
        #}

        for prefix in destroy_function_prefix:
        #{
            for suffix in pfn_suffix:
            #{
                candidate = prefix + name_short.removesuffix(vendor) + suffix + vendor
                if(candidate in commands):
                #{
                    destroy_pfn = candidate
                    break
                #}
            #}
            else:
            #{
                continue
            #}
        #}

        for suffix in create_struct_suffix:
        #{
            candidate = handle_name.removesuffix(vendor) + suffix + vendor
            if(candidate in structures):
            #{
                create_struct = candidate
                break
            #}
        #}

        return create_struct, create_pfn, destroy_pfn
    #}

    for handle in handles:
    #{
        if("alias" in handle.attrib):
        #{
            # Skip alias that have been merged into Vulkan core
            # Unlike commands, these have to be skipped because the type is identical as for
            continue
        #}

        name = handle.find("name").text

        create_struct, create_pfn, destroy_pfn = make_traits(handle_name=name, commands=commands, structures=api_registry.structures)

        result.setdefault(name,
                          registry.handle(name=name,
                                          parent=handle.attrib["parent"] if "parent" in handle.attrib else "",
                                          type_enum=handle.attrib["objtypeenum"],
                                          create_struct=create_struct,
                                          create_pfn=create_pfn,
                                          destroy_pfn=destroy_pfn,
                                          provenance="VK_VERSION_1_0",
                                          apis={"vulkan"}))
    #}

    api_registry.handles = result
#}

def retrieve_formats(root: xml_tree.Element, api_registry: registry.api):
#{
    result = dict()

    for format_node in root.find("formats").findall("format"):
    #{
        format_name = format_node.attrib["name"]

        block = registry.format.block(w=1, h=1, d=1)
        if("blockExtent" in format_node.attrib):
        #{
            extent = format_node.attrib["blockExtent"].split(",")
            block.w = int(extent[0])
            block.h = int(extent[1])
            block.d = int(extent[2])
        #}

        chroma = int(format_node.attrib["chroma"]) if "chroma" in format_node.attrib else -1
        packing = int(format_node.attrib["packed"]) if "packed" in format_node.attrib else -1

        format = registry.format(name=format_name,
                                 block_size = int(format_node.attrib["blockSize"]),
                                 block_extent=block,
                                 texels_per_block=int(format_node.attrib["texelsPerBlock"]),
                                 components=dict(),
                                 chroma=chroma,
                                 packing=packing,
                                 planes=[],
                                 provenance="VK_VERSION_1_0", # Updated later when parsing features and extensions
                                 apis={"vulkan"}) # Same, updated later

        for component_node in format_node.findall("component"):
        #{
            component_name = component_node.attrib["name"]
            bits           = component_node.attrib["bits"]
            plane_index    = int(component_node.attrib["planeIndex"]) if "planeIndex" in component_node.attrib else -1

            format.components.setdefault(component_name,
                                         registry.format.component(name=component_name,
                                                                   bits=int(bits) if bits != "compressed" else 0,
                                                                   numeric=component_node.attrib["numericFormat"],
                                                                   plane_index=plane_index))
        #}

        for plane_node in format_node.findall("plane"):
        #{
            format.planes.append(registry.format.plane(index=int(plane_node.attrib["index"]),
                                                       width_divisor=int(plane_node.attrib["widthDivisor"]),
                                                       height_divisor=int(plane_node.attrib["heightDivisor"]),
                                                       compatible=plane_node.attrib["compatible"]))
        #}


        result.setdefault(format_name, format)
    #}

    api_registry.formats = result
#}

def parse_feature_or_extension_node(node: xml_tree.Element, commands: dict, api_registry: registry.api, type: str):
#{
    # Expects type=="feature" or type=="extension"

    result = None
    result_apis = set()

    if(type == "feature"):
    #{
        result_apis = set(node.attrib["api"].split(",")) if "api" in node.attrib else {"vulkan"}
        number = registry.version(major=0, minor=0, patch=0)
        number_tokens = (node.attrib["number"] if "number" in node.attrib else "").split(".")

        number.major = int(number_tokens[0]) if(len(number_tokens) > 0) else 0
        number.minor = int(number_tokens[1]) if(len(number_tokens) > 1) else 0
        number.patch = int(number_tokens[2]) if(len(number_tokens) > 2) else 0 # Note indicated yet though

        result = registry.feature(name=node.attrib["name"],
                                  functions=dict(),
                                  commands=dict(),
                                  number=number,
                                  apis=result_apis)
    #}

    if (type == "extension"):
    #{
        result_apis = set(node.attrib["supported"].split(",")) if "supported" in node.attrib else {"vulkan"}
        promotions = set(node.attrib["promotedto"].split(",")) if "promotedto" in node.attrib else set()

        result = registry.extension(name=node.attrib["name"],
                                    type=node.attrib["type"] if "type" in node.attrib else "",
                                    functions=dict(),
                                    commands=dict(),
                                    apis=result_apis,
                                    promoted_to=promotions)
    #}

    for require_node in node.findall("require"):
    #{
        apis = set(require_node.attrib["api"].split(",")) if "api" in require_node.attrib else {"vulkan"}

        for enum_node in require_node.findall("enum"):
        #{
             # Indicates a new value is provided by this feature/extension
            if "extends" in enum_node.attrib:
            #{
                enum_type = enum_node.attrib["extends"]
                value = enum_node.attrib["name"]

                if(enum_type == "VkFormat"):
                #{
                    format = api_registry.formats.get(value)

                    # False when some values are aliased like VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT
                    if(format is not None):
                    #{
                        format.provenance = result.name
                        format.apis = apis
                    #}
                #}

                alias   = enum_node.attrib.get("alias", "")
                protect = enum_node.attrib.get("protect", "")

                api_registry.enums[enum_type].values.setdefault(value, registry.enum.value(name=value, provenance=result.name, protect=protect, alias_to=alias, apis=apis))
            #}
        #}

        for type_node in require_node.findall("type"):
        #{
            name      = type_node.attrib["name"]
            as_handle = api_registry.handles.get(name)

            if(as_handle is not None):
            #{
                as_handle.provenance = result.name
                as_handle.apis = apis
                continue
            #}

            as_struct = api_registry.structures.get(name)

            if(as_struct is not None):
            #{
                as_struct.provenance = result.name
                as_struct.apis = apis
                continue
            #}

            # API constants are provided as <enum/> tags, so they don't exist in the representation we build
            as_enum = api_registry.enums.get(name)

            if(as_enum is not None):
            #{
                as_enum.provenance = result.name

                for _, value in as_enum.values.items():
                #{
                    # Only override when not encountered yet
                    if(value.provenance == "VK_VERSION_1_0"):
                    #{
                        value.provenance = result.name
                        value.apis = apis
                    #}
                #}
                continue
            #}
        #}

        for command_node in require_node.findall("command"):
        #{
            name = command_node.attrib["name"]
            command = commands[name]
            command.apis = apis

            if(name.startswith("vkCmd")):
            #{
                result.commands.setdefault(name, command)
            #}
            else:
            #{
                result.functions.setdefault(name, command)
            #}
        #}
    #}

    return result
#}

def retrieve_features(root: xml_tree.Element, commands: dict, api_registry: registry.api):
#{
    result = dict()

    for feature_node in root.findall("feature"):
    #{
        feature = parse_feature_or_extension_node(feature_node, commands, api_registry, "feature")

        if(feature is not None):
        #{
            result.setdefault(feature.name, feature)
        #}
    #}

    api_registry.features = result
#}

def retrieve_extensions(root: xml_tree.Element, commands: dict, api_registry: registry.api):
#{
    result = dict()

    for extension_node in root.find("extensions").findall("extension"):
    #{
        extension = parse_feature_or_extension_node(extension_node, commands, api_registry, "extension")

        # It's still required to parse the node to get the extension provider for some types
        if("supported" in extension_node.attrib and extension_node.attrib["supported"] == "disabled"):
        #{
            continue
        #}

        if(extension is not None):
        #{
            result.setdefault(extension.name, extension)
        #}
    #}

    api_registry.extensions = result
#}

def retrieve_vendors(root: xml_tree.Element, api_registry: registry.api):
#{
    result = set()
    for tag in root.find("tags").findall("tag"):
    #{
        result.add(tag.attrib["name"])
    #}
    api_registry.vendors = result
#}

def parse_registry_file(registry_xml: pathlib.Path) -> registry.api:
#{
    tree = xml_tree.parse(registry_xml)
    root = tree.getroot()

    types             = root.find("types").findall("type")
    commands          = retrieve_commands(root)
    structures        = []
    handles           = []

    for type in types:
    #{
        if "category" not in type.attrib:
        #{
            continue
        #}

        match type.attrib["category"]:
        #{
            case "handle":
            #{
                handles.append(type)
            #}
            case "struct":
            #{
                structures.append(type)
            #}
            case "union":
            #{
                structures.append(type) # Handled at the same level
            #}
            case _:
            #{
                pass
            #}
        #}
    #}

    result = registry.api(enums=dict(),
                          handles=dict(),
                          formats=dict(),
                          structures=dict(),
                          features=dict(),
                          extensions=dict(),
                          vendors=set())

    # WARNING: the order matters.
    # See the top of the file for more information about the dependencies.

    retrieve_vendors(root=root, api_registry=result)
    retrieve_structures(structures, api_registry=result)
    retrieve_enums(root=root, api_registry=result)
    retrieve_handles(handles=handles, commands=commands,api_registry=result)
    retrieve_formats(root=root, api_registry=result)
    retrieve_features(root=root, commands=commands, api_registry=result)
    retrieve_extensions(root=root, commands=commands, api_registry=result)

    return result
#}
