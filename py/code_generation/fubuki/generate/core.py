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

import os
import pathlib
import types

import fubuki.generate.make as make

from dataclasses import dataclass

from fubuki.data import registry
from fubuki.formatting.string import to_snake_case
from . import target


#------------------------------------------------------------------------------

def targets(license: str, api_registry: registry.api, paths: target.path) -> list:
#{
    format_hpp = target.description(output=paths.libs / "core/format.hpp",
                                    template=paths.templates / "core/format.hpp.in",
                                    generator=make.format.format,
                                    finalise=make.generic.finalise_simple,
                                    generator_args=dict(),
                                    finalise_args=dict())

    handles_hpp = target.description(output=paths.libs / "core/handle.hpp",
                                     template=paths.templates / "core/handle.hpp.in",
                                     generator=make.handle.types,
                                     finalise=make.generic.finalise_simple,
                                     generator_args=dict(),
                                     finalise_args=dict())

    handle_traits_hpp = target.description(output=paths.libs / "core/detail/handle_traits.hpp",
                                           template=paths.templates / "core/handle_traits.hpp.in",
                                           generator=make.handle.traits,
                                           finalise=make.generic.finalise_simple,
                                           generator_args=dict(),
                                           finalise_args=dict())

    pfn_hpp = target.description(output=paths.libs / "core/detail/pfn.hpp",
                                 template=paths.templates / "core/detail_pfn.hpp.in",
                                 generator=make.pfn.hpp,
                                 finalise=make.generic.finalise_simple,
                                 generator_args=dict(),
                                 finalise_args=dict())

    result_hpp = target.description(output=paths.libs / "core/result.hpp",
                                    template=paths.templates / "core/result.hpp.in",
                                    generator=make.enum.vkresult,
                                    finalise=make.generic.finalise_simple,
                                    generator_args=dict(),
                                    finalise_args=dict())

    structure_type_hpp = target.description(output=paths.libs / "core/structure_type.hpp",
                                            template=paths.templates / "core/structure_type.hpp.in",
                                            generator=make.structure_type.hpp,
                                            finalise=make.generic.finalise_simple,
                                            generator_args=dict(),
                                            finalise_args=dict())

    all_enums_hpp = target.description(output=paths.libs / "core/enums.hpp",
                                       template=paths.templates / "core/all_enums.hpp.in",
                                       generator=make.enum.all_enums,
                                       finalise=make.generic.finalise_simple,
                                       generator_args=dict(),
                                       finalise_args=dict())

    detail_pnext_chain_hpp = target.description(output=paths.libs / "core/detail/pnext_chain.hpp",
                                                template=paths.templates / "core/detail_pnext_chain.hpp.in",
                                                generator=make.pnext_chain.include_all,
                                                finalise=make.generic.finalise_simple,
                                                generator_args=dict(),
                                                finalise_args=dict())

    structure_type_test_cpp = target.description(output=paths.tests / "core/structure_type.cpp",
                                                 template=paths.templates / "core/test/structure_type.cpp.in",
                                                 generator=make.structure_type.test,
                                                 finalise=make.structure_type.finalise_test,
                                                 generator_args=dict(),
                                                 finalise_args=dict())

    enum_test_cpp = target.description(output=paths.tests / "core/enum.cpp",
                                       template=paths.templates / "core/test/enum.cpp.in",
                                       generator=make.enum.test,
                                       finalise=make.enum.finalise_test,
                                       generator_args=dict(),
                                       finalise_args=dict())

    result_test_cpp = target.description(output=paths.tests / "core/result.cpp",
                                         template=paths.templates / "core/test/result.cpp.in",
                                         generator=make.enum.vkresult_test,
                                         finalise=make.generic.finalise_simple,
                                         generator_args=dict(),
                                         finalise_args=dict())

    pnext_chain_test_cpp = target.description(output=paths.tests / "core/pnext_chain.cpp",
                                              template=paths.templates / "core/test/pnext_chain.cpp.in",
                                              generator=make.pnext_chain.unit_test,
                                              finalise=make.generic.finalise_simple,
                                              generator_args=dict(),
                                              finalise_args=dict())

    functions_hpp = []
    functions_cpp = []

    for level in {"instance", "device"}:
    #{
        functions_hpp.append(target.description(output=paths.libs / str("core/functions/" + level + "_core.hpp"),
                                               template=paths.templates / "core/core_functions.hpp.in",
                                               generator=make.function.core_hpp,
                                               finalise=make.function.finalise,
                                               generator_args={"level" : level},
                                               finalise_args={"level" : level, "file": "hpp"}))

        functions_cpp.append(target.description(output=paths.libs / str("core/functions/" + level + "_core.cpp"),
                                               template=paths.templates / "core/core_functions.cpp.in",
                                               generator=make.function.core_cpp,
                                               finalise=make.function.finalise,
                                               generator_args={"level" : level},
                                               finalise_args={"level" : level, "file": "cpp"}))
    #}

    enums_hpp = []

    for _, enum in api_registry.enums.items():
    #{
        # API constants are #define directives, not enums
        # VkResult is provided in a separated file, because we have fubuki::result with it
        if(enum.name.lower() == "api constants" or enum.name == "VkResult"):
        #{
            continue
        #}

        fubuki_name = to_snake_case(enum.name).removeprefix("vk_")

        enums_hpp.append(target.description(output=paths.libs / str("core/enum/" + fubuki_name + ".hpp"),
                                            template=paths.templates / "core/enum.hpp.in",
                                            generator=make.enum.generic,
                                            finalise=make.enum.finalise,
                                            generator_args={"name" : enum.name},
                                            finalise_args={"name" : enum.name}))
    #}


    chain_validators_hpp    = []
    chain_compatibility_hpp = []
    compare_hpp             = []

    for _, struct in api_registry.structures.items():
    #{
        if(struct.name in make.pnext_chain.disabled_structs()):
        #{
            continue
        #}

        fubuki_name = to_snake_case(struct.name).removeprefix("vk_").replace("2_d", "2d").replace("3_d", "3d")

        if(len(struct.pnext) > 0):
        #{
            chain_validators_hpp.append(target.description(output=paths.libs / str("core/detail/chain_validator/" + fubuki_name + ".hpp"),
                                                template=paths.templates / "core/detail_chain_validator.hpp.in",
                                                generator=make.pnext_chain.validator,
                                                finalise=make.pnext_chain.finalise,
                                                generator_args={"name" : struct.name},
                                                finalise_args={"name" : struct.name}))
        #}

        if(len(struct.allowed_in) > 0):
        #{
            chain_compatibility_hpp.append(target.description(output=paths.libs / str("core/detail/chain_compatibility/" + fubuki_name + ".hpp"),
                                           template=paths.templates / "core/detail_chain_compatibility.hpp.in",
                                           generator=make.pnext_chain.compatibility,
                                           finalise=make.pnext_chain.finalise,
                                           generator_args={"name" : struct.name},
                                           finalise_args={"name" : struct.name}))
        #}

        compare_hpp.append(target.description(output=paths.libs / str("core/compare/" + fubuki_name + ".hpp"),
                                         template=paths.templates / "core/compare.hpp.in",
                                         generator=make.compare.hpp,
                                         finalise=make.compare.finalise,
                                         generator_args={"name": struct.name},
                                         finalise_args={"name" : struct.name}))
    #}

    return [format_hpp, \
            handles_hpp, \
            handle_traits_hpp, \
            pfn_hpp, \
            result_hpp, \
            structure_type_hpp, \
            *functions_hpp, \
            *functions_cpp, \
            *enums_hpp, \
            all_enums_hpp, \
            detail_pnext_chain_hpp, \
            *compare_hpp, \
            *chain_validators_hpp, \
            *chain_compatibility_hpp, \
            structure_type_test_cpp, \
            enum_test_cpp, \
            result_test_cpp, \
            pnext_chain_test_cpp]
#}

