########################################################################
## Support for ConnectionLitePCIe connection
########################################################################
add_library("comms-pcie"
    LMS64C_FPGA_Over_PCIe.cpp
    LMS64C_LMS7002M_Over_PCIe.cpp
    LitePCIe.cpp
    PCIE_CSR_Pipe.cpp)

########################################################################
## Feature registration
########################################################################
include(FeatureSummary)
include(CMakeDependentOption)
cmake_dependent_option(ENABLE_LITE_PCIE "Enable Lite PCIe" ON "UNIX;ENABLE_LIBRARY; NOT APPLE" OFF)
add_feature_info(LITE_PCIE ENABLE_LITE_PCIE "PCIe support")
if(NOT ENABLE_LITE_PCIE)
    return()
endif()

########################################################################
## Add to library
########################################################################

# build kernel module only on Linux
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_include_directories(${MAIN_LIBRARY_NAME} PRIVATE ${THIS_SOURCE_DIR}/linux-kernel-module)

    cmake_dependent_option(LITEPCIE_KERNEL_MODULE "Build Linux LitePCIe kernel module" ON "UNIX; NOT APPLE" OFF)
    add_feature_info(LITEPCIE_KERNEL_MODULE LITEPCIE_KERNEL_MODULE "Build Linux LitePCIe kernel module")
    if(LITEPCIE_KERNEL_MODULE)
        add_subdirectory(linux-kernel-module)
    endif()
endif()

target_include_directories("comms-pcie" PRIVATE ../)