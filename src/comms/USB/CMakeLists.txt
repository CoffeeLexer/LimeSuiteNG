########################################################################
## Support for USB STREAM connection
########################################################################
if(NOT ENABLE_USB_FX3 AND NOT ENABLE_USB_FTDI)
    return()
endif()

add_library("lime-comms-usb" STATIC 
    LMS64C_FPGA_Over_USB.cpp
    LMS64C_LMS7002M_Over_USB.cpp
    LMS64C_ADF4002_Over_USB.cpp
    USBDMA.cpp
    USBEntry.cpp
    USBGeneric.cpp
    USBTransferContext.cpp)

add_subdirectory(FX3)
add_subdirectory(FT601)
target_include_directories("lime-comms-usb" PRIVATE ../)

if(NOT LIBUSB_1_FOUND)
find_package(libusb-1.0)
endif()

if(NOT LIBUSB_1_FOUND)
    message(WARNING "libusb-1.0 libraries not found. Omitting USB support")
endif()

target_link_libraries("lime-comms-usb" PRIVATE ${LIBUSB_1_LIBRARIES})

if(LIBUSB_1_INCLUDE_DIR)
    target_include_directories(
        "lime-comms-usb" PUBLIC $<BUILD_INTERFACE:${LIBUSB_1_INCLUDE_DIRS}> $<INSTALL_INTERFACE:include>)
endif()

########################################################################
## Add to library
########################################################################
