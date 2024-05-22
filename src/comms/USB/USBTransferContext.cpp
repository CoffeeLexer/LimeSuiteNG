#include "USBTransferContext.h"

#ifdef __unix__
    #ifdef __GNUC__
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wpedantic"
    #endif
    #include <libusb.h>
    #ifdef __GNUC__
        #pragma GCC diagnostic pop
    #endif
#endif

using namespace lime;

USBTransferContext::USBTransferContext()
    : isTransferUsed(false)
#if __unix__
    , transfer(libusb_alloc_transfer(0))
    , bytesXfered(0)
#else
    , context(NULL)
#endif
{
#ifdef __unix__
    done.store(false);
#endif
}

USBTransferContext::~USBTransferContext()
{
#ifdef __unix__
    if (transfer)
    {
        libusb_free_transfer(transfer);
    }
#endif
}

/**
  @brief Abstract method to override to reset the USB device.
  @returns Opposite of `isTransferUsed`.
 */
bool USBTransferContext::Reset()
{
    return !isTransferUsed;
}
