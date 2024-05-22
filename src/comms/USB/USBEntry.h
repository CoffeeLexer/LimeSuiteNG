#ifndef LIME_USBENTRY_H
#define LIME_USBENTRY_H

#include "limesuiteng/DeviceRegistry.h"
#include <cstdint>
#include <set>

#ifdef __unix_
#endif
struct libusb_context;
struct libusb_device;
struct libusb_device_handle;
struct libusb_device_descriptor;

namespace lime {

struct VidPid {
    uint16_t vid;
    uint16_t pid;

    bool operator<(const VidPid& other) const
    {
        if (vid == other.vid)
        {
            return pid < other.pid;
        }

        return vid < other.vid;
    }
};

/** @brief An abstract class for a USB device entry. */
class USBEntry : public DeviceRegistryEntry
{
  public:
    /**
      @brief Constructs a new USBEntry object.
      @param name The name of the device.
      @param deviceIds The device Vendor and Product ID pairs to match to.
     */
    USBEntry(const std::string& name, const std::set<VidPid>& deviceIds);
    virtual ~USBEntry();

    virtual std::vector<DeviceHandle> enumerate(const DeviceHandle& hint);

  protected:
#ifdef __unix__
    static struct libusb_context* ctx;
    static uint ctxRefCount;
#endif
  private:
    std::set<VidPid> mDeviceIds;
#ifdef __unix__
    std::string_view GetUSBDeviceSpeedString(struct libusb_device* device);
    DeviceHandle GetDeviceHandle(struct libusb_device_handle* tempHandle, struct libusb_device* device, const struct libusb_device_descriptor& desc);
#endif
};

} // namespace lime

#endif // LIME_USBENTRY_H
