########################################################################
## Support for LimeMM-X8 board
########################################################################

########################################################################
## Add to library
########################################################################
# target_include_directories(${MAIN_LIBRARY_NAME} PRIVATE ${THIS_SOURCE_DIR})
# target_sources(${MAIN_LIBRARY_NAME} PRIVATE ${MM_X8_SOURCES})

set(LIMESDR_MM_X8_NAME "LimeSDR-MM-X8")
add_library(${LIMESDR_MM_X8_NAME}
    LMS64C_ADF_Over_PCIe_MMX8.cpp
    LMS64C_FPGA_Over_PCIe_MMX8.cpp
    LMS64C_LMS7002M_Over_PCIe_MMX8.cpp
    MM_X8.cpp)
target_link_libraries(${LIMESDR_MM_X8_NAME} PRIVATE ${BOARD_LIBRARY_NAME})