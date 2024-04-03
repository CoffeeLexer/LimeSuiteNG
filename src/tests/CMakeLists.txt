set(LIME_TEST_SUITE_NAME limesuiteng-test)

set(LIME_TEST_SUITE_SOURCES
    # parsers/CoefficientFileParserTest.cpp
    # protocols/LMS64CProtocol/CustomParameterReadTest.cpp
    # protocols/LMS64CProtocol/CustomParameterWriteTest.cpp
    # protocols/LMS64CProtocol/DeviceResetTest.cpp
    # protocols/LMS64CProtocol/FirmwareToDescriptorTest.cpp
    # protocols/LMS64CProtocol/FPGA_SPITest.cpp
    # protocols/LMS64CProtocol/GetFirmwareInfoTest.cpp
    # protocols/LMS64CProtocol/GPIODirReadTest.cpp
    # protocols/LMS64CProtocol/GPIODirWriteTest.cpp
    # protocols/LMS64CProtocol/GPIOReadTest.cpp
    # protocols/LMS64CProtocol/GPIOWriteTest.cpp
    # protocols/LMS64CProtocol/LMS7002M_SPITest.cpp
    # protocols/BufferInterleavingTest.cpp
)

if (ENABLE_LIMESDR_X3)
    set(LIME_TEST_SUITE_SOURCES ${LIME_TEST_SUITE_SOURCES}     
        # boards/LimeSDR_X3/SlaveSelectShimTest.cpp
    )
endif()

if (ENABLE_LITE_PCIE)
    set(LIME_TEST_SUITE_SOURCES ${LIME_TEST_SUITE_SOURCES}     
        comms/PCIe/PCIE_CSR_PipeTest.cpp
    )
endif()

if (ENABLE_LIMESDR_USB)
    set(LIME_TEST_SUITE_SOURCES ${LIME_TEST_SUITE_SOURCES}     
        # boards/LimeSDR/LimeSDRTest.cpp
        # boards/LimeSDR/USB_CSR_Pipe_SDRTest.cpp
    )
endif()

if (ENABLE_LIMESDR_MINI)
    set(LIME_TEST_SUITE_SOURCES ${LIME_TEST_SUITE_SOURCES}     
        # boards/LimeSDR_Mini/LimeSDR_MiniTest.cpp
        # boards/LimeSDR_Mini/USB_CSR_Pipe_MiniTest.cpp
    )
endif()