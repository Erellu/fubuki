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

def _prepare(struct: registry.structure) -> dict:
#{
    # result : {equal: str, three_way: str, disable_three_way_begin : str, disable_three_way_end : str}

    equal_compare_format = "equal(a.@MEMBER@, b.@MEMBER@) and "

    three_way_format = """
    if(const auto cmp = to_ordering<result_type>(three_way(a.@MEMBER@, b.@MEMBER@)); cmp != result_type::equivalent)
    {
        return cmp;
    }
"""

    generated_code = {"equal": "", "disable_three_way_begin": "", "disable_three_way_end" : "", "three_way": "", "first": ""}

    for _, member in struct.members.items():
    #{
        if (generated_code["first"] == ""):
        #{
            generated_code["first"] = member.name
        #}

        if (member.type.startswith("PFN_")):
        #{
            generated_code["disable_three_way_begin"] = "/* Disabled: this struct has members that are not <=>-comparable"
            generated_code["disable_three_way_end"] = "*/"
        #}

        generated_code["equal"] += equal_compare_format.replace("@MEMBER@", member.name)
        generated_code["three_way"] += three_way_format.replace("@MEMBER@", member.name)
    #}

    generated_code["equal"] = generated_code["equal"].rsplit(" and ", 1)[0]

    return generated_code
#}

def hpp(api_registry: registry.api, args: dict) -> dict:
#{
    # args: {structs: set} : names of the structs to include. Must not include aliased structures.

    def compute_dependencies(name: str, api_registry: registry.api):
    #{
        result = set()

        for _, member in api_registry.structures[name].members.items():
        #{
            if member.type in api_registry.structures:
            #{
                if (api_registry.structures[member.type].category == "union"):
                #{
                    return False, result
                #}

                result.add(member.type)
                comp, nested = compute_dependencies(member.type, api_registry)

                if not comp:
                #{
                    return False, result # Indicates there is an union, stop early
                #}

                result.update(nested)
            #}
        #}

        return True, result
    #}

    entries = []

    struct = api_registry.structures[args["name"]]

    # Unions aren't comparable, so structures containing
    if(struct.category == "union"):
    #{
        return {"comparable" : False}
    #}

    comparable, deps = compute_dependencies(struct.name, api_registry)

    functions = _prepare(struct=struct)

    return {"provenance" : struct.provenance,
            "dependencies": deps,
            "name" : struct.name,
            "equal" : functions["equal"],
            "comparable" : comparable,
            "three_way" : functions["three_way"],
            "disable_three_way_begin" : functions["disable_three_way_begin"],
            "disable_three_way_end" : functions["disable_three_way_end"],
            "first": functions["first"]
            }
#}

def finalise(license: str, api_registry: registry.api, template: str, generated_code: dict, args: dict) -> str:
#{
    """
    args:
    {
        "name" : str
    }

    generated_code:
    {
        "provenance" : str,
        "dependencies": set[str],
        "name" : str,
        "equal" : str,
        "comparable": bool,
        "three_way" : str,
        "disable_three_way_begin" : str,
        "disable_three_way_end" : str,
        "first" : str
    }
    """

    struct = api_registry.structures[args["name"]]

    if(not generated_code["comparable"]):
    #{
        return license + """
    // @NAME@ contains an union or a struct containing an union and is therefor not comparable.
""".replace("@NAME@", struct.name)
    #}

    deps = ""

    for dep in generated_code["dependencies"]:
    #{
        dep_name = to_snake_case(dep).removeprefix("vk_").replace("2_d", "2d").replace("3_d", "3d")

        deps += '#include "core/compare/' + dep_name + '.hpp" // IWYU pragma: keep\n'
    #}

    alias_guard = ""

    if(struct.alias_to != ""):
    #{
        alias_format = "&& !defined(@ALIAS_PROVENANCE@)"
        alias = api_registry.structures[struct.alias_to]

        alias_guard = alias_format.replace("@ALIAS_PROVENANCE@", alias.provenance)
    #}

    return license + template.replace("@PROVENANCE@", struct.provenance) \
                             .replace("@ALIAS@", alias_guard) \
                             .replace("@DEPENDENCIES@", deps) \
                             .replace("@NAME@", struct.name) \
                             .replace("@FUBUKI_NAME_UPPER@", to_snake_case(struct.name).removeprefix("vk_").replace("2_d", "2d").replace("3_d", "3d").upper()) \
                             .replace("@EQUAL_BODY@", generated_code["equal"]) \
                             .replace("@DISABLE_THREE_WAY_BEGIN@", generated_code["disable_three_way_begin"]) \
                             .replace("@FIRST_MEMBER@", generated_code["first"]) \
                             .replace("@THREE_WAY_BODY@", generated_code["three_way"]) \
                             .replace("@DISABLE_THREE_WAY_END@", generated_code["disable_three_way_end"])

#}

#------------------------------------------------------------------------------
