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

from fubuki.data import registry
from fubuki.formatting.string import to_snake_case

#------------------------------------------------------------------------------

# The following are are not obtainable through the generic mechanism (vkGetInstanceProcAddr, vkGetDeviceProcAddr)
_SPECIAL_PFNS = {\
"vkCreateInstance",\
"vkEnumerateInstanceExtensionProperties",\
"vkEnumerateInstanceLayerProperties",\
"vkEnumerateInstanceVersion",\
}


def core_hpp(api_registry: registry.api, args: dict) -> dict:
#{
    result = {"types" : "", "members" : "","get_from": ""}

    level = args["level"]

    type_declaration_format = """
#if defined(@FEATURE_NAME@)
    struct @FEAT_SHORT@_core_functions
    {
        struct command
        {
@COMMANDS@
        };

@REGULAR_FUNCTIONS@

        command cmd = {};
    };

    [[nodiscard]]
    operator const @FEAT_SHORT@_core_functions&() const{return @FEAT_SHORT@;}
#endif // #if defined(@FEATURE_NAME@)
"""

    member_format = """
#if defined(@FEATURE_NAME@)
    @FEAT_SHORT@_core_functions @FEAT_SHORT@ = {};
#endif // #if defined(@FEATURE_NAME@)
"""

    function_format = "@VK_TYPE@ @FUBUKI_NAME@ = nullptr;\n"

    get_from_format = "FUBUKI_MAKE_GET_FROM(@VK_FUNCTION_NAME@, @STRUCT@, @FUBUKI_NAME@);\n"

    for _, feat in api_registry.features.items():
    #{
        if("vulkan" not in feat.apis):
        #{
            continue # Skip Vulkan SC
        #}

        short_feat_name = "vk" + str(feat.number.major) + str(feat.number.minor)

        commands          = ""
        regular_functions = ""
        get_from          = ""

        for _, func in feat.functions.items():
        #{
            if(func.level != level):
            #{
                continue
            #}

            fubuki_name = to_snake_case(func.name).removeprefix("vk_")

            regular_functions += "        " + function_format.replace("@VK_TYPE@", "PFN_" + func.name) \
                                                             .replace("@FUBUKI_NAME@", fubuki_name)

            get_from += get_from_format.replace("@VK_FUNCTION_NAME@", func.name)\
                                       .replace("@STRUCT@", short_feat_name) \
                                       .replace("@FUBUKI_NAME@", fubuki_name)
        #}

        for _, cmd in feat.commands.items():
        #{
            if(cmd.level != level):
            #{
                continue
            #}

            fubuki_name = to_snake_case(cmd.name).removeprefix("vk_cmd_")

            commands += "            " + function_format.replace("@VK_TYPE@", "PFN_" + cmd.name) \
                                                        .replace("@FUBUKI_NAME@", fubuki_name)

            get_from += get_from_format.replace("@VK_FUNCTION_NAME@", cmd.name)\
                                       .replace("@STRUCT@", short_feat_name + ".cmd") \
                                       .replace("@FUBUKI_NAME@", fubuki_name)
        #}

        result["types"] += type_declaration_format.replace("@FEATURE_NAME@", feat.name) \
                                                  .replace("@FEAT_SHORT@", short_feat_name) \
                                                  .replace("@COMMANDS@", commands) \
                                                  .replace("@REGULAR_FUNCTIONS@", regular_functions)

        result["members"] += member_format.replace("@FEATURE_NAME@", feat.name) \
                                          .replace("@FEAT_SHORT@", short_feat_name)

        result["get_from"] += get_from
    #}

    return result
#}

#------------------------------------------------------------------------------

def core_cpp(api_registry: registry.api, args: dict) -> dict:
#{
    level = args["level"]

    prerequisites = """    fubuki_assert(instance != null_handle, "Instance must not be a null handle.");
    fubuki_assert(version >= version_number(1, 0, 0), "Invalid version.");"""

    if(level == "device"):
    #{
        prerequisites += """
    fubuki_assert(device != null_handle, "Device must not be a null handle.");

    auto* const getter = pfn<"vkGetDeviceProcAddr">(instance);"""
    #}

    load_args = "instance, device, getter" if level == "device" else "instance"

    loading = ""
    return_statement = ""

    loading_format = """
#if defined(@FEATURE_NAME@)
    @LEVEL@_core_functions::@FEAT_SHORT@_core_functions @FEAT_SHORT@ = {};

    if(version >= version_number{@VERSION_MAJOR@, @VERSION_MINOR@, 0})
    {
        // clang-format off
        @FEAT_SHORT@ =
        {
@REGULAR_FUNCTIONS@
            .cmd =
            {
@COMMANDS@
            },
        };
        // clang-format on
    }
#endif // #if defined(@FEATURE_NAME@)
"""

    return_statement_format = """
#if defined(@FEATURE_NAME@)
            @FEAT_SHORT@,
#endif //  #if defined(@FEATURE_NAME@)
"""

    load_function_format = """.@FUBUKI_NAME@ = pfn<"@VK_NAME@">(@LOAD_ARGS@),
"""

    for _, feat in api_registry.features.items():
    #{
        if("vulkan" not in feat.apis):
        #{
            continue # Skip Vulkan SC
        #}

        short_feat_name = "vk" + str(feat.number.major) + str(feat.number.minor)

        regular_functions = ""
        commands          = ""

        for _, func in feat.functions.items():
        #{
            if(func.level != level):
            #{
                continue
            #}

            fubuki_name = to_snake_case(func.name).removeprefix("vk_")

            if(func.name in _SPECIAL_PFNS):
            #{
                # Some functions are not available through the generic mechanism
                regular_functions += "            ." + fubuki_name + " = " + func.name + ",\n"
            #}
            else:
            #{
                regular_functions += "            " + load_function_format.replace("@FUBUKI_NAME@", fubuki_name) \
                                                                          .replace("@VK_NAME@", func.name) \
                                                                          .replace("@LOAD_ARGS@", load_args)
            #}


        #}

        for _, cmd in feat.commands.items():
        #{
            if(cmd.level != level):
            #{
                continue
            #}

            fubuki_name = to_snake_case(cmd.name).removeprefix("vk_cmd_")
            commands += "                " + load_function_format.replace("@FUBUKI_NAME@", fubuki_name) \
                                                                 .replace("@VK_NAME@", cmd.name) \
                                                                 .replace("@LOAD_ARGS@", load_args)
            pass
        #}

        loading += loading_format.replace("@FEATURE_NAME@", feat.name) \
                                 .replace("@FEAT_SHORT@", short_feat_name) \
                                 .replace("@LEVEL@", level) \
                                 .replace("@VERSION_MAJOR@", str(feat.number.major)) \
                                 .replace("@VERSION_MINOR@", str(feat.number.minor)) \
                                 .replace("@REGULAR_FUNCTIONS@", regular_functions) \
                                 .replace("@COMMANDS@", commands) \

        return_statement += return_statement_format.replace("@FEATURE_NAME@", feat.name) \
                                                   .replace("@FEAT_SHORT@", short_feat_name)
    #}

    function_body_format = """@PREREQUISITES@
@LOADING@
    return
    {
@RETURN@
    };
"""

    generated_code = function_body_format.replace("@PREREQUISITES@", prerequisites) \
                                         .replace("@LOADING@", loading) \
                                         .replace("@RETURN@", return_statement)

    return {"generated_code": generated_code}
#}

#------------------------------------------------------------------------------

def finalise(license: str, api_registry: registry.api, template: str, generated_code: dict, args: dict) -> str:
#{
    """
    args:
    {
        "level:" str - Either "instance" or "device"
        "file:" str - Either "cpp" or "hpp"
    }
    """
    level     : str    = args["level"]
    struct_name        = level + "_core_functions"
    load_function_args = ""
    load_function_args = "instance_handle instance, version_number version" \
                         if level == "instance" \
                         else "instance_handle instance, version_number version, device_handle device"

    members =  generated_code.get("members", "")

    if(args["file"] == "cpp"):
    #{
        return license + template.replace("@STRUCT_NAME@", struct_name) \
                                 .replace("@LEVEL@", level) \
                                 .replace("@LOAD_FUNCTION_ARGS@", load_function_args) \
                                 .replace("@LOAD_FUNCTION_BODY@", generated_code.get("generated_code", ""))
    #}

    if(args["file"] == "hpp"):
    #{
        return license + template.replace("@LEVEL_UPPER@", level.upper()) \
                                 .replace("@STRUCT_NAME@", struct_name) \
                                 .replace("@LEVEL@", level) \
                                 .replace("@TYPES@", generated_code.get("types", "")) \
                                 .replace("@MEMBERS@", members) \
                                 .replace("@LOAD_FUNCTION_ARGS@", load_function_args) \
                                 .replace("@GET_FROM@", generated_code.get("get_from", ""))
    #}

    return "Internal error while generating - invalid type '" + args["type"] + "'\n"
#}
