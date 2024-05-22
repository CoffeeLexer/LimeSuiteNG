set(BOARD_LIBRARY_NAME "lime-boards")

add_library(${BOARD_LIBRARY_NAME}
    DeviceRegistry.cpp
    DeviceHandle.cpp
    LMS7002M_SDRDevice.cpp)

if(ENABLE_LITE_PCIE)
    target_sources(${BOARD_LIBRARY_NAME} PRIVATE DeviceFactoryPCIe.cpp)
    add_subdirectory(./LimeSDR_X3)
    add_subdirectory(./LimeSDR_XTRX)
    add_subdirectory(./MMX8)
    add_subdirectory(./external/XSDR)
endif()

if(ENABLE_USB_FX3)
    target_sources(${BOARD_LIBRARY_NAME} PRIVATE DeviceFactoryFX3.cpp)
    target_link_libraries(${BOARD_LIBRARY_NAME} "lime-comms-usb-fx3")
    add_subdirectory(LimeSDR)
endif()

if(ENABLE_USB_FTDI)
    target_sources(${BOARD_LIBRARY_NAME} PRIVATE DeviceFactoryFTDI.cpp)
    target_link_libraries(${BOARD_LIBRARY_NAME} "lime-comms-usb-ftdi")
    add_subdirectory(LimeSDR_Mini)
endif()



# target_sources(
#     ${MAIN_LIBRARY_NAME}
#     PRIVATE ${CMAKE_CURRENT_LIST_DIR}/DeviceRegistry.cpp
#             ${CMAKE_CURRENT_LIST_DIR}/DeviceHandle.cpp
#             ${CMAKE_CURRENT_LIST_DIR}/LMS7002M_SDRDevice.cpp)

# if(ENABLE_LITE_PCIE)
#     target_sources(${MAIN_LIBRARY_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/DeviceFactoryPCIe.cpp)
#     include(${CMAKE_CURRENT_LIST_DIR}/LimeSDR_X3/CMakeLists.txt)
#     include(${CMAKE_CURRENT_LIST_DIR}/LimeSDR_XTRX/CMakeLists.txt)
#     include(${CMAKE_CURRENT_LIST_DIR}/MMX8/CMakeLists.txt)
#     include(${CMAKE_CURRENT_LIST_DIR}/external/XSDR/CMakeLists.txt)
# endif()

# if(ENABLE_USB_FX3)
#     include(${CMAKE_CURRENT_LIST_DIR}/LimeSDR/CMakeLists.txt)
#     target_sources(${MAIN_LIBRARY_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/DeviceFactoryFX3.cpp)
# endif()

# if(ENABLE_USB_FTDI)
#     include(${CMAKE_CURRENT_LIST_DIR}/LimeSDR_Mini/CMakeLists.txt)
#     target_sources(${MAIN_LIBRARY_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/DeviceFactoryFTDI.cpp)
# endif()
