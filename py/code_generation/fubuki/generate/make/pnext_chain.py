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

import itertools
import os

from fubuki.data import registry
from fubuki.formatting.string import to_snake_case


#------------------------------------------------------------------------------

def disabled_structs() -> set:
#{
    return \
    { \
        "VkPerformanceQueryReservationInfoKHR" # Available only in Vulkan SC
    }
#}

#------------------------------------------------------------------------------

def validator(api_registry: registry.api, args: dict) -> str:
#{
    """
    args:
    {
        "name" : str
    }
    """

    template_specialisation_format = """
#if defined(@EXT_PROVIDER@) @ALIAS@
template<>
struct chain_validator<@BASE@, @EXT@>
{
    static constexpr bool allowed = true;
    static constexpr bool unique  = @UNIQUE@;
};
#endif // #if defined(@EXT_PROVIDER@)
"""

    name : str = args["name"]

    struct = api_registry.structures[name]

    result = ""

    for pnext_member in struct.pnext:
    #{
        ext = api_registry.structures[pnext_member.name]

        if(ext.name in disabled_structs()):
        #{
            continue
        #}

        alias_guard = ""
        if(ext.alias_to != ""):
        #{
            alias_format = "&& !defined(@ALIAS_PROVENANCE@)"
            alias = api_registry.structures[value.alias_to]

            alias_guard = alias_format.replace("@ALIAS_PROVENANCE@", alias.provenance)
        #}

        result += template_specialisation_format.replace("@EXT_PROVIDER@", ext.provenance) \
                                                .replace("@ALIAS@", alias_guard) \
                                                .replace("@BASE@", name) \
                                                .replace("@EXT@", pnext_member.name) \
                                                .replace("@UNIQUE@", "true" if pnext_member.unique else "false")
    #}

    return result
#}

#------------------------------------------------------------------------------

def compatibility(api_registry: registry.api, args: dict) -> str:
#{
    name : str = args["name"]
    struct     = api_registry.structures[name]

    result = ""

    parent_format = """
                                      #if defined(@PROVIDER@)
                                          .add<@NAME@>()
                                      #endif // #if defined(@PROVIDER@)
"""

    comma = ""

    for parent_name in struct.allowed_in:
    #{
        provenance = api_registry.structures[parent_name].provenance

        result += parent_format.replace("@PROVIDER@", provenance) \
                               .replace("@COMMA@", comma) \
                               .replace("@NAME@", parent_name)

        comma = ","
    #}

    return result
#}

#------------------------------------------------------------------------------

def include_all(api_registry: registry.api, args: dict) -> str:
#{
    result = ""

    for _, struct in api_registry.structures.items():
    #{
        if(struct.name in disabled_structs()):
        #{
            continue
        #}

        fubuki_name = to_snake_case(struct.name).removeprefix("vk_").replace("2_d", "2d").replace("3_d", "3d")

        if(len(struct.pnext) > 0):
        #{
            result += "#include <core/detail/chain_validator/" + fubuki_name + ".hpp>" + "\n"
        #}

        if(len(struct.allowed_in) > 0):
        #{
            result += "#include <core/detail/chain_compatibility/" + fubuki_name + ".hpp>" + "\n"
        #}
    #}

    return result.removesuffix("\n")
#}

#------------------------------------------------------------------------------

def unit_test(api_registry: registry.api, args: dict) -> str:
#{
    # args unused

    chain_validator     = ""

    validator_test_format = """
TEST(pnext_chain, @FUBUKI_NAME@)
{
#if defined(@STRUCT_PROVENANCE@) @ALIAS@
    @TEST_CONTENTS@
#endif // @STRUCT_PROVENANCE@
}
"""

    positive_test_case_format = """
    #if @PREPROCESSOR_CONDITION@
        STATIC_EXPECT_TRUE(@TEST_STATEMENT@);
    #endif // @PREPROCESSOR_CONDITION@
"""

    negative_test_case_format = """
    #if @PREPROCESSOR_CONDITION@
        STATIC_EXPECT_FALSE(@TEST_STATEMENT@);
    #endif // @PREPROCESSOR_CONDITION@
"""

    for _, struct in api_registry.structures.items():
    #{
        if(struct.name in disabled_structs()):
        #{
            continue
        #}

        fubuki_name = to_snake_case(struct.name).removeprefix("vk_")

        if(len(struct.pnext) > 0):
        #{
            test_contents = ""

            for element in struct.pnext:
            #{
                if(element.name in disabled_structs()):
                #{
                    continue
                #}

                alias_guard = ""

                if(struct.alias_to != ""):
                    #{
                    alias_format = "&& !defined(@ALIAS_PROVENANCE@)"
                    alias = api_registry.structures[value.alias_to]

                    alias_guard = alias_format.replace("@ALIAS_PROVENANCE@", alias.provenance)
                #}

                element_provider = api_registry.structures[element.name].provenance
                element_provider_preprocessor = "defined(" + element_provider + ")"

                test_contents += positive_test_case_format.replace("@PREPROCESSOR_CONDITION@", element_provider_preprocessor) \
                                                          .replace("@TEST_STATEMENT@", "(can_extend_v<" + struct.name + ", " + element.name + ">)")

                if(element.unique):
                #{
                    test_contents += negative_test_case_format.replace("@PREPROCESSOR_CONDITION@", element_provider_preprocessor) \
                                                              .replace("@TEST_STATEMENT@", "(can_extend_v<" + struct.name + ", " + element.name + ", " + element.name + ">)")
                #}

                test_contents += positive_test_case_format.replace("@PREPROCESSOR_CONDITION@", element_provider_preprocessor) \
                                                          .replace("@TEST_STATEMENT@", "(chain_compatible<" + struct.name + ", " + element.name + ">)")

                # TODO: find a way to test chain compatibility more exhaustively
                # The naive version is too heavy for the compiler
                """
                for other_element in struct.pnext:
                #{
                    if(other_element.name in disabled_structs()):
                    #{
                        continue
                    #}

                    other_element_provider = api_registry.structures[other_element.name].provenance
                    other_element_provider_preprocessor =  "defined(" + other_element_provider + ")"

                    test_contents += positive_test_case_format.replace("@PREPROCESSOR_CONDITION@", element_provider_preprocessor + " && " + other_element_provider_preprocessor) \
                                                              .replace("@TEST_STATEMENT@", "(chain_compatible<" + element.name + ", " + other_element.name + ">)")

                    test_contents += positive_test_case_format.replace("@PREPROCESSOR_CONDITION@", element_provider_preprocessor + " && " + other_element_provider_preprocessor) \
                                                              .replace("@TEST_STATEMENT@", "(chain_compatible<" + element.name + ", " + other_element.name + ">)")
                #}
                """
            #}

            chain_validator += validator_test_format.replace("@STRUCT_NAME@", struct.name) \
                                                    .replace("@FUBUKI_NAME@", fubuki_name) \
                                                    .replace("@STRUCT_PROVENANCE@", struct.provenance) \
                                                    .replace("@ALIAS@", alias_guard) \
                                                    .replace("@TEST_CONTENTS@", test_contents)
        #}
    #}

    return chain_validator
#}

#------------------------------------------------------------------------------

def finalise(license: str, api_registry: registry.api, template: str, generated_code: str, args: dict) -> str:
#{
    name : str = args["name"]

    struct = api_registry.structures[name]

    return license + template.replace("@FUBUKI_STRUCT_NAME_UPPER@", to_snake_case(struct.name).removeprefix("vk_").upper()) \
                             .replace("@STRUCT_PROVIDER@", struct.provenance) \
                             .replace("@VK_STRUCT_NAME@", struct.name) \
                             .replace("@GENERATED_CODE@", generated_code)
#}

#------------------------------------------------------------------------------
