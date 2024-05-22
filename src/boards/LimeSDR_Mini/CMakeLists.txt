########################################################################
## Support for LimeSDR Mini v1 board
########################################################################

########################################################################
## Add to library
########################################################################
# target_include_directories(${MAIN_LIBRARY_NAME} PRIVATE ${THIS_SOURCE_DIR})
# target_sources(${MAIN_LIBRARY_NAME} PRIVATE ${LIMESDR_MINI_SOURCES})

set(LIMESDR_MINI_NAME "LimeSDR-Mini")
add_library(${LIMESDR_MINI_NAME}
    LimeSDR_Mini.cpp
    FPGA_Mini.cpp
    USB_CSR_Pipe_Mini.cpp)

target_link_libraries(${LIMESDR_MINI_NAME} PRIVATE ${BOARD_LIBRARY_NAME})