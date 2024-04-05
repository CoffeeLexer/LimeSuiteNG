#ifndef PNL_EQUALIZER_H
#define PNL_EQUALIZER_H

#include "ISOCPanel.h"
#include "DSP/Equalizer.h"
#include "Register.h"
#include "wxRegisterPtr.h"

#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/choice.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>

#include <map>

class wxStaticText;
class wxFlexGridSizer;
class wxCheckBox;

class pnlEqualizer : public ISOCPanel
{
  lime::Equalizer::Config mEqualizerConfig;
  lime::Equalizer *mEqualizer;

  public:
    pnlEqualizer(wxWindow* parent,
        wxWindowID id,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = 0);
    ~pnlEqualizer();
    void Setup(lime::Equalizer* ptr);
    void OnChange(wxCommandEvent &event);

    virtual void UpdateGUI() override;
    virtual void Update() override;
};

#endif
