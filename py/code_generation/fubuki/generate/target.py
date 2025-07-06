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
import subprocess
import types

from dataclasses import dataclass
from termcolor import colored as coloured

from fubuki.data import registry


@dataclass
class path:
#{
    libs: pathlib.Path              ## Path to fubuki/libs.
    tests: pathlib.Path             ## Path to fubuki/tests.
    templates: pathlib.Path         ## Path to the code generation templates.
    clang_format_exe: pathlib.Path  ## Path to the clang-format executable.
    clang_format_file: pathlib.Path ## Path to the clang-format file to use for formatting.
#}


@dataclass
class description:
#{
    output: pathlib.Path          ## The path to the file that will be written.
    template: pathlib.Path        ## The path to the template for this target.
    generator: types.FunctionType ## The function to call to generate this target. Must accept the following call: generator(api_registry=registry.api(), forward_args=dict())
    finalise: types.FunctionType  ## The function to call to replace placeholder in the template. Must accept the following call: finalise(license=str(), api_registry=registry.api(), template=str(), generator(...), forward_args=dict())
    generator_args: dict          ## Named arguments to forward to generator.
    finalise_args: dict           ## Named arguments to forward to finalise.
#}


def prettify(paths: path, target: description):
#{
    if(os.path.isfile(target.output)):
    #{
        cmd = [str(paths.clang_format_exe), \
              "-style=file:" + str(paths.clang_format_file), \
              "-i", str(target.output.resolve().absolute())]

        if(subprocess.call(cmd) != 0):
        #{
            print(coloured("Failed to format " + str(), "red"))
        #}
    #}
    else:
    #{
        print(coloured("Skipping the prettification of '", "cyan") + str(target.output) + coloured("' because the file does not exists.", "cyan"))
    #}
#}


def generate(license: str, api_registry: registry.api, paths: path, target: description):
#{
    source_files_ext: set = {".hpp", ".cpp"}

    if(not os.path.isfile(target.output)):
    #{
        template = ""
        with open(target.template, "r") as template_file:
        #{
            template = template_file.read()
        #}

        result = target.finalise(license=license, \
                                 api_registry=api_registry, \
                                 template=template, \
                                 generated_code=target.generator(api_registry=api_registry, args=target.generator_args), \
                                 args=target.finalise_args)

        with open(target.output, "w+", newline="\n") as file:
        #{
            file.write(result.replace("\uFEFF", "")) # Sometimes appears on Windows, because why not, after all?
        #}

        # Sometimes we generate markdown files, which clang-format obviously won't format properly
        if(target.output.suffix in source_files_ext):
        #{
            prettify(paths, target)
        #}
    #}
    else:
    #{
        print(coloured("Skipping the generation of '", "cyan") + str(target.output) + coloured("' because the file already exists. Delete it to generate it again.", "cyan"))
    #}
#}
