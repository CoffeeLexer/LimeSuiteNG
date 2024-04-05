#pragma once

#include <wx/clntdata.h>
#include "Register.h"

class wxRegisterPtr:public wxClientData
{
public:
    const lime::Register* mPtr;
    wxRegisterPtr(const lime::Register* ptr) : mPtr(ptr){}
};