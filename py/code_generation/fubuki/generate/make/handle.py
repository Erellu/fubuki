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

def types(api_registry: registry.api, args: dict) -> str:
#{
    # args unused

    generated_code = ""

    disabled_handles : set = {}

    format_base ="""
#if defined(@PROVENANCE@)
    @DISABLE@FUBUKI_MAKE_HANDLE(@HANDLE_TYPE@, @FUBUKI_NAME@); // @COMMENT@
#endif // #if defined (@PROVENANCE@)
"""

    for _, handle in api_registry.handles.items():
    #{
        fubuki_name = to_snake_case(handle.name).removeprefix("vk_")

        entry = format_base.replace("", "")
        entry = entry.replace("@PROVENANCE@", handle.provenance)
        entry = entry.replace("@HANDLE_TYPE@", handle.name)
        entry = entry.replace("@FUBUKI_NAME@", fubuki_name)
        entry = entry.replace("@COMMENT@", fubuki_name + "_handle")

        if(handle.name in disabled_handles):
        #{
            entry = entry.replace("@DISABLE@", "//")
        #}
        else:
        #{
            entry = entry.replace("@DISABLE@", "")
        #}

        generated_code += entry
    #}

    return generated_code
#}

#------------------------------------------------------------------------------

def traits(api_registry: registry.api, args: dict) -> str:
#{
    generated_code = ""

    format_base = """
#if defined(@PROVIDER@)
@DISABLE_BEGIN@template<>
struct handle_traits<@FUBUKI_HANDLE@_handle>
{
    using handle          = @FUBUKI_HANDLE@_handle;
    using parent          = @PARENT@;
    using underlying_type = typename handle::underlying_type;
    using vk_info         = @CREATE_STRUCT@;
    using pfn_create      = PFN_@CREATE_PFN@;
    using pfn_destroy     = PFN_@DESTROY_PFN@;

    static constexpr auto pfn_create_name  = "@CREATE_PFN@"_literal;
    static constexpr auto pfn_destroy_name = "@DESTROY_PFN@"_literal;
};@DISABLE_END@
#endif // #if defined(@PROVIDER@)
"""

    for _, handle in api_registry.handles.items():
    #{
        disable_begin = "" if (handle.create_pfn != "" and handle.destroy_pfn != "" and handle.create_struct != "") else "/*"
        disable_end   = "" if disable_begin == "" else "*/"

        generated_code += format_base.replace("@FUBUKI_HANDLE@", to_snake_case(handle.name).removeprefix("vk_")) \
                                     .replace("@PARENT@", to_snake_case(handle.parent).removeprefix("vk_") + "_handle" if handle.parent != "" else "void") \
                                     .replace("@CREATE_STRUCT@", handle.create_struct) \
                                     .replace("@CREATE_PFN@", handle.create_pfn) \
                                     .replace("@DESTROY_PFN@", handle.destroy_pfn) \
                                     .replace("@PROVIDER@", handle.provenance) \
                                     .replace("@DISABLE_BEGIN@", disable_begin) \
                                     .replace("@DISABLE_END@", disable_end)
    #}

    return generated_code
#}

#------------------------------------------------------------------------------
