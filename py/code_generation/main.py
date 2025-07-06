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

import argparse
import os
import pathlib

import fubuki.data
import fubuki.generate as code_gen

from termcolor import colored as coloured
from dataclasses import dataclass


@dataclass
class resources:
#{
    license: str
    api_registry: fubuki.data.registry.api
#}

def load_resources(license_file_path: pathlib.Path, cache_path: pathlib.Path, sdk_path: pathlib.Path) -> resources:
#{
    sdk_api_registry = sdk_path / "share/vulkan/registry/vk.xml"

    formatted_api_registry_path = cache_path / "vk.xml.formatted.cache"

    license = ""
    with open(license_file_path) as license_file:
    #{
        license = license_file.read()
    #}

    if(not os.path.isfile(formatted_api_registry_path)):
    #{
        formatted_registry_xml = ""
        with open(sdk_api_registry, "r", encoding="utf-8") as file:
        #{
            formatted_registry_xml = file.read()
        #}

        # Tweaks to ease the parsing of the <command> tags

        # Sometimes there are several level pointers ... And sometimes const qualified
        for i in range(5): # Hopefully no more levels of indirections could ever be added
        #{
            formatted_registry_xml = formatted_registry_xml.replace("</type>*", "*</type>")
            formatted_registry_xml = formatted_registry_xml.replace("</type> const", "const</type>")
        #}

        # Some qualifers that appears before the type tag
        formatted_registry_xml = formatted_registry_xml.replace("struct <type>", "<type>struct ")
        formatted_registry_xml = formatted_registry_xml.replace("const <type>", "<type>const ")

        # The size of arrays ares specified like [<enum> /<enum>]
        formatted_registry_xml = formatted_registry_xml.replace("[<enum>", "<enum>[")
        formatted_registry_xml = formatted_registry_xml.replace("</enum>]", "]</enum>")

        with open(formatted_api_registry_path, "w+", encoding="utf-8") as formatted_api_registry:
        #{
            formatted_api_registry.write(formatted_registry_xml)
        #}
    #}

    return resources(license=license, api_registry=fubuki.data.serialise.parse_registry_file(formatted_api_registry_path))
#}


def main() -> int:
#{
    parser = argparse.ArgumentParser()
    parser.add_argument("--license", help="Path to the license file, ex. C:/fubuki/LICENSE", required=True)
    parser.add_argument("--libs", help="Path to fubuki/libs", required=True)
    parser.add_argument("--tests", help="Path to fubuki/tests", required=True)
    parser.add_argument("--templates", help="Path to the template files, ex. C:/fubuki/cmake/code_generation/templates", required=True)
    parser.add_argument("--cache", help="Path to the cache files, ex. C:/fubuki/py/code_generation/cache", required=True)
    parser.add_argument("--vulkan-sdk", dest="vulkan_sdk", help="Path to the Vulkan SDK", required=True)
    parser.add_argument("--clang-format-exe", dest="clang_format_exe", help="Clang-format executable", required=True)
    parser.add_argument("--clang-format-file", dest="clang_format_file", help="Clang-format file", required=True)

    script_args = vars(parser.parse_args())

    pathlib.Path(script_args["cache"]).mkdir(parents=True, exist_ok=True)

    rc : resources = load_resources(license_file_path = pathlib.Path(script_args["license"]),\
                                    cache_path        = pathlib.Path(script_args["cache"]), \
                                    sdk_path          = pathlib.Path(script_args["vulkan_sdk"]))

    paths = code_gen.target.path(libs=pathlib.Path(script_args["libs"]).resolve().absolute(),
                                 tests=pathlib.Path(script_args["tests"]).resolve().absolute(),
                                 templates=pathlib.Path(script_args["templates"]).resolve().absolute(),
                                 clang_format_exe=pathlib.Path(script_args["clang_format_exe"]).resolve().absolute(),
                                 clang_format_file=pathlib.Path(script_args["clang_format_file"]).resolve().absolute()
                                 )

    for module in [code_gen.core, code_gen.extension, code_gen.fuyu]:
    #{
        for t in module.targets(license=rc.license, api_registry=rc.api_registry, paths=paths):
        #{
            code_gen.target.generate(license=rc.license, api_registry=rc.api_registry, paths=paths, target=t)
        #}
    #}

    return 0
#}

if __name__ == "__main__":
#{
    try:
    #{
        r = main()
        output_message = "Program exited with code " + str(r)

        if(r == 0):
        #{
            print(output_message)
        #}
        else:
        #{
            print(coloured(output_message, "red"))
        #}
        exit(r)
    #}
    except KeyboardInterrupt:
    #{
        print(coloured("Process cancelled by the user.", "red"))
        exit(200)
    #}
    except NotADirectoryError as ex:
    #{
        print(coloured("Invalid argument: ", "red") + coloured(ex, "yellow") + coloured(" is not a directory.", "red"))
        exit(300)
    #}
    except RuntimeError as ex:
    #{
        print(coloured("A runtime error occurred: ", "red") + coloured(ex, "yellow") + coloured(".", "red"))
        exit(400)
    #}
#}
