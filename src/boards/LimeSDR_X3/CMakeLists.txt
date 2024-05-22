########################################################################
## Support for LimeSDR_X3 board
########################################################################


########################################################################
## Add to library
########################################################################


# target_include_directories(${MAIN_LIBRARY_NAME} PRIVATE ${THIS_SOURCE_DIR})
# target_sources(${MAIN_LIBRARY_NAME} PRIVATE ${LIMESDR_X3_SOURCES})

set(LIMESDR_X3_NAME "LimeSDR-X3")
add_library(${LIMESDR_X3_NAME}
    FPGA_X3.cpp
    LimeSDR_X3.cpp
    SlaveSelectShim.cpp
)
target_link_libraries(${LIMESDR_X3_NAME} PRIVATE ${BOARD_LIBRARY_NAME})