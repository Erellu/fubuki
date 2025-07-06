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

from dataclasses import dataclass

from fubuki.data import registry
from fubuki.formatting.string import to_snake_case

#------------------------------------------------------------------------------

def _signature(func: registry.command, api_registry: registry.api, export: bool) -> str:
#{
    int_types = {"int8_t", "uint8_t", "int16_t", "uint16_t", "int32_t", "uint32_t", "int64_t", "uint64_t", "size_t"}
    short_name = to_snake_case(func.name).removeprefix("vk_").removeprefix("cmd_")

    result = "" if func.result == "void" else "[[nodiscard]] "

    if(export):
    #{
        result += "FUBUKI_EXTENSION_API"
    #}

    result += (" " + func.result)

    vendor_suffix = ""
    for v in api_registry.vendors:
    #{
        if(func.name.endswith(v)):
        #{
            vendor_suffix = "_" + v.lower()
            break
        #}
    #}

    result += " " + short_name.removesuffix(vendor_suffix)

    result += "(const functions& ext, "
    for arg in func.args:
    #{
        if(arg.type in api_registry.handles):
        #{
            result += (to_snake_case(arg.type).removeprefix("vk_") + "_handle")
        #}
        elif(arg.type in int_types):
        #{
            result += ("std::" + arg.type)
        #}
        else:
        #{
            result += arg.type
        #}

        result += (" " + to_snake_case(arg.name) + ",")
    #}
    result = result.removesuffix(",")
    result += ") noexcept"

    return result
#}

#------------------------------------------------------------------------------

def functions_hpp(api_registry: registry.api, args: dict) -> dict:
#{
    """
    args: {"name": str - Name of the extension}
    """

    extern_static_load_format = """/// Loads the extension.
[[nodiscard]] FUBUKI_EXTENSION_API static @SHORT_NAME@ load(@ARGS@) noexcept;"""

    inline_static_load_format = """/// Loads the extension.
[[nodiscard]] static constexpr @SHORT_NAME@ load(@ARGS@) noexcept {return {};}"""

    free_load_format = """/// Loads the extension.
    [[nodiscard]] inline functions load(@ARGS@) noexcept{return functions::load(@ARGS_NAME@);}"""

    member_pfn_formats = """
    struct command
    {
    @COMMANDS@
    };

@REGULAR_FUNCTIONS@
    command cmd = {};
"""

    ext = api_registry.extensions[args["name"]]

    has_new_commands = (len(ext.functions) == 0 and len(ext.commands) == 0)

    load_function_args = "[[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version" if ext.type == "instance" else "[[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device"
    load_function_args_name = "instance, vk_version" if ext.type == "instance" else "instance, vk_version, device"

    static_load_format = inline_static_load_format if has_new_commands else extern_static_load_format

    regular_functions_pfn = ""
    commands_pfn          = ""
    get_from              = ""

    for _, function in ext.functions.items():
    #{
        short_pfn_name = to_snake_case(function.name).removeprefix("vk_")
        regular_functions_pfn += "    PFN_" + function.name + " " + short_pfn_name +" = nullptr;\n"
        get_from += "FUBUKI_MAKE_GET_FROM(" + function.name + "," + short_pfn_name +");\n"
    #}

    for _, cmd in ext.commands.items():
    #{
        short_pfn_name = to_snake_case(cmd.name).removeprefix("vk_cmd_")
        commands_pfn += "        PFN_" + cmd.name + " " + short_pfn_name +" = nullptr;\n"
        get_from += "FUBUKI_MAKE_GET_FROM(" + cmd.name + ", cmd." + short_pfn_name +");\n"
    #}

    return \
    { \
        "static_load": static_load_format.replace("@ARGS@", load_function_args), \
        "free_load": free_load_format.replace("@ARGS@", load_function_args).replace("@ARGS_NAME@", load_function_args_name), \
        "member_pfn": member_pfn_formats.replace("@COMMANDS@", commands_pfn).replace("@REGULAR_FUNCTIONS@", regular_functions_pfn), \
        "get_from": get_from
    }
#}

#------------------------------------------------------------------------------

def hpp(api_registry: registry.api, args: dict) -> dict:
#{
    """
    args: {"name": str - Name of the extension}
    """

    ext = api_registry.extensions[args["name"]]

    regular_free_functions = ""
    free_commands          = ""

    for _, function in ext.functions.items():
    #{
        doc = "/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/" + function.name + ".html"
        regular_free_functions += doc + "\n" + _signature(func=function, api_registry=api_registry, export=True) + ";\n\n"
    #}

    for _, cmd in ext.commands.items():
    #{
        doc = "/// @see https://registry.khronos.org/vulkan/specs/latest/man/html/" + cmd.name + ".html"
        free_commands += doc + "\n" + _signature(func=cmd, api_registry=api_registry, export=True) + ";\n\n"
    #}

    return \
    {\
        "free_functions": regular_free_functions,\
        "free_commands": free_commands
    }
#}

#------------------------------------------------------------------------------

def instance_device_hpp(api_registry: registry.api, args: dict) -> dict:
#{
    """
    args:
    {
        "level:" str - Either "instance" or "device"
        "file:" str - Either "cpp" or "hpp"
    }
    """

    @dataclass
    class get_from_entry:
    #{
        obtain: str # The logic to obtain the PFN
        providers: set # set(str), list of the extensions providing the PFN
    #}

    get_from_provider_format = """
#if defined(@PROVIDER@)
    if(functions.@EXT_SHORT_NAME@)
    {
        static_assert(
            requires {
                {functions.@EXT_SHORT_NAME@};
            }, "Internal error. Bad name or version structure.");

        static_assert(get_from<extension::functions::@EXT_SHORT_NAME@, "@FUNCTION_NAME@">::valid, "Internal error. Wrong extension");

        return get_from<extension::functions::@EXT_SHORT_NAME@, "@FUNCTION_NAME@">::get(*functions.@EXT_SHORT_NAME@);
    }
#endif // defined(@PROVIDER@)
"""

    level     : str    = args["level"]
    struct_name        = level + "_functions"

    includes    = ""
    members     = ""

    seen_by_get_from = dict() # dict(str: pfn name, get_from_entry: generated code)

    load_function_args = "instance_handle instance, version_number version" \
                         if level == "instance" \
                         else "instance_handle instance, version_number version, device_handle device"

    for _, ext in api_registry.extensions.items():
    #{
        if("vulkan" not in ext.apis or ext.type != level or ext.name in registry.enumerate_surface_extensions()):
        #{
            continue
        #}

        short_name = to_snake_case(ext.name).removeprefix("vk_")

        includes += """#include "extension/functions/""" + short_name + '.hpp"\n'
        members += """    FUBUKI_DECLARE_EXT(""" + short_name +")\n"

        for _, function in ext.functions.items():
        #{
            function_providers = seen_by_get_from.setdefault(function.name, get_from_entry("", set()))
            function_providers.obtain += get_from_provider_format.replace("@PROVIDER@", ext.name) \
                                                                 .replace("@EXT_SHORT_NAME@", short_name) \
                                                                 .replace("@FUNCTION_NAME@", function.name)

            function_providers.providers.add("defined(" + ext.name + ")")

            seen_by_get_from[function.name] = function_providers
        #}

        for _, cmd in ext.commands.items():
        #{
            function_providers = seen_by_get_from.setdefault(cmd.name, get_from_entry("", set()))
            function_providers.obtain += get_from_provider_format.replace("@PROVIDER@", ext.name) \
                                                                 .replace("@EXT_SHORT_NAME@", short_name) \
                                                                 .replace("@FUNCTION_NAME@", cmd.name)

            function_providers.providers.add("defined(" + ext.name + ")")

            seen_by_get_from[cmd.name] = function_providers
        #}
    #}

    get_from = ""

    for function, entry in seen_by_get_from.items():
    #{
        get_from_format = """
#if @PRODIVERS@
    template<>
    struct get_from<extension::@LEVEL@_functions, "@FUNCTION_NAME@">
    {
        static constexpr bool valid = true;

        [[nodiscard]] constexpr static PFN_@FUNCTION_NAME@ get(const extension::@LEVEL@_functions& functions) noexcept
        {
@OBTAIN@
            return nullptr;
        }
    };
#endif // @PRODIVERS@
"""

        get_from += get_from_format.replace("@OBTAIN@", entry.obtain) \
                                   .replace("@PRODIVERS@", "or ".join(entry.providers)) \
                                   .replace("@FUNCTION_NAME@", function)
    #}

    return {"struct_name": struct_name, "includes": includes, "members": members, "load_function_args": load_function_args, "get_from": get_from}
#}

#------------------------------------------------------------------------------

def functions_cpp(api_registry: registry.api, args: dict) -> dict:
#{
    """
    args: {"name": str - Name of the extension}
    """

    load_format = """
[[nodiscard]]
@SHORT_NAME@ @SHORT_NAME@::load(@LOAD_ARGS@) noexcept
{
@ASSERTS@
@DEVICE_GET@

    // clang-format off
    return
    {
#if defined(@EXTENSION_NAME@)
@REGULAR_FUNCTIONS@
        .cmd =
        {
@COMMANDS@
        },
#endif // defined(@EXTENSION_NAME@)
    };
    // clang-format on
}
"""

    ext = api_registry.extensions[args["name"]]

    regular_functions_pfn  = ""
    commands_pfn           = ""

    for _, function in ext.functions.items():
    #{
        func_load_args = "instance" if function.level == "instance" else "instance, device, device_get"
        short_pfn_name = to_snake_case(function.name).removeprefix("vk_")

        regular_functions_pfn += "        ." + short_pfn_name + ' = pfn<"' + function.name + '">(' + func_load_args + ")," + "\n"
    #}

    for _, cmd in ext.commands.items():
    #{
        cmd_load_args  = "instance" if cmd.level == "instance" else "instance, device, device_get"
        short_pfn_name = to_snake_case(cmd.name).removeprefix("vk_cmd_")

        commands_pfn += "            ." + short_pfn_name + ' = pfn<"' + cmd.name + '">(' + cmd_load_args + ")," + "\n"
    #}

    device_get = "" \
                 if ext.type == "instance" \
                 else """
    [[maybe_unused]] auto* const device_get = pfn<"vkGetDeviceProcAddr">(instance);
    fubuki_assert(device_get != nullptr, "Could not retrieve vkGetDeviceProcAddr function pointer.");
"""

    load_args = "[[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version" \
                if ext.type == "instance" \
                else """[[maybe_unused]] instance_handle instance, [[maybe_unused]] version_number vk_version, [[maybe_unused]] device_handle device"""

    asserts = """    fubuki_assert(instance != null_handle, "Instance cannot be null_handle.");"""

    if(ext.type == "device"):
    #{
        asserts += """    fubuki_assert(device != null_handle, "Device cannot be null_handle.");"""
    #}

    load = load_format.replace("@LOAD_ARGS@", load_args) \
                      .replace("@ASSERTS@", asserts) \
                      .replace("@DEVICE_GET@", device_get) \
                      .replace("@EXTENSION_NAME@", ext.name) \
                      .replace("@REGULAR_FUNCTIONS@", regular_functions_pfn) \
                      .replace("@COMMANDS@", commands_pfn)

    return {"load": load}
#}

#------------------------------------------------------------------------------

def cpp(api_registry: registry.api, args: dict) -> dict:
#{
    """
    args: {"name": str - Name of the extension}
    """

    free_func_format = """
@SIGNATURE@
{
    #error @SHORT_NAME@ not checked
    return fubuki::invoke<"@FULL_NAME@">(ext, @ARGS@);
}
"""

    ext = api_registry.extensions[args["name"]]

    regular_free_functions = ""
    free_commands          = ""

    for _, function in ext.functions.items():
    #{
        short_pfn_name = to_snake_case(function.name).removeprefix("vk_")
        args = ""

        for arg in function.args:
        #{
            args += (to_snake_case(arg.name) + ", ")
        #}

        args = args.removesuffix(", ")

        regular_free_functions +=  free_func_format.replace("@SIGNATURE@", _signature(func=function, api_registry=api_registry, export=False)) \
                                                   .replace("@FULL_NAME@", function.name) \
                                                   .replace("@SHORT_NAME@", short_pfn_name) \
                                                   .replace("@ARGS@", args)
    #}

    for _, cmd in ext.commands.items():
    #{
        short_pfn_name = to_snake_case(cmd.name).removeprefix("vk_cmd_")
        args = ""

        for arg in cmd.args:
        #{
            args += (to_snake_case(arg.name) + ", ")
        #}

        args = args.removesuffix(", ")

        free_commands += free_func_format.replace("@SIGNATURE@", _signature(func=cmd, api_registry=api_registry, export=False)) \
                                         .replace("@SHORT_NAME@", "cmd." + short_pfn_name) \
                                         .replace("@FULL_NAME@", cmd.name) \
                                         .replace("@ARGS@", args)
    #}

    return {"free_functions": regular_free_functions, "free_commands": free_commands}
#}

#------------------------------------------------------------------------------

def instance_device_cpp(api_registry: registry.api, args: dict) -> dict:
#{
    """
    args:
    {
        "level:" str - Either "instance" or "device"
        "file:" str - Either "cpp" or "hpp"
    }
    """

    level     : str    = args["level"]
    struct_name        = level + "_functions"

    make_loader = ""
    loader_args = ""
    pre_loader  = ""
    loaders     = ""

    load_function_args = "instance_handle instance, version_number version" \
                         if level == "instance" \
                         else "instance_handle instance, version_number version, device_handle device"

    loader_type = "std::function<void(@STRUCT_NAME@& functions, @LOAD_FUNCTION_ARGS@)>" \
                  .replace("@STRUCT_NAME@", struct_name) \
                  .replace("@LOAD_FUNCTION_ARGS@", load_function_args)

    if(level == "instance"):
    #{
        loader_args  = "functions, instance, version"
        make_loader = """
#define FUBUKI_MAKE_LOADER(ext_name)                                                                                     \\
{ext_name::name,                                                                                              \\
 [](instance_ext_functions& f, instance_handle i, version_number vk_ver)                                      \\
 {                                                                                                            \\
     if(f.ext_name == nullptr)                                                                                \\
     {                                                                                                        \\
         f.ext_name = std::make_unique<extension::ext_name::functions>(extension::ext_name::load(i, vk_ver)); \\
     }                                                                                                        \\
 }}

"""
        pre_loader = """
static const std::unordered_set<std::string_view> surface_ext =
{
@SURFACE_EXTENSIONS@
};

if(surface_ext.contains(extension))
{
    // The support for these extensions is embedded in VK_KHR_surface
    extension = "VK_KHR_surface";
}
""".replace("@SURFACE_EXTENSIONS@", registry.format_surface_extensions(indent=8))
    #}
    elif(level == "device"):
    #{
        loader_args  = "functions, instance, version, device"
        make_loader  = """
#define FUBUKI_MAKE_LOADER(ext_name)                                                                                   \\
{ext_name::name,                                                                                            \\
 [](device_ext_functions& f, instance_handle i, version_number v, device_handle d)                          \\
 {                                                                                                          \\
     if(f.ext_name == nullptr)                                                                              \\
     {                                                                                                      \\
         f.ext_name = std::make_unique<extension::ext_name::functions>(extension::ext_name::load(i, v, d)); \\
     }                                                                                                      \\
 }}
"""
    #}

    for _, ext in api_registry.extensions.items():
    #{
        if("vulkan" not in ext.apis or ext.type != level or ext.name in registry.enumerate_surface_extensions()):
        #{
            continue
        #}

        short_name = to_snake_case(ext.name).removeprefix("vk_")

        loaders += "        FUBUKI_MAKE_LOADER(" + short_name + "),\n"
    #}

    return \
    {\
        "struct_name": struct_name, \
        "load_function_args": load_function_args, \
        "loader_type": loader_type, \
        "loaders" : loaders, \
        "loader_args": loader_args, \
        "pre_loader": pre_loader, \
        "make_loader": make_loader, \
    }

#}

#------------------------------------------------------------------------------

def finalise_functions(license: str, api_registry: registry.api, template: str, generated_code: dict, args: dict) -> str:
#{
    """
    args:
    {
        "name": str - Name of the extension
        "file": str - Either "cpp" or "hpp", indicates the type of file to finish
    }
    """

    ext = api_registry.extensions[args["name"]]

    short_name = to_snake_case(ext.name).removeprefix("vk_")

    if(args["file"] == "hpp"):
    #{
        return license + template.replace("@EXTENSION_NAME_UPPER@", short_name.upper()) \
                                 .replace("@EXTENSION_NAME@", ext.name) \
                                 .replace("@MEMBER_PFNS@", generated_code["member_pfn"]) \
                                 .replace("@STATIC_LOAD@", generated_code["static_load"]) \
                                 .replace("@FREE_LOAD@", generated_code["free_load"]) \
                                 .replace("@GET_FROM@", generated_code["get_from"]) \
                                 .replace("@SHORT_NAME@", short_name)
    #}

    if(args["file"] == "cpp"):
    #{
        return license + template.replace("@EXTENSION_NAME@", ext.name) \
                                 .replace("@LOAD@", generated_code["load"]) \
                                 .replace("@SHORT_NAME@", short_name) \
    #}

    return "Internal error. Invalid value for 'file' argument: '" + args["file"] + "'"
#}

#------------------------------------------------------------------------------

def finalise(license: str, api_registry: registry.api, template: str, generated_code: dict, args: dict) -> str:
#{
    """
    args:
    {
        "name": str - Name of the extension
        "file": str - Either "cpp" or "hpp", indicates the type of file to finish
    }
    """

    ext = api_registry.extensions[args["name"]]

    short_name = to_snake_case(ext.name).removeprefix("vk_")

    if(args["file"] == "hpp"):
    #{
        if(len(ext.functions) == 0 and len(ext.commands) == 0):
        #{
            generated_code = {"free_functions": "", "free_commands": ""}
            template       = """#ifndef FUBUKI_EXTENSION_@EXTENSION_NAME_UPPER@_HPP
#define FUBUKI_EXTENSION_@EXTENSION_NAME_UPPER@_HPP

#include "extension/functions/@SHORT_NAME@.hpp" // IWYU pragma: export

#endif // FUBUKI_EXTENSION_@EXTENSION_NAME_UPPER@_HPP
"""
        #}

        return license + template.replace("@EXTENSION_NAME_UPPER@", short_name.upper()) \
                                 .replace("@SHORT_NAME@", short_name) \
                                 .replace("@EXTENSION_NAME@", ext.name) \
                                 .replace("@FREE_FUNCTIONS@", generated_code["free_functions"]) \
                                 .replace("@FREE_COMMANDS@", generated_code["free_commands"])
    #}

    if(args["file"] == "cpp"):
    #{
        return license + template.replace("@EXTENSION_NAME@", ext.name) \
                                 .replace("@SHORT_NAME@", short_name) \
                                 .replace("@FREE_FUNCTIONS@", generated_code["free_functions"]) \
                                 .replace("@FREE_COMMANDS@", generated_code["free_commands"])
    #}

    return "Internal error. Invalid value for 'file' argument: '" + args["file"] + "'"
#}

#------------------------------------------------------------------------------

def finalise_instance_device(license: str, api_registry: registry.api, template: str, generated_code: dict, args: dict) -> str:
#{
    """
    args:
    {
        "level:" str - Either "instance" or "device"
        "file:" str - Either "cpp" or "hpp"
    }
    """

    level : str = args["level"]

    if(args["file"] == "cpp"):
    #{
        return license + template.replace("@LEVEL@", level) \
                                 .replace("@LOAD_FUNCTION_ARGS@", generated_code["load_function_args"]) \
                                 .replace("@PRE_LOADER@", generated_code["pre_loader"]) \
                                 .replace("@LOADER_TYPE@", generated_code["loader_type"]) \
                                 .replace("@MAKE_LOADER@", generated_code["make_loader"]) \
                                 .replace("@LOADERS@", generated_code["loaders"]) \
                                 .replace("@LOADER_ARGUMENTS@", generated_code["loader_args"]) \
                                 .replace("@STRUCT_NAME@", generated_code["struct_name"])
    #}

    if(args["file"] == "hpp"):
    #{
        return license + template.replace("@GET_FROM@", generated_code["get_from"]) \
                                 .replace("@MEMBERS@", generated_code["members"]) \
                                 .replace("@LOAD_FUNCTION_ARGS@", generated_code["load_function_args"]) \
                                 .replace("@STRUCT_NAME@", generated_code["struct_name"]) \
                                 .replace("@LEVEL@", level) \
                                 .replace("@LEVEL_UPPER@", level.upper()) \
                                 .replace("@INCLUDES@",  generated_code["includes"])
    #}

    return ""
#}
