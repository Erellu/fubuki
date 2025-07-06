#------------------------------------------------------------------------------
# Sets up the FUBUKI_WARNINGS variable according to the current compiler.
########################################
#
# output: sets FUBUKI_WARNINGS.
macro(fubuki_setup_warning_list)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU") # gcc / mingw (gcc)
        set(FUBUKI_WARNINGS
            -WNSObject-attribute
            -Waddress
            -Waddress-of-packed-member
            -Waggressive-loop-optimizations
            -Waligned-new
            -Wall
            -Walloc-zero
            -Walloca
            -Wanalyzer-double-fclose
            -Wanalyzer-double-free
            -Wanalyzer-exposure-through-output-file
            -Wanalyzer-file-leak
            -Wanalyzer-free-of-non-heap
            -Wanalyzer-malloc-leak
            -Wanalyzer-mismatching-deallocation
            -Wanalyzer-null-argument
            -Wanalyzer-null-dereference
            -Wanalyzer-possible-null-argument
            -Wanalyzer-possible-null-dereference
            -Wanalyzer-shift-count-negative
            -Wanalyzer-shift-count-overflow
            -Wanalyzer-stale-setjmp-buffer
            -Wanalyzer-tainted-array-index
            -Wanalyzer-too-complex
            -Wanalyzer-unsafe-call-within-signal-handler
            -Wanalyzer-use-after-free
            -Wanalyzer-use-of-pointer-in-stale-stack-frame
            -Wanalyzer-write-to-const
            -Wanalyzer-write-to-string-literal
            -Warith-conversion
            -Warray-bounds
            -Wattribute-warning
            -Wattributes
            -Wbool-compare
            -Wbool-operation
            -Wbuiltin-declaration-mismatch
            -Wbuiltin-macro-redefined
            -Wcannot-profile
            -Wcast-align
            -Wcast-align=strict
            -Wcast-function-type
            -Wcast-qual
            -Wchar-subscripts
            -Wclass-conversion
            -Wclass-memaccess
            -Wclobbered
            -Wcomma-subscript
            -Wcomment
            -Wconversion
            -Wconversion-null
            -Wcoverage-mismatch
            -Wcpp
            -Wctad-maybe-unsupported
            -Wctor-dtor-privacy
            -Wdangling-else
            -Wdate-time
            -Wdelete-incomplete
            -Wdelete-non-virtual-dtor
            -Wdeprecated
            -Wdeprecated-copy
            -Wdeprecated-copy-dtor
            -Wdeprecated-declarations
            -Wdeprecated-enum-enum-conversion
            -Wdeprecated-enum-float-conversion
            -Wdisabled-optimization
            -Wdiv-by-zero
            -Wdouble-promotion
            -Wduplicated-branches
            -Wduplicated-cond
            -Wempty-body
            -Wendif-labels
            -Wenum-compare
            -Wenum-conversion
            -Wexceptions
            -Wexpansion-to-defined
            -Wextra
            -Wextra-semi
            -Wfloat-conversion
            -Wfloat-equal
            -Wformat
            -Wformat-contains-nul
            -Wformat-diag
            -Wformat-extra-args
            -Wformat-nonliteral
            -Wformat-security
            -Wformat-signedness
            -Wformat-y2k
            -Wformat-zero-length
            -Wframe-address
            -Wfree-nonheap-object
            -Whsa
            -Wif-not-aligned
            -Wignored-attributes
            -Wignored-qualifiers
            -Winaccessible-base
            -Winherited-variadic-ctor
            -Winit-list-lifetime
            -Winit-self
            -Wint-in-bool-context
            -Wint-to-pointer-cast
            -Winvalid-memory-model
            -Winvalid-offsetof
            -Winvalid-pch
            -Wliteral-suffix
            -Wlogical-not-parentheses
            -Wlogical-op
            -Wlto-type-mismatch
            -Wmain
            -Wmaybe-uninitialized
            -Wmemset-elt-size
            -Wmemset-transposed-args
            -Wmisleading-indentation
            -Wmismatched-dealloc
            -Wmismatched-new-delete
            -Wmismatched-tags
            -Wmissing-attributes
            -Wmissing-field-initializers
            -Wmissing-include-dirs
            -Wmissing-profile
            -Wmultichar
            -Wmultistatement-macros
            -Wnarrowing
            -Wnoexcept-type
            -Wnon-template-friend
            -Wnon-virtual-dtor
            -Wnonnull
            -Wnonnull-compare
            -Wnull-dereference
            -Wodr
            -Wold-style-cast
            -Wopenmp-simd
            -Woverflow
            -Woverlength-strings
            -Woverloaded-virtual
            -Wpacked
            -Wpacked-bitfield-compat
            -Wpacked-not-aligned
            -Wparentheses
            -Wpedantic
            -Wpessimizing-move
            -Wplacement-new=1
            -Wpmf-conversions
            -Wpointer-arith
            -Wpointer-compare
            -Wpragmas
            -Wprio-ctor-dtor
            -Wpsabi
            -Wrange-loop-construct
            -Wredundant-decls
            -Wredundant-move
            -Wredundant-tags
            -Wregister
            -Wreorder
            -Wrestrict
            -Wreturn-local-addr
            -Wreturn-type
            -Wscalar-storage-order
            -Wsequence-point
            -Wshadow
            -Wshadow=compatible-local
            -Wshadow=local
            -Wshift-count-negative
            -Wshift-count-overflow
            -Wshift-negative-value
            -Wsign-compare
            -Wsign-conversion
            -Wsign-promo
            -Wsized-deallocation
            -Wsizeof-array-argument
            -Wsizeof-array-div
            -Wsizeof-pointer-div
            -Wsizeof-pointer-memaccess
            -Wstack-protector
            -Wstrict-null-sentinel
            -Wstring-compare
            -Wstringop-overread
            -Wstringop-truncation
            -Wsubobject-linkage
            -Wsuggest-attribute=cold
            -Wsuggest-attribute=const
            -Wsuggest-attribute=format
            -Wsuggest-attribute=malloc
            -Wsuggest-attribute=noreturn
            -Wsuggest-attribute=pure
            -Wsuggest-final-methods
            -Wsuggest-final-types
            -Wsuggest-override
            -Wswitch
            -Wswitch-bool
            -Wswitch-default
            -Wswitch-enum
            -Wswitch-outside-range
            -Wswitch-unreachable
            -Wsync-nand
            -Wtautological-compare
            -Wterminate
            -Wtrampolines
            -Wtrigraphs
            -Wtsan
            -Wtype-limits
            -Wundef
            -Wuninitialized
            -Wunknown-pragmas
            -Wunreachable-code
            -Wunsafe-loop-optimizations
            -Wunused
            -Wunused-but-set-parameter
            -Wunused-but-set-variable
            -Wunused-function
            -Wunused-label
            -Wunused-local-typedefs
            -Wunused-macros
            -Wunused-result
            -Wunused-value
            -Wunused-variable
            -Wuseless-cast
            -Wvarargs
            -Wvariadic-macros
            -Wvector-operation-performance
            -Wvexing-parse
            -Wvirtual-inheritance
            -Wvirtual-move-assign
            -Wvla
            -Wvla-parameter
            -Wvolatile
            -Wvolatile-register-var
            -Wwrite-strings
            -Wzero-as-null-pointer-constant
            -Wzero-length-bounds
        )
    elseif(MSVC)
        set(FUBUKI_WARNINGS
            /Wall
            /wd4514 # Disabled - see below
            /wd4623 # Disabled - see below
            /wd4625 # Disabled - see below
            /wd4626 # Disabled - see below
            /wd4668 # Disabled - see below
            /wd4710 # Disabled - see below
            /wd4711 # Disabled - see below
            /wd4820 # Disabled - see below
            /wd5026 # Disabled - see below
            /wd5027 # Disabled - see below
            /wd5045 # Disabled - see below
            /wd5246 # Disabled - see below
        )
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang") # clang / mingw (llvm)
        set(FUBUKI_WARNINGS
            -Weverything

            # Compatibility warnings - Forcefully disabled because we use C++23 features
            -Wno-c++98-compat
            -Wno-c++98-compat-pedantic
            -Wno-c++98-c++11-compat-binary-literal

            -Wno-c++11-compat

            -Wno-c++14-compat
            -Wno-pre-c++14-compat

            -Wno-c++17-compat
            -Wno-pre-c++17-compat

            -Wno-c++20-compat
            -Wno-pre-c++20-compat
            -Wno-pre-c++20-compat-pedantic
            -Wno-c++20-extensions

            -Wno-pre-c++23-compat

            # Disabled warnings, see below for a rationale
            -Wno-padded
            -Wno-covered-switch-default
            -Wno-missing-prototypes
            -Wno-exit-time-destructors
            -Wno-weak-vtables

            # Errors
            -Werror=unknown-warning-option
        )
    else() # TODO: other compilers if required
        set(FUBUKI_WARNINGS "")
    endif()
endmacro()

# Set FUBUKI_WARNINGS after the first include()
fubuki_setup_warning_list()

#------------------------------------------------------------------------------
# GCC / MinGW
# The warnings below are disabled.
#
#
# | Warning                         | Reason to discard it                                                                                                                          |
# |---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------|
# | -Wabi                           | Not interested in this for now. Maybe later.                                                                                                  |
# | -Wabsolute-value                | C and Objective-C only                                                                                                                        |
# | -Waggregate-return              | Prevents from returning structs, classes or unions that are aggregates (https://en.cppreference.com/w/cpp/language/aggregate_initialization). |
# | -Wbad-function-cast             | C and Objective-C only                                                                                                                        |
# | -Wc++-compat                    | C and Objective-C only                                                                                                                        |
# | -Wc11-c2x-compat                | C and Objective-C only                                                                                                                        |
# | -Wc90-c99-compat                | C and Objective-C only                                                                                                                        |
# | -Wc99-c11-compat                | C and Objective-C only                                                                                                                        |
# | -Wdeclaration-after-statement   | C and Objective-C only                                                                                                                        |
# | -Wdesignated-init               | C++20 mandates to support this feature.                                                                                                       |
# | -Wdiscarded-array-qualifiers    | C and Objective-C only                                                                                                                        |
# | -Wdiscarded-qualifiers          | C and Objective-C only                                                                                                                        |
# | -Wduplicate-decl-specifier      | C and Objective-C only                                                                                                                        |
# | -Winline                        | It's the compiler that decides if something should be inlined. There is no way to force it.                                                   |
# | -Wimplicit                      | C and Objective-C only                                                                                                                        |
# | -Wimplicit-function-declaration | C and Objective-C only                                                                                                                        |
# | -Wimplicit-int                  | C and Objective-C only                                                                                                                        |
# | -Wincompatible-pointer-types    | C and Objective-C only                                                                                                                        |
# | -Wint-conversion                | C and Objective-C only                                                                                                                        |
# | -Wjump-misses-init              | C and Objective-C only                                                                                                                        |
# | -Wlong-long                     | This is for compatibility with C++98.                                                                                                         |
# | -Wmissing-braces                | Disables initalisations of arrays like std::array<int, 3> a = {1, 2, 3}; (requires additional inner braces)                                   |
# | -Wmissing-declarations          | Warns when a function is defined without a prototype (except templates). It's annoying.                                                       |
# | -Wmissing-parameter-type        | C and Objective-C only                                                                                                                        |
# | -Wmissing-prototypes            | C and Objective-C only                                                                                                                        |
# | -Wnested-externs                | C and Objective-C only                                                                                                                        |
# | -Wnoexcept                      | Too much false positive.                                                                                                                      |
# | -Wold-style-declaration         | C and Objective-C only                                                                                                                        |
# | -Wold-style-definition          | C and Objective-C only                                                                                                                        |
# | -Woverride-init                 | C and Objective-C only                                                                                                                        |
# | -Woverride-init-side-effects    | C and Objective-C only                                                                                                                        |
# | -Wpadded                        | Warns when structs are padded. Not relevant yet.                                                                                              |
# | -Wpointer-sign                  | C and Objective-C only                                                                                                                        |
# | -Wpointer-to-int-cast           | C and Objective-C only                                                                                                                        |
# | -Wstrict-prototypes             | C and Objective-C only                                                                                                                        |
# | -Wsystem-headers                | Well, we don't want std namespace warnings in Fubuki.                                                                                      |
# | -Wtraditional                   | C and Objective-C only                                                                                                                        |
# | -Wunsuffixed-float-constants    | C and Objective-C only                                                                                                                        |
# | -Wtraditional-conversion        | C and Objective-C only                                                                                                                        |
#
# Warnings specific to C++:
#
# | Warning                   | Reason to discard it                                                          |
# |---------------------------|-------------------------------------------------------------------------------|
# | -Wabi-tag                 | We don't care about ABI tags yet.                                             |
# | -Wc++11-compat            | Correct is selected by -Wall.                                                 |
# | -Wc++14-compat            | Correct is selected by -Wall.                                                 |
# | -Wc++17-compat            | Correct is selected by -Wall.                                                 |
# | -Wc++20-compat            | Correct is selected by -Wall.                                                 |
# | -Wcatch-value=<0,3>       | All are enabled by -Wall.                                                     |
# | -Wconditionally-supported | Warn for conditionally-supported (C++11) constructs. We're far in the future. |
# | -Weffc++                  | It's a style guide. Not a real warning.                                       |
# | -Winvalid-imported-macros | Useful, but very heavy.                                                       |
# | -Wmultiple-inheritance    | There are places where multiple inheritance is okay.                          |
# | -Wnamespaces              | Why would we disable namespaces ?                                             |
# | -Wsynth                   | Warns when g++ synthesis does not match cfront's one. We don't care.          |
# | -Wtemplates               | Forbids templates. Seriously ?                                                |
# | -Wvirtual-inheritance     | There are places where virtual inheritance is okay... I guess.                |
#
#------------------------------------------------------------------------------
# Clang
# The warnings below are disabled.
#
#
# | Warning                    | Reason to discard it                                                                             |
# |----------------------------|--------------------------------------------------------------------------------------------------|
# | Wno-padded                 | Warns when structs are padded. Not relevant yet.                                                 |
# | Wno-covered-switch-default | Safety to handle improper static_cast. This also conflicts with gcc's switch-default.            |
# | Wno-missing-prototypes     | It's again OK to not have a prototype, for example for inline functions in anonymous namespaces. |
# | Wno-exit-time-destructors  | Global variables trigger this, including constants.                                              |
# | Wno-weak-vtables           | Usually handled by LTO.                                                                          |
#
#------------------------------------------------------------------------------
# MSVC
#
# | Warning | Reason to discard it                                                                                                    |
# |---------|-------------------------------------------------------------------------------------------------------------------------|
# | /wd4514 | Informative warning about inline functions being removed in some translation units. We do not care about that.          |
# | /wd4623 | Informative warning about implicit default ctor being deleted. This is fine to have an implicitly deleted ctor.         |
# | /wd4625 | Informative warning, this is OK for aggregates and similar constructs.                                                  |
# | /wd4626 | Informative warning, this is OK for aggregates and similar constructs.                                                  |
# | /wd4710 | Same as Winline for GCC. This is purely informative, no way to fix it. Also gets triggered in Standard Library Headers. |
# | /wd4711 | Opposite of 4710, but still informative. And gets triggered in standard library headers.                                |
# | /wd4668 | Gets triggered in Standard Library headers. Warnings of this kind get caught when compiling with GCC any way.           |
# | /wd4820 | Padded struct are what all compilers do any way.                                                                        |
# | /wd5026 | Erronously triggered for aggregates.                                                                                    |
# | /wd5027 | Erronously triggered for aggregates.                                                                                    |
# | /wd5045 | We don't compile with QSpectre and there is no plan for it.                                                             |
# | /wd5246 | Equivalent of -Wmissing-braces which we disable in GCC/clang                                                            |
