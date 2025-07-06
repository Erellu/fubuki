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

    pfns = set()

    def format_command(parent_name: str, command: registry.command) -> str:
    #{
        disabled_pfn = set()

        format_base = """
#if defined(@PROVENANCE@)
template<>
struct vk_function<compile_time_hash("@FUNCTION_NAME@"_literal)>
{
    using type                 = PFN_@FUNCTION_NAME@;
    static constexpr auto name = "@FUNCTION_NAME@"_literal;
};
#endif // #if defined (@PROVENANCE@)
"""
        return format_base.replace("@PROVENANCE@", parent_name) \
                          .replace("@FUNCTION_NAME@", function.name)
    #}

    for _, feature in api_registry.features.items():
    #{
        for _, function in feature.functions.items():
        #{
            if (function.name not in pfns):
            #{
                generated_code += format_command(feature.name, function)
                pfns.add(function.name)
            #}
        #}

        for _, function in feature.commands.items():
        #{
            if (function.name not in pfns):
            #{
                generated_code += format_command(feature.name, function)
                pfns.add(function.name)
            #}
        #}
    #}

    for _, extension in api_registry.extensions.items():
    #{
        for _, function in extension.functions.items():
        #{
            if (function.name not in pfns):
            #{
                generated_code += format_command(extension.name, function)
                pfns.add(function.name)
            #}
        #}

        for _, function in extension.commands.items():
        #{
            if (function.name not in pfns):
            #{
                generated_code += format_command(extension.name, function)
                pfns.add(function.name)
            #}
        #}
    #}

    return generated_code
#}

#------------------------------------------------------------------------------
