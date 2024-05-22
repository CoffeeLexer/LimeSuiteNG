#ifndef LIME_USBTRANSFERCONTEXT_H
#define LIME_USBTRANSFERCONTEXT_H

#include <atomic>
#include <condition_variable>
#include <mutex>

#ifndef __unix__
    #include <windows.h>
#endif
    
#ifdef __unix__
struct libusb_transfer;
#endif

namespace lime {

/** @brief Base class for a USB transfer context. */
class USBTransferContext
{
  public:
    explicit USBTransferContext();
    virtual ~USBTransferContext();
    virtual bool Reset();

    bool isTransferUsed; ///< A flag to mark if this transfer is currently being used.

#ifdef __unix__
    libusb_transfer* transfer;
    long bytesXfered;
    std::atomic<bool> done;
    std::mutex transferLock;
    std::condition_variable cv;
#else
    PUCHAR context;
#endif
};

} // namespace lime

#endif // LIME_USBTRANSFERCONTEXT_H
