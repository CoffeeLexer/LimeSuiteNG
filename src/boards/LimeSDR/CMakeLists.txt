########################################################################
## Support for LimeSDR board
########################################################################
set(THIS_SOURCE_DIR boards/LimeSDR)
set(LIMESDR_NAME "lime-boards-limesdr")

########################################################################
## Add to library
########################################################################
add_library(${LIMESDR_NAME}
    LimeSDR.cpp
    USB_CSR_Pipe_SDR.cpp
)

target_link_libraries(${LIMESDR_NAME} PRIVATE "lime-boards" "lime-comms-usb-fx3")



