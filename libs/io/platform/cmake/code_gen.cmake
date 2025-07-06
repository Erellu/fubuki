

function(fubuki_generate_wayland_headers WORKING_DIR WAYLAND_DIR)

    if(NOT EXISTS "${WAYLAND_DIR}/generated/xdg/shell-protocol.c")
        execute_process(
            WORKING_DIRECTORY ${WORKING_DIR}
            COMMAND wayland-scanner private-code /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml ${WAYLAND_DIR}/generated/xdg/shell-protocol.c
            OUTPUT_VARIABLE FUBUKI_CODEGEN_STDOUT
            RESULT_VARIABLE FUBUKI_CODE_GEN_SUCCESS
        )

        if(FUBUKI_CODE_GEN_SUCCESS AND NOT FUBUKI_CODE_GEN_SUCCESS EQUAL 0)
            message(FATAL_ERROR "Codegen failed with\n*************************************\n ${FUBUKI_CODEGEN_STDOUT}\n*************************************")
        endif()
    endif()

    if(NOT EXISTS "${WAYLAND_DIR}/generated/xdg/shell-client-protocol.h")
        execute_process(
            WORKING_DIRECTORY ${WORKING_DIR}
            COMMAND wayland-scanner client-header /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml ${WAYLAND_DIR}/generated/xdg/shell-client-protocol.h
            OUTPUT_VARIABLE FUBUKI_CODEGEN_STDOUT
            RESULT_VARIABLE FUBUKI_CODE_GEN_SUCCESS
        )

        if(FUBUKI_CODE_GEN_SUCCESS AND NOT FUBUKI_CODE_GEN_SUCCESS EQUAL 0)
            message(FATAL_ERROR "Codegen failed with\n*************************************\n ${FUBUKI_CODEGEN_STDOUT}\n*************************************")
        endif()
    endif()

    if(NOT EXISTS "${WAYLAND_DIR}/generated/zxdg/decoration-protocol.c")
        execute_process(
            WORKING_DIRECTORY ${WORKING_DIR}
            COMMAND wayland-scanner private-code /usr/share/wayland-protocols/unstable/xdg-decoration/xdg-decoration-unstable-v1.xml ${WAYLAND_DIR}/generated/zxdg/decoration-protocol.c
            OUTPUT_VARIABLE FUBUKI_CODEGEN_STDOUT
            RESULT_VARIABLE FUBUKI_CODE_GEN_SUCCESS
        )

        if(FUBUKI_CODE_GEN_SUCCESS AND NOT FUBUKI_CODE_GEN_SUCCESS EQUAL 0)
            message(FATAL_ERROR "Codegen failed with\n*************************************\n ${FUBUKI_CODEGEN_STDOUT}\n*************************************")
        endif()
    endif()

    if(NOT EXISTS "${WAYLAND_DIR}/generated/zxdg/decoration-client-protocol.h")
        execute_process(
            WORKING_DIRECTORY ${WORKING_DIR}
            COMMAND wayland-scanner client-header /usr/share/wayland-protocols/unstable/xdg-decoration/xdg-decoration-unstable-v1.xml ${WAYLAND_DIR}/generated/zxdg/decoration-client-protocol.h
            OUTPUT_VARIABLE FUBUKI_CODEGEN_STDOUT
            RESULT_VARIABLE FUBUKI_CODE_GEN_SUCCESS
        )

        if(FUBUKI_CODE_GEN_SUCCESS AND NOT FUBUKI_CODE_GEN_SUCCESS EQUAL 0)
            message(FATAL_ERROR "Codegen failed with\n*************************************\n ${FUBUKI_CODEGEN_STDOUT}\n*************************************")
        endif()
    endif()

endfunction()

