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

import pathlib

import fubuki.generate.make as make

from dataclasses import dataclass

from fubuki.data import registry
from fubuki.formatting.string import to_snake_case
from . import target


#------------------------------------------------------------------------------

def targets(license: str, api_registry: registry.api, paths: target.path) -> list:
#{
    readme_md = target.description(output=paths.libs / "extension/README.md",
                                   template=paths.templates / "extension/README.md.in",
                                   generator=make.readme.ext,
                                   finalise=make.readme.finalise_ext,
                                   generator_args={"ext_dir": paths.libs/"extension"},
                                   finalise_args=dict())

    functions_hpp = []
    functions_cpp = []

    for level in {"instance", "device"}:
    #{
        functions_hpp.append(target.description(output=paths.libs / str("extension/functions/" + level + "_ext.hpp"),
                                               template=paths.templates / "extension/instance_device.hpp.in",
                                               generator=make.ext.instance_device_hpp,
                                               finalise=make.ext.finalise_instance_device,
                                               generator_args={"level" : level},
                                               finalise_args={"level" : level, "file": "hpp"}))

        functions_cpp.append(target.description(output=paths.libs / str("extension/functions/" + level + "_ext.cpp"),
                                               template=paths.templates / "extension/instance_device.cpp.in",
                                               generator=make.ext.instance_device_cpp,
                                               finalise=make.ext.finalise_instance_device,
                                               generator_args={"level" : level},
                                               finalise_args={"level" : level, "file": "cpp"}))
    #}

    extensions = []

    for _,extension in api_registry.extensions.items():
    #{
        if("vulkan" not in extension.apis or extension.name in registry.enumerate_surface_extensions()):
        #{
            continue
        #}

        short_name = to_snake_case(extension.name).removeprefix("vk_")

        extensions.append(target.description(output=paths.libs / str("extension/" + short_name + ".hpp"),
                                             template=paths.templates / "extension/extension.hpp.in",
                                             generator=make.ext.hpp,
                                             finalise=make.ext.finalise,
                                             generator_args={"name": extension.name},
                                             finalise_args={"name": extension.name, "file": "hpp"}))

        extensions.append(target.description(output=paths.libs / str("extension/functions/" + short_name + ".hpp"),
                                             template=paths.templates / "extension/functions.hpp.in",
                                             generator=make.ext.functions_hpp,
                                             finalise=make.ext.finalise_functions,
                                             generator_args={"name": extension.name},
                                             finalise_args={"name": extension.name, "file": "hpp"}))


        # Everything is inlined for extensions that don't provide new functions/commands
        if(len(extension.functions) > 0 or len(extension.commands) > 0):
        #{
            extensions.append(target.description(output=paths.libs / str("extension/" + short_name + ".cpp"),
                                                 template=paths.templates / "extension/extension.cpp.in",
                                                 generator=make.ext.cpp,
                                                 finalise=make.ext.finalise,
                                                 generator_args={"name": extension.name},
                                                 finalise_args={"name": extension.name, "file": "cpp"}))

            extensions.append(target.description(output=paths.libs / str("extension/functions/" + short_name + ".cpp"),
                                                 template=paths.templates / "extension/functions.cpp.in",
                                                 generator=make.ext.functions_cpp,
                                                 finalise=make.ext.finalise_functions,
                                                 generator_args={"name": extension.name},
                                                 finalise_args={"name": extension.name, "file": "cpp"}))
        #}
    #}

    return [*extensions, *functions_hpp, *functions_cpp, readme_md]
#}


