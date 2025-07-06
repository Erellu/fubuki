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

def format(api_registry: registry.api, args: dict) -> str:
#{
    # args unused

    generated_code = ""

    # This function only generated code in a switch, see format.hpp.in

    case_str = """
    #if defined(@FORMAT_PROVIDER@)
        case(@FORMAT_NAME@):
        {
            result.block_size       = @BLOCK_SIZE@;
            result.block_extent     = {@BLOCK_EXTENT_W@, @BLOCK_EXTENT_H@, @BLOCK_EXTENT_D@};
            result.texels_per_block = @TEXELS_PER_BLOCKS@;
            result.components.r     = {@COMPONENT_R@};
            result.components.g     = {@COMPONENT_G@};
            result.components.b     = {@COMPONENT_B@};
            result.components.a     = {@COMPONENT_A@};
            result.chroma           = {@CHROMA@};
            result.packing          = {@PACKING@};
            result.planes           = @PLANES@;
            break;
        }
    #endif // #if defined(@FORMAT_PROVIDER@)
"""

    for format_name, format in api_registry.formats.items():
    #{
        entry = case_str.replace("@FORMAT_NAME@", format.name) \
                        .replace("@FORMAT_PROVIDER@", format.provenance) \
                        .replace("@BLOCK_SIZE@", str(format.block_size)) \
                        .replace("@BLOCK_EXTENT_W@", str(format.block_extent.w)) \
                        .replace("@BLOCK_EXTENT_H@", str(format.block_extent.h)) \
                        .replace("@BLOCK_EXTENT_D@", str(format.block_extent.d)) \
                        .replace("@TEXELS_PER_BLOCKS@", str(format.texels_per_block)) \
                        .replace("@CHROMA@", str(format.chroma) if format.chroma != -1 else "") \
                        .replace("@PACKING@", str(format.packing) if format.packing != -1 else "") \

        for component in {"R", "G", "B", "A"}:
        #{
            marker = "@COMPONENT_" + component + "@"
            if component in format.components:
            #{
                info = format.components[component]

                component_str = ".bits = @COMPONENT_BITS@, .numeric_format = @COMPONENT_NUMERIC@, .plane_index=@PLANE_INDEX@," \
                                .replace("@COMPONENT_BITS@", str(info.bits)) \
                                .replace("@COMPONENT_NUMERIC@", info.numeric.lower()) \
                                .replace("@PLANE_INDEX@", str(info.plane_index) if info.plane_index != -1 else "{}")

                entry = entry.replace(marker, component_str)
            #}
            else:
            #{
                entry = entry.replace(marker, "")
            #}
        #}

        if(len(format.planes) == 0):
        #{
            entry = entry.replace("@PLANES@", "{}")
        #}
        else:
        #{
            planes = """
            {
                {
                    {
                        {@PLANE_0@},
                        {@PLANE_1@},
                        {@PLANE_2@},
                    }
                }
            }"""

            for plane in format.planes:
            #{
                token = "@PLANE_" + str(plane.index) +"@"
                plane_str = "{.width_divisor = @WIDTH_DIVISOR@, .height_divisor = @HEIGHT_DIVISOR@, .compatible = @COMPATIBLE@,}" \
                            .replace("@WIDTH_DIVISOR@", str(plane.width_divisor)) \
                            .replace("@HEIGHT_DIVISOR@", str(plane.height_divisor)) \
                            .replace("@COMPATIBLE@", plane.compatible)

                planes = planes.replace(token, plane_str)
            #}

            # Remove the planes not specified
            planes = planes.replace("@PLANE_0@", "") \
                           .replace("@PLANE_1@", "") \
                           .replace("@PLANE_2@", "")

            entry = entry.replace("@PLANES@", planes)
        #}

        generated_code += entry
    #}

    return generated_code
#}

#------------------------------------------------------------------------------
