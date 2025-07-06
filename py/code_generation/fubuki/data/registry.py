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

# TODO: something matching the "depends" attribute in XML

def enumerate_surface_extensions() -> set:
#{
    return \
    {\
        "VK_KHR_android_surface", \
        "VK_KHR_wayland_surface", \
        "VK_KHR_win32_surface", \
        "VK_KHR_xcb_surface", \
        "VK_KHR_xlib_surface", \
        "VK_EXT_directfb_surface", \
        "VK_EXT_headless_surface", \
        "VK_EXT_metal_surface", \
        "VK_FUCHSIA_imagepipe_surface", \
        "VK_GGP_stream_descriptor_surface", \
        "VK_MVK_ios_surface", \
        "VK_MVK_macos_surface", \
        "VK_NN_vi_surface", \
        "VK_QNX_screen_surface", \
    }
#}

def format_surface_extensions(indent: int = 0) -> str:
#{
    result = ""

    for ext in enumerate_surface_extensions():
    #{
        result += " " * indent + '"' + ext + '"' + ",\n"
    #}

    return result
#}

@dataclass
class version:
#{
    major: int
    minor: int
    patch: int = 0
#}

@dataclass
class alias:
#{
    old: str ## The old name of the feature/command/etc.
    new: str ## The new name of the feature/command/etc.

    def __hash__(self):
        return hash(self.old)
#}

@dataclass
class enum:
#{
    @dataclass
    class value:
    #{
        name: str       ## The value token.
        provenance: str ## The extension or the Vulkan version providing this.
        protect: str    ## The preprocessor guard enabling this value.
        alias_to: str   ## Indicates if this value is an alias to another.
        apis: set       ## The APIs providing this. Elements are "vulkan" or "vulkansc".

        def __hash__(self):
            return hash(self.name)
    #}

    name: str       ## The name of the enum.
    values: dict    ## Format {name: str, info: registry.enum.value}.
    type: str       ## Indicates if the enum is a bitmask or a real type.
    provenance: str ## The extension or the Vulkan version providing this.
    apis: set       ## The APIs providing this. Elements are "vulkan" or "vulkansc".

    def __hash__(self):
        return hash(self.name)
#}

@dataclass
class pnext_element:
#{
    name: str
    unique: bool

    def __hash__(self):
        return hash(self.name)
#}

@dataclass
class structure:
#{
    @dataclass
    class member:
    #{
        name: str ## Name of this member
        type: str ## Type of this member
    #}

    name: str       ## The name of the structure.
    category: str   ## Indicates if this type is a 'struct' or an 'union'.
    type_enum: str  ## The value of sType for this structure.
    pnext: set      ## Format {registry.pnext_element}.
    allowed_in: set ## Format {name: str}. Indicates in which structures' pnext chain this structure can appear.
    members: dict   ## The members of this struct, format {member_name: str, info: structure.member}
    provenance: str ## The extension or the Vulkan version providing this.
    alias_to: str   ## Indicates if this value is an alias to another.
    apis: set       ## The APIs providing this. Elements are "vulkan" or "vulkansc".

    def __hash__(self):
        return hash(self.name)
#}

@dataclass
class handle:
#{
    name: str          ## The name of the handle.
    parent: str        ## The parent of the handle.
    type_enum: str     ## The value in VkObjectType corresponding to this handle.
    create_struct: str ## The name of the struct to provide to create an instance of this handle.
    create_pfn: str    ## The name of the function to create an instance of this handle.
    destroy_pfn: str   ## The name of the function to destory an instance of this handle.
    provenance: str    ## The extension or the Vulkan version providing this.
    apis: set          ## The APIs providing this. Elements are "vulkan" or "vulkansc".

    def __hash__(self):
        return hash(self.name)
#}

@dataclass
class command:
#
    @dataclass
    class argument:
    #{
        type: str ## The type of the argument.
        name: str ## The name of the argument.
    #}

    name: str   ## Name of the PFN.
    result: str ## The return type of this functions.
    args: list  ## Arguments this function takes, as a list of registry.command.argument.
    level: str  ## Either "device" or "instance". Indicates if the command is device- or instance-level.
    apis: set   ## The APIs providing this. Elements are "vulkan" or "vulkansc".

    def __hash__(self):
        return hash(self.name)
#}

@dataclass
class feature:
#{
    name: str       ## The name of the feature.
    functions: dict ## Format {name:str, info: registry.command}. Name are only functions without the vkCmd prefix.
    commands: dict  ## Format {name:str, info: registry.command}. Name are only functions with the vkCmd prefix.
    number: version ## The version corresponding to this feature.
    apis: set       ## The APIs providing this. Elements are "vulkan" or "vulkansc".

    def __hash__(self):
        return hash(self.name)
#}

@dataclass
class extension:
#{
    name: str        ## The name of the extension.
    type: str        ## The type of the extension, either "instance" or "device".
    functions: dict  ## Format {name:str, info: registry.command}. Name are only functions without the vkCmd prefix.
    commands: dict   ## Format {name:str, info: registry.command}. Name are only functions with the vkCmd prefix.
    apis: set        ## The APIs providing this. Elements are "vulkan" or "vulkansc".
    promoted_to: set ## The other extension or features this extension has been promoted to.

    def __hash__(self):
        return hash(self.name)
#}

@dataclass
class format:
#{
    @dataclass
    class block:
    #{
        w: int
        h: int
        d: int
    #}

    @dataclass
    class component:
    #{
        name: str        ## The name of this component.
        bits: int        ## The numer of bits for this component.
        numeric: str     ## One of {UNORM, SNORM, USCALED, SSCALED, SINT, UINT, SRGB}
        plane_index: int ## Index of this plane for this component, or -1.
    #}

    @dataclass
    class plane:
    #{
        index: int          ## The index of this plane.
        width_divisor: int  ## The width divisor of this plane.
        height_divisor: int ## The height divisor of this plane.
        compatible: str     ## A format with which this plane is compatible.
    #}

    name: str              ## The name of this format.
    block_size: int        ## The size of a texel block in bytes.
    block_extent: block    ## The size of a block in texels.
    texels_per_block: int  ## The number of texels per blocks.
    components: dict       ## Format {name: str, info: registry.format.component}.
    chroma: int            ## Chroma for planar formats, or -1 for others.
    packing: int           ## Packing for packed formats, or -1 for others.
    planes: list           ## A list of registry.format.planes for planar components, or empty for others.
    provenance: str        ## The extension or the Vulkan version providing this.
    apis: set              ## The APIs providing this. Elements are "vulkan" or "vulkansc".
#}

@dataclass
class api:
#{
    enums: dict             ## Format {name: str, info: registry.enum}.
    handles: dict           ## Format {name: str, info: registry.handle}
    formats : dict          ## Format {name: str, info: registry.format}
    structures: dict        ## Format {name: str, info: registry.structure}.
    features: dict          ## Format {name: str, info: registry.feature}
    extensions: dict        ## Format {name: str, info: registry.extension}.
    vendors: set            ## Format {name: str} .
#}
