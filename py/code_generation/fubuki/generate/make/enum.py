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

def all_enums(api_registry: registry.api, args: dict) -> str:
#{
    # args unsused

    result = ""

    for _, enum in api_registry.enums.items():
    #{
        if(enum.name.lower() == "api constants"):
        #{
            continue
        #}

        fubuki_name = to_snake_case(enum.name).removeprefix("vk_")

        header = '#include "core/enum/' + fubuki_name + '.hpp"' if enum.name != "VkResult" else '#include "core/result.hpp"'

        result += header + " // IWYU pragma: export\n"
    #}

    return result
#}

#------------------------------------------------------------------------------

def _impl(api_registry: registry.api, enum_name: str, disabled_cases: set) -> str:
#{
    format_base = """
#if defined(@PROVENANCE@)@PROTECT@ @ALIAS@
        @DISABLE@FUBUKI_MAKE_CASE(@VALUE@);
#endif // #if defined (@PROVENANCE@)
"""

    generated_code = ""
    enum = api_registry.enums[enum_name]

    # Not provided for bitmasks, that are not separate types
    if(enum.type != "bitmask"):
    #{
        for _, value in enum.values.items():
        #{
            alias_guard = ""

            if(value.alias_to != ""):
            #{
                alias_format = "&& !(defined(@ALIAS_PROVENANCE@)@ALIAS_PROTECT@)"
                alias = enum.values[value.alias_to]

                alias_guard = alias_format.replace("@ALIAS_PROVENANCE@", alias.provenance) \
                                          .replace("@ALIAS_PROTECT@",  "&& defined(" + alias.protect + ")" if alias.protect != "" else "")
            #}

            # For some reason, the SDK doesn't add VK_ENABLE_BETA_EXTENSION guards for VkObjectType
            protect_guard = "&& defined(" + value.protect + ")" if value.protect != "" and enum.name != "VkObjectType" else ""

            generated_code += format_base.replace("@PROVENANCE@", value.provenance)\
                                         .replace("@VALUE@", value.name) \
                                         .replace("@PROTECT@", protect_guard) \
                                         .replace("@DISABLE@", "//" if value.name in disabled_cases else "") \
                                         .replace("@ALIAS@", alias_guard)
        #}

        vendor = ""

        for v in api_registry.vendors:
        #{
            if enum_name.endswith(v):
            #{
                vendor = "_" + v
                break
            #}
        #}

        max_enum = to_snake_case(enum_name).upper().removesuffix(vendor) + "_MAX_ENUM" + vendor
        generated_code += "\n        FUBUKI_MAKE_CASE(" + max_enum + ");\n"
    #}

    return generated_code
#}

#------------------------------------------------------------------------------

def vkresult(api_registry: registry.api, args: dict) -> str:
#{
    # args unused
    return _impl(api_registry=api_registry, enum_name="VkResult", disabled_cases=set())
#}

#------------------------------------------------------------------------------

def generic(api_registry: registry.api, args: dict) -> str:
#{
    # args : {name: str} : name of the enum

    enum_name = args["name"]

    disabled_cases = set()

    if(enum_name == "VkStructureType"):
    #{
        disabled_cases = \
        { \
            "VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_RESERVATION_INFO_KHR" # For whatever reason, this exists in the registry but not in the header...
        }
    #}

    return _impl(api_registry=api_registry, enum_name=enum_name, disabled_cases=disabled_cases)
#}

#------------------------------------------------------------------------------

def test(api_registry: registry.api, args: dict) -> dict:
#{
    # args unused
    headers         = ""
    to_string_view  = ""
    to_string       = ""
    stream_operator = ""

    to_string_view_format = """
    @DISABLE@#if defined(@ENUM_PROVIDER@)
    @DISABLE@STATIC_EXPECT_TRUE(requires{{fubuki::to_string_view(@ENUM_TYPE@{})};});
    @DISABLE@#endif // #if defined(@ENUM_PROVIDER@)
"""

    to_string_format = """
    @DISABLE@#if defined(@ENUM_PROVIDER@)
    @DISABLE@STATIC_EXPECT_TRUE(requires{{fubuki::to_string(@ENUM_TYPE@{})};});
    @DISABLE@#endif // #if defined(@ENUM_PROVIDER@)
"""

    def make_test(format: str, enum: registry.enum) -> str:
    #{
        return format.replace("@ENUM_TYPE@", enum.name) \
                     .replace("@ENUM_PROVIDER@", enum.provenance) \
                     .replace("@DISABLE@", "// " if enum.provenance == "" or enum.type == "bitmask" else "")
    #}

    for _, enum in api_registry.enums.items():
    #{
        if(enum.name.lower() == "api constants"):
        #{
            continue
        #}

        fubuki_name = to_snake_case(enum.name).removeprefix("vk_")

        to_string_view += make_test(to_string_view_format, enum)
        to_string += make_test(to_string_format, enum)
    #}

    return {"to_string_view" : to_string_view, "to_string" : to_string}
#}

#------------------------------------------------------------------------------

def vkresult_test(api_registry: registry.api, args: dict) -> str:
#{
    generated_code = "MAKE_VK_RESULT(VK_SUCCESS),"

    format_base = """
    #if defined(@PROVENANCE@)@PROTECT@ @ALIAS@
        @DISABLE@MAKE_VK_RESULT(@VALUE@),
    #endif // #if defined (@PROVENANCE@)
"""

    disabled_cases = set()

    for _, value in api_registry.enums["VkResult"].values.items():
    #{
        if( value.name == "VK_SUCCESS"):
        #{
            continue
        #}

        alias_guard = ""

        if(value.alias_to != ""):
        #{
            alias_format = "&& !(defined(@ALIAS_PROVENANCE@)@ALIAS_PROTECT@)"
            alias = enum.values[value.alias_to]

            alias_guard = alias_format.replace("@ALIAS_PROVENANCE@", alias.provenance) \
                                      .replace("@ALIAS_PROTECT@",  "&& defined(" + alias.protect + ")" if alias.protect != "" else "")
        #}

        disable = "//" if(value.name in disabled_cases) else ""

        generated_code += format_base.replace("@PROVENANCE@", value.provenance) \
                                     .replace("@VALUE@", value.name) \
                                     .replace("@DISABLE@", disable) \
                                     .replace("@PROTECT@", "&& defined(" + value.protect + ")" if value.protect != "" else "") \
                                     .replace("@ALIAS@", alias_guard)
    #}

    return generated_code
#}

#------------------------------------------------------------------------------

def finalise(license: str, api_registry: registry.api, template: str, generated_code: str, args: dict) -> str:
#{
    # args : {name: str} : name of the enum

    vk_enum_name : str           = args["name"]
    enum         : registry.enum = api_registry.enums[vk_enum_name]

    if(enum.type == "bitmask"):
    #{
        return license + "\n// Enum '" + vk_enum_name + "' is a bitmask. These are not separated types, so we cannot provide facilities like the others.\n"
    #}

    if(enum.provenance != ""):
    #{
        fubuki_enum_name : str = to_snake_case(vk_enum_name).removeprefix("vk_")

        return license + template.replace("@GENERATED_CODE@", generated_code) \
                                 .replace("@ENUM_PROVIDER@", enum.provenance) \
                                 .replace("@VK_ENUM_NAME@", vk_enum_name) \
                                 .replace("@FUBUKI_ENUM_NAME_UPPER@", fubuki_enum_name.upper()) \
                                 .replace("@FUBUKI_ENUM_NAME@", fubuki_enum_name) \
                                 .replace("@DISABLE@", "// " if enum.type == "bitmask" else "") \
                                 .replace("@DISABLE_COMMENT@", "// Not provided for bitmasks\n" if enum.type == "bitmask" else "")
    #}
    else :
    #{
        return license + "\n// Enum '" + vk_enum_name + "' is present in the registry but not provided by any enabled extension.\n"
    #}
#}

#------------------------------------------------------------------------------

def finalise_test(license: str, api_registry: registry.api, template: str, generated_code: dict, args: dict) -> str:
#{
    return license + template.replace("@TO_STRING_VIEW@", generated_code["to_string_view"]) \
                             .replace("@TO_STRING@", generated_code["to_string"])
#}
