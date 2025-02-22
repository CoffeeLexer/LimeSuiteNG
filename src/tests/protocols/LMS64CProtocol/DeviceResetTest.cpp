#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "tests/protocols/SerialPortMock.h"
#include "LMS64CProtocol.h"

using namespace lime;
using namespace lime::testing;
using ::testing::_;
using ::testing::AllOf;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::ReturnArg;
using ::testing::SetArrayArgument;

static constexpr std::size_t PACKET_SIZE = sizeof(LMS64CPacket);

// NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
MATCHER_P(IsCommandCorrect, command, "Checks if the packet has the correct command"sv)
{
    const LMS64CPacket* packet = reinterpret_cast<const LMS64CPacket*>(arg);

    return packet->cmd == command;
}

// NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
MATCHER_P(IsSubdeviceCorrect, subDevice, "Checks if the packet has the correct subdevice"sv)
{
    const LMS64CPacket* packet = reinterpret_cast<const LMS64CPacket*>(arg);

    return packet->subDevice == subDevice;
}

// NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
MATCHER_P(IsPeripheralIDCorrect, periphID, "Checks if the packet has the correct peripheral ID"sv)
{
    const LMS64CPacket* packet = reinterpret_cast<const LMS64CPacket*>(arg);

    return packet->periphID == periphID;
}

// NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
MATCHER_P2(IsPayloadByteCorrect, index, byte, "Checks if the packet has the correct block count"sv)
{
    auto packet = reinterpret_cast<const LMS64CPacket*>(arg);

    return packet->payload[index] == byte;
}

TEST(LMS64CProtocol, DeviceResetTestCorrectCommand)
{
    SerialPortMock mockPort{};
    LMS64CPacket packet{};
    packet.status = LMS64CProtocol::CommandStatus::Completed;

    uint32_t socIndex = 6U;
    uint32_t subdevice = 1U;

    ON_CALL(mockPort, Read(_, PACKET_SIZE, _))
        .WillByDefault(DoAll(
            SetArrayArgument<0>(reinterpret_cast<uint8_t*>(&packet), reinterpret_cast<uint8_t*>(&packet + 1)), ReturnArg<1>()));

    EXPECT_CALL(mockPort,
        Write(AllOf(IsCommandCorrect(LMS64CProtocol::Command::LMS7002_RST),
                  IsSubdeviceCorrect(subdevice),
                  IsPeripheralIDCorrect(socIndex),
                  IsPayloadByteCorrect(0, 2)),
            PACKET_SIZE,
            _))
        .Times(1);
    EXPECT_CALL(mockPort, Read(_, PACKET_SIZE, _)).Times(1);

    OpStatus returnValue = LMS64CProtocol::DeviceReset(mockPort, socIndex, subdevice);

    EXPECT_EQ(returnValue, OpStatus::Success);
}

TEST(LMS64CProtocol, DeviceResetTestNotFullyWritten)
{
    SerialPortMock mockPort{};

    uint32_t socIndex = 6U;
    uint32_t subdevice = 1U;

    ON_CALL(mockPort, Write(_, PACKET_SIZE, _)).WillByDefault(Return(0));

    EXPECT_CALL(mockPort,
        Write(AllOf(IsCommandCorrect(LMS64CProtocol::Command::LMS7002_RST),
                  IsSubdeviceCorrect(subdevice),
                  IsPeripheralIDCorrect(socIndex),
                  IsPayloadByteCorrect(0, 2)),
            PACKET_SIZE,
            _))
        .Times(1);
    EXPECT_CALL(mockPort, Read(_, PACKET_SIZE, _)).Times(0);

    EXPECT_THROW(LMS64CProtocol::DeviceReset(mockPort, socIndex, subdevice);, std::runtime_error);
}

TEST(LMS64CProtocol, DeviceResetTestNotFullyRead)
{
    SerialPortMock mockPort{};

    uint32_t socIndex = 6U;
    uint32_t subdevice = 1U;

    ON_CALL(mockPort, Read(_, PACKET_SIZE, _)).WillByDefault(Return(0));

    EXPECT_CALL(mockPort,
        Write(AllOf(IsCommandCorrect(LMS64CProtocol::Command::LMS7002_RST),
                  IsSubdeviceCorrect(subdevice),
                  IsPeripheralIDCorrect(socIndex),
                  IsPayloadByteCorrect(0, 2)),
            PACKET_SIZE,
            _))
        .Times(1);
    EXPECT_CALL(mockPort, Read(_, PACKET_SIZE, _)).Times(1);

    EXPECT_THROW(LMS64CProtocol::DeviceReset(mockPort, socIndex, subdevice);, std::runtime_error);
}

TEST(LMS64CProtocol, DeviceResetTestWrongStatus)
{
    SerialPortMock mockPort{};
    LMS64CPacket packet{};
    packet.status = LMS64CProtocol::CommandStatus::Busy;

    uint32_t socIndex = 6U;
    uint32_t subdevice = 1U;

    ON_CALL(mockPort, Read(_, PACKET_SIZE, _))
        .WillByDefault(DoAll(
            SetArrayArgument<0>(reinterpret_cast<uint8_t*>(&packet), reinterpret_cast<uint8_t*>(&packet + 1)), ReturnArg<1>()));

    EXPECT_CALL(mockPort,
        Write(AllOf(IsCommandCorrect(LMS64CProtocol::Command::LMS7002_RST),
                  IsSubdeviceCorrect(subdevice),
                  IsPeripheralIDCorrect(socIndex),
                  IsPayloadByteCorrect(0, 2)),
            PACKET_SIZE,
            _))
        .Times(1);
    EXPECT_CALL(mockPort, Read(_, PACKET_SIZE, _)).Times(1);

    EXPECT_THROW(LMS64CProtocol::DeviceReset(mockPort, socIndex, subdevice);, std::runtime_error);
}
