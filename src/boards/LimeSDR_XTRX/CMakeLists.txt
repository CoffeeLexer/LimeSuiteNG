########################################################################
## Support for LimeSDR_XTRX board
########################################################################


########################################################################
## Add to library
########################################################################
# target_include_directories(${MAIN_LIBRARY_NAME} PRIVATE ${THIS_SOURCE_DIR})
# target_sources(${MAIN_LIBRARY_NAME} PRIVATE ${LIMESDR_XTRX_SOURCES})

set(LIMESDR_XTRX_NAME "LimeSDR-XTRX")
add_library(${LIMESDR_XTRX_NAME}
    LimeSDR_XTRX.cpp
    FPGA_XTRX.cpp
)
target_link_libraries(${LIMESDR_XTRX_NAME} PRIVATE ${BOARD_LIBRARY_NAME})