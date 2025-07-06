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

import re


# From https://stackoverflow.com/a/60978847
# Code available under the CC BY-SA license (https://creativecommons.org/licenses/by-sa/4.0/)
def to_camel_case(text: str) -> str:
#{
    s = text.replace("-", " ").replace("_", " ")
    s = s.split()
    if len(text) == 0:
        return text
    return s[0] + ''.join(i.capitalize() for i in s[1:])
#} to_camel_case


# From https://stackoverflow.com/a/12867228
# Code available under the CC BY-SA license (https://creativecommons.org/licenses/by-sa/4.0/)
def to_snake_case(text: str) -> str:
#{
    regex = re.compile('((?<=[a-z0-9])[A-Z]|(?!^)[A-Z](?=[a-z]))')
    return regex.sub(r'_\1', text).lower()
#} // to snake_case


# From https://stackoverflow.com/a/2556252
# Code available under the CC BY-SA license (https://creativecommons.org/licenses/by-sa/4.0/)
def rreplace(s: str, old: str, new: str, occurrence: int = -1) -> str:
#{
    li = s.rsplit(old, occurrence)
    return new.join(li)
#} rreplace
