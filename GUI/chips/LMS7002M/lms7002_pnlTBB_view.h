#ifndef __lms7002_pnlTBB_view__
#define __lms7002_pnlTBB_view__

#include "ILMS7002MTab.h"

class NumericSlider;

class lms7002_pnlTBB_view : public ILMS7002MTab
{
  public:
    lms7002_pnlTBB_view(wxWindow* parent,
        wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxTAB_TRAVERSAL);
    virtual void Initialize(lime::LMS7002M* pControl);
    virtual void UpdateGUI();

  protected:
    void ParameterChangeHandler(wxCommandEvent& event);
    void ParameterChangeHandler(wxSpinEvent& event);
    virtual void OnbtnTuneFilter(wxCommandEvent& event);
    virtual void OnbtnTuneTxGain(wxCommandEvent& event);

    enum {
        ID_PD_LPFH_TBB = 2048,
        ID_PD_LPFIAMP_TBB,
        ID_PD_LPFLAD_TBB,
        ID_PD_LPFS5_TBB,
        ID_EN_G_TBB,
        ID_EN_DIR_TBB,
        ID_BYPLADDER_TBB,
        ID_LOOPB_TBB,
        ID_TSTIN_TBB,
        ID_CG_IAMP_TBB,
        ID_ICT_IAMP_FRP_TBB,
        ID_ICT_IAMP_GG_FRP_TBB,
        ID_ICT_LPFS5_F_TBB,
        ID_ICT_LPFS5_PT_TBB,
        ID_ICT_LPF_H_PT_TBB,
        ID_ICT_LPFH_F_TBB,
        ID_ICT_LPFLAD_F_TBB,
        ID_ICT_LPFLAD_PT_TBB,
        ID_RCAL_LPFH_TBB,
        ID_RCAL_LPFLAD_TBB,
        ID_RCAL_LPFS5_TBB,
        ID_CCAL_LPFLAD_TBB,
        ID_BTN_TUNE_FILTER
    };

    wxCheckBox* chkPD_LPFH_TBB;
    wxCheckBox* chkPD_LPFIAMP_TBB;
    wxCheckBox* chkPD_LPFLAD_TBB;
    wxCheckBox* chkPD_LPFS5_TBB;
    wxCheckBox* chkEN_G_TBB;
    wxCheckBox* chkEN_DIR_TBB;
    wxCheckBox* chkBYPLADDER_TBB;
    wxCheckBox* chkR5_LPF_BYP_TBB;
    wxStaticText* ID_STATICTEXT1;
    wxComboBox* cmbLOOPB_TBB;
    wxStaticText* ID_STATICTEXT5;
    wxComboBox* cmbTSTIN_TBB;
    wxStaticText* ID_STATICTEXT2;
    NumericSlider* cmbCG_IAMP_TBB;
    wxStaticText* ID_STATICTEXT3;
    NumericSlider* cmbICT_IAMP_FRP_TBB;
    wxStaticText* ID_STATICTEXT4;
    NumericSlider* cmbICT_IAMP_GG_FRP_TBB;
    wxStaticText* ID_STATICTEXT6;
    wxComboBox* cmbICT_LPFS5_F_TBB;
    wxStaticText* ID_STATICTEXT7;
    wxComboBox* cmbICT_LPFS5_PT_TBB;
    wxStaticText* ID_STATICTEXT8;
    wxComboBox* cmbICT_LPF_H_PT_TBB;
    wxStaticText* ID_STATICTEXT9;
    wxComboBox* cmbICT_LPFH_F_TBB;
    wxStaticText* ID_STATICTEXT10;
    wxComboBox* cmbICT_LPFLAD_F_TBB;
    wxStaticText* ID_STATICTEXT11;
    wxComboBox* cmbICT_LPFLAD_PT_TBB;
    wxStaticText* ID_STATICTEXT12;
    NumericSlider* cmbRCAL_LPFH_TBB;
    wxStaticText* ID_STATICTEXT13;
    NumericSlider* cmbRCAL_LPFLAD_TBB;
    wxStaticText* ID_STATICTEXT15;
    NumericSlider* cmbRCAL_LPFS5_TBB;
    wxStaticText* ID_STATICTEXT14;
    NumericSlider* cmbCCAL_LPFLAD_TBB;
    wxStaticText* lblFilterInputName;
    wxTextCtrl* txtFilterFrequency;
    wxButton* btnTuneFilter;
    wxButton* btnTuneTxGain;
};

#endif // __lms7002_pnlTBB_view__
