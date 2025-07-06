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

#------------------------------------------------------------------------------

def hpp(api_registry: registry.api, args: dict) -> str:
#{
    # args unused

    generated_code = ""

    disabled_structs : set = \
    { \
        "VkPerformanceQueryReservationInfoKHR" # For whatever reason, this structure exists in the registry but not in the header...
    }

    format_base = """
#if defined(@PROVENANCE@)@PROTECT@ @ALIAS@
    @DISABLE@FUBUKI_MAKE_STRUCTURE_TYPE(@STRUCT_TYPE@, @ENUM_VALUE@);
#endif // #if defined (@PROVENANCE@)
"""

    for _, struct in api_registry.structures.items():
    #{
        if(struct.type_enum != ""):
        #{
            protect = api_registry.enums["VkStructureType"].values[struct.type_enum].protect

            alias_guard = ""

            if(struct.alias_to != ""):
            #{
                alias_format = "&& !defined(@ALIAS_PROVENANCE@)"
                alias = api_registry.structures[value.alias_to]

                alias_guard = alias_format.replace("@ALIAS_PROVENANCE@", alias.provenance)
            #}

            generated_code += format_base.replace("@PROVENANCE@", struct.provenance) \
                                         .replace("@ALIAS@", alias_guard) \
                                         .replace("@STRUCT_TYPE@", struct.name) \
                                         .replace("@ENUM_VALUE@", struct.type_enum) \
                                         .replace("@PROTECT@", "&& defined(" + protect + ")" if protect != "" else "") \
                                         .replace("@DISABLE@", "//" if struct.name in disabled_structs else "")
        #}
    #}

    return generated_code
#}

#------------------------------------------------------------------------------

def test(api_registry: registry.api, args: dict) -> dict:
#{
    generated_code = {"vk_struct_concept": "", "make_test": ""}

    disabled_structs : set = \
    { \
        "VkPerformanceQueryReservationInfoKHR" # For whatever reason, this structure exists in the registry but not in the header...
    }

    vk_struct_format = """
#if defined(@PROVIDER@)@PROTECT@ @ALIAS@
    @DISABLE@STATIC_EXPECT_TRUE((fubuki::vk_struct<@STRUCT_TYPE@>));
#endif // if defined(@PROVIDER@)
"""

    make_test_format = """
#if defined(@PROVIDER@)@PROTECT@ @ALIAS@
    @DISABLE@DO_MAKE_TEST(@STRUCT_TYPE@, @STYPE_VALUE@);
#endif // if defined(@PROVIDER@)
"""

    for _, struct in api_registry.structures.items():
    #{
        if(struct.type_enum != ""):
        #{
            disable = "//" if struct.name in disabled_structs else ""

            vk_structure_type = api_registry.enums["VkStructureType"]
            value = vk_structure_type.values[struct.type_enum]

            protect = value.protect

            alias_guard = ""

            if(value.alias_to != ""):
            #{
                alias_format = "&& !defined(@ALIAS_PROVENANCE@)"
                alias = vk_structure_type.values[value.alias_to]

                alias_guard = alias_format.replace("@ALIAS_PROVENANCE@", alias.provenance)
            #}

            generated_code["vk_struct_concept"] += vk_struct_format.replace("@PROVIDER@", struct.provenance) \
                                                                   .replace("@ALIAS@", alias_guard) \
                                                                   .replace("@STRUCT_TYPE@", struct.name) \
                                                                   .replace("@DISABLE@", disable) \
                                                                   .replace("@PROTECT@", "&& defined(" + protect + ")" if protect != "" else "")

            generated_code["make_test"] += make_test_format.replace("@PROVIDER@", struct.provenance) \
                                                           .replace("@ALIAS@", alias_guard) \
                                                           .replace("@STRUCT_TYPE@", struct.name) \
                                                           .replace("@STYPE_VALUE@", struct.type_enum) \
                                                           .replace("@DISABLE@", disable) \
                                                           .replace("@PROTECT@", "&& defined(" + protect + ")" if protect != "" else "")
        #}
    #}

    return generated_code
#}

#------------------------------------------------------------------------------

def finalise_test(license: str, api_registry: registry.api, template: str, generated_code: dict, args: dict) -> str:
#{
    return license + template.replace("@VK_STRUCT_CONCEPT_TEST_BODY@", generated_code["vk_struct_concept"]) \
                             .replace("@MAKE_TEST_BODY@", generated_code["make_test"]) \
#}
