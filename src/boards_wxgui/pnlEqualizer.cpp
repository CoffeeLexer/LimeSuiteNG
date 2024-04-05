#include "pnlEqualizer.h"
#include "limesuiteng/Logger.h"

#include "DSP/Equalizer.h"
#include "wxRegisterPtr.h"


using namespace lime;

pnlEqualizer::pnlEqualizer(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : ISOCPanel(parent, id, pos, size, style)
{
    wxFlexGridSizer* Master;
    Master = new wxFlexGridSizer(1, 2, 0, 0);
    Master->SetFlexibleDirection(wxBOTH);
    Master->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_ALL);





    wxFlexGridSizer *Control_Grid = new wxFlexGridSizer(3, 1, 0, 0);
    
    wxFlexGridSizer *CFR_Grid = new wxFlexGridSizer(3, 2, 0, 0);

    wxFlexGridSizer *Spin_Grid = new wxFlexGridSizer(4, 1, 0, 0);

    wxFlexGridSizer *FIR_Grid = new wxFlexGridSizer(2, 2, 0, 0);



    wxCheckBox *chkBx_EN_RXTSP = new wxCheckBox(this, wxNewId(), _("EN_RXTSP"));
    CFR_Grid->Add(chkBx_EN_RXTSP, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(
        chkBx_EN_RXTSP->GetId(), 
        wxEVT_CHECKBOX,
        wxCommandEventHandler(pnlEqualizer::OnChange),
        new wxRegisterPtr(&Equalizer::EN_RXTSP),
        this
    );

    //wnd2Register[chkBx_EN_RXTSP] = &Equalizer::EN_RXTSP;





    CFR_Grid->Add(new wxCheckBox(this, wxNewId(), _("Bypass CFR")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    CFR_Grid->Add(new wxCheckBox(this, wxNewId(), _("Bypass HB1")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    CFR_Grid->Add(new wxCheckBox(this, wxNewId(), _("Sleep")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    CFR_Grid->Add(new wxCheckBox(this, wxNewId(), _("Bypass Gain")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    CFR_Grid->Add(new wxCheckBox(this, wxNewId(), _("HB1 delay")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    CFR_Grid->Add(new wxCheckBox(this, wxNewId(), _("HB1 delay")), wxALIGN_LEFT | wxALIGN_TOP, 5);

    Spin_Grid->Add(new wxCheckBox(this, wxNewId(), _("HB1 delay")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    Spin_Grid->Add(new wxCheckBox(this, wxNewId(), _("HB1 delay")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    Spin_Grid->Add(new wxCheckBox(this, wxNewId(), _("HB1 delay")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    Spin_Grid->Add(new wxCheckBox(this, wxNewId(), _("HB1 delay")), wxALIGN_LEFT | wxALIGN_TOP, 5);

    FIR_Grid->Add(new wxCheckBox(this, wxNewId(), _("Sleep")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    FIR_Grid->Add(new wxCheckBox(this, wxNewId(), _("HB1 delay")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    FIR_Grid->Add(new wxCheckBox(this, wxNewId(), _("HB1 delay")), wxALIGN_LEFT | wxALIGN_TOP, 5);
    FIR_Grid->Add(new wxCheckBox(this, wxNewId(), _("HB1 delay")), wxALIGN_LEFT | wxALIGN_TOP, 5);


    Control_Grid->Add(FIR_Grid, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    Control_Grid->Add(Spin_Grid, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    Control_Grid->Add(CFR_Grid, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);

    Master->Add(Control_Grid, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);



    wxSize spinBoxSize(64, -1);
    long spinBoxStyle = wxSP_ARROW_KEYS | wxTE_PROCESS_ENTER;


    wxStaticBoxSizer *CFRcontrolsGroup = new wxStaticBoxSizer(wxVERTICAL, this, _T("LMS#2 CFR controls"));
    wxFlexGridSizer *CFRcontrols = new wxFlexGridSizer(1, 2, 0, 0);
    wxCheckBox *chkTX_HB_BYP = new wxCheckBox(this, wxNewId(), _("Bypass HB1"));
    CFRcontrols->Add(chkTX_HB_BYP, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkTX_HB_BYP->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    wxCheckBox *chkTX_HB_DEL = new wxCheckBox(this, wxNewId(), _("HB1 delay"));
    CFRcontrols->Add(chkTX_HB_DEL, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkTX_HB_DEL->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
     
    CFRcontrols->Add(new wxStaticText(this, wxID_ANY, _("")), 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    CFRcontrols->Add(new wxStaticText(this, wxID_ANY, _("")), 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    
    wxCheckBox *chkBYPASS_CFR = new wxCheckBox(this, wxNewId(), _("Bypass CFR"));
    CFRcontrols->Add(chkBYPASS_CFR, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkBYPASS_CFR->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    wxCheckBox *chkSLEEP_CFR = new wxCheckBox(this, wxNewId(), _("Sleep"));
    CFRcontrols->Add(chkSLEEP_CFR, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkSLEEP_CFR->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    wxCheckBox *chkODD_CFR = new wxCheckBox(this, wxNewId(), _("Odd"));
    CFRcontrols->Add(chkODD_CFR, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkODD_CFR->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    wxCheckBox *chkBYPASSGAIN_CFR = new wxCheckBox(this, wxNewId(), _("Bypass gain"));
    CFRcontrols->Add(chkBYPASSGAIN_CFR, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkBYPASSGAIN_CFR->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);




    // TODO: CHANGE TO NEW LAYOUT GRID2x3

    wxFlexGridSizer *spinGrid = new wxFlexGridSizer(3, 2, 0, 0);

    spinGrid->Add(new wxStaticText(this, wxID_ANY, _("CFR order")), 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    wxSpinCtrl *spinCFR_ORDER = new wxSpinCtrl(this, wxNewId(), wxEmptyString, wxDefaultPosition, spinBoxSize, spinBoxStyle, 2, 40, 39);
    spinGrid->Add(spinCFR_ORDER, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(spinCFR_ORDER->GetId(), wxEVT_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    Connect(spinCFR_ORDER->GetId(), wxEVT_SPINCTRL, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    Connect(spinCFR_ORDER->GetId(), wxEVT_SPIN, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);

    spinGrid->Add(new wxStaticText(this, wxID_ANY, _("Threshold")), 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
    wxSpinCtrlDouble *thresholdSpin = new wxSpinCtrlDouble(this, wxNewId(), _("1.0"), wxDefaultPosition, wxSize(64, -1), 0, 0.0, 1.0, 1.0, 0.01);  
    spinGrid->Add(thresholdSpin, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(thresholdSpin->GetId(), wxEVT_SPINCTRLDOUBLE, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);

    spinGrid->Add(new wxStaticText(this, wxID_ANY, _("Gain")), 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
    wxSpinCtrlDouble * thresholdGain = new wxSpinCtrlDouble(this, wxNewId(), _("1.0"), wxDefaultPosition, wxSize(64, -1), 0, 0.0, 4.0, 1.0, 0.01);
    spinGrid->Add(thresholdGain, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(thresholdGain->GetId(), wxEVT_SPINCTRLDOUBLE, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    
    CFRcontrols->Add(spinGrid, 1, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


    CFRcontrols->Add(new wxStaticText(this, wxID_ANY, _("")), 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    CFRcontrols->Add(new wxStaticText(this, wxID_ANY, _("")), 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    
    CFRcontrols->Add(new wxStaticText(this, wxID_ANY, _("Post-CFR FIR")), 1, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    wxCheckBox *chkSLEEP_FIR = new wxCheckBox(this, wxNewId(), _("Sleep"));
    CFRcontrols->Add(chkSLEEP_FIR, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkSLEEP_FIR->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    wxCheckBox *chkBYPASS_FIR = new wxCheckBox(this, wxNewId(), _("Bypass FIR"));
    CFRcontrols->Add(chkBYPASS_FIR, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkBYPASS_FIR->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    wxCheckBox *chkODD_FIR = new wxCheckBox(this, wxNewId(), _("Odd"));
    CFRcontrols->Add(chkODD_FIR, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkODD_FIR->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    wxCheckBox *chkTX_INVERTQ = new wxCheckBox(this, wxNewId(), _("Invert Q sig."));
    CFRcontrols->Add(chkTX_INVERTQ, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Connect(chkTX_INVERTQ->GetId(), wxEVT_CHECKBOX, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    wxButton *setFIR1 = new wxButton(this, wxNewId(), _T("Coefficients"));
    Connect(setFIR1->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pnlEqualizer::OnChange));
    CFRcontrols->Add(setFIR1, 1, wxEXPAND | wxALIGN_LEFT | wxALIGN_TOP, 50);

    CFRcontrols->Add(setFIR1, 1, wxEXPAND | wxALIGN_LEFT | wxALIGN_TOP, 50);
    CFRcontrolsGroup->Add(CFRcontrols, 1, wxALIGN_LEFT | wxALIGN_TOP, 5);
    Master->Add(CFRcontrolsGroup, 1, wxEXPAND | wxALIGN_LEFT | wxALIGN_TOP | wxALL, 5);

    this->SetSizer(Master);
    this->Layout();
    Master->Fit(this);

//     m_PrimaryFreq->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_SecondaryFreq->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_RDivider->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_PrimarySel->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(pnlEqualizer::OnRadio), NULL, this);
//     m_SecondarySel->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(pnlEqualizer::OnRadio), NULL, this);
//     m_MDivider->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_NMultiplier->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_PSB->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(pnlEqualizer::OnChoice), NULL, this);
//     m_PSA->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(pnlEqualizer::OnChoice), NULL, this);
//     m_CDCM_VER->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(pnlEqualizer::OnChoice), NULL, this);
//     m_Baseaddr->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_WriteAll->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pnlEqualizer::OnButton), NULL, this);
//     m_ReadAll->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pnlEqualizer::OnButton), NULL, this);
//     m_Reset->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pnlEqualizer::OnButton), NULL, this);
//     m_Y0Y1_chk->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
//     m_Y2Y3_chk->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
//     m_Y4_chk->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
//     m_Y5_chk->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
//     m_Y6_chk->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
//     m_Y7_chk->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
//     m_button4->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pnlEqualizer::OnFreqEntry), NULL, this);
//     m_Y2Y3_DIV->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_Y6_DIV->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_Y7_DIV->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_Y0Y1_DIV->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_Y4_DIV->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
//     m_Y5_DIV->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
}

void pnlEqualizer::OnChange(wxCommandEvent &event)
{
    printf("DEBUG INT: %i\n", event.GetInt());
}

pnlEqualizer::~pnlEqualizer()
{
    // Disconnect Events
    // m_PrimaryFreq->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_SecondaryFreq->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_RDivider->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_PrimarySel->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(pnlEqualizer::OnRadio), NULL, this);
    // m_SecondarySel->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(pnlEqualizer::OnRadio), NULL, this);
    // m_MDivider->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_NMultiplier->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_PSB->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(pnlEqualizer::OnChoice), NULL, this);
    // m_PSA->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(pnlEqualizer::OnChoice), NULL, this);
    // m_CDCM_VER->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(pnlEqualizer::OnChoice), NULL, this);
    // m_Baseaddr->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_WriteAll->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pnlEqualizer::OnButton), NULL, this);
    // m_ReadAll->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pnlEqualizer::OnButton), NULL, this);
    // m_Reset->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pnlEqualizer::OnButton), NULL, this);
    // m_Y0Y1_chk->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
    // m_Y2Y3_chk->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
    // m_Y4_chk->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
    // m_Y5_chk->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
    // m_Y6_chk->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
    // m_Y7_chk->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(pnlEqualizer::onFP_chk), NULL, this);
    // m_button4->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(pnlEqualizer::OnFreqEntry), NULL, this);
    // m_Y2Y3_DIV->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_Y6_DIV->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_Y7_DIV->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_Y0Y1_DIV->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_Y4_DIV->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
    // m_Y5_DIV->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(pnlEqualizer::OnChange), NULL, this);
}

void pnlEqualizer::Setup(lime::Equalizer* ptr)
{
    mEqualizer = ptr;


    // assert(cdcm);
    // this->CDCM = cdcm;
    // CDCM->DownloadConfiguration();
    UpdateGUI();

    // m_Baseaddr->SetValue(std::to_string(CDCM->GetSPIBaseAddr()));
}

void pnlEqualizer::Update()
{
    UpdateGUI();
}




void pnlEqualizer::UpdateGUI()
{
    // CDCM_VCO VCO = CDCM->GetVCO();
    // CDCM_Outputs Outputs = CDCM->GetOutputs();
    // //Primary input
    // auto str = wxString::Format(_("%.3f"), VCO.prim_freq / 1e6);
    // m_PrimaryFreq->SetValue(str);

    // //Secondary Input
    // str = wxString::Format(_("%.3f"), VCO.sec_freq / 1e6);
    // m_SecondaryFreq->SetValue(str);

    // //R Divider
    // str = std::to_string(VCO.R_div);
    // m_RDivider->SetValue(str);

    // //MUX Selection
    // if (VCO.input_mux == 2)
    // {
    //     m_PrimarySel->SetValue(false);
    //     m_SecondarySel->SetValue(true);
    // }
    // else if (VCO.input_mux == 1)
    // {
    //     m_PrimarySel->SetValue(true);
    //     m_SecondarySel->SetValue(false);
    // }

    // //M Divider
    // str = std::to_string(VCO.M_div);
    // m_MDivider->SetValue(str);

    // //N Multiplier
    // str = std::to_string(VCO.N_mul_full);
    // m_NMultiplier->SetValue(str);

    // //VCO prescalers
    // m_PSA->SetSelection(VCO.prescaler_A - 4);
    // m_PSB->SetSelection(VCO.prescaler_B - 4);

    // //CDCM Version
    // m_CDCM_VER->SetSelection(CDCM->GetVersion());

    // //VCO Range
    // m_VCORANGE->SetLabel(wxString::Format(_("%.0f - %.0f"), VCO.min_freq / 1e6, VCO.max_freq / 1e6));

    // //VCO Frequency
    // m_VCOFREQ->SetLabel(wxString::Format(_("%.2f MHz"), VCO.output_freq / 1e6));
    // if (VCO.output_freq > VCO.max_freq || VCO.output_freq < VCO.min_freq)
    //     m_VCOFREQ->SetForegroundColour(wxColour("#ff0000"));
    // else
    //     m_VCOFREQ->SetForegroundColour(wxColour("#000000"));

    // //Y0Y1 divider
    // str = std::to_string(static_cast<int>(Outputs.Y0Y1.divider_val));
    // m_Y0Y1_DIV->SetValue(str);
    // //Y0Y1 Frequency
    // str = std::to_string(Outputs.Y0Y1.output_freq / 1e6);
    // m_Y0Y1_FREQ->SetValue(str);

    // str = std::to_string(Outputs.Y0Y1.requested_freq / 1e6);
    // m_Y0Y1_FREQ_req->SetValue(str);

    // //Y2Y3 divider
    // str = std::to_string(static_cast<int>(Outputs.Y2Y3.divider_val));
    // m_Y2Y3_DIV->SetValue(str);
    // //Y2Y3 Frequency
    // str = std::to_string(Outputs.Y2Y3.output_freq / 1e6);
    // m_Y2Y3_FREQ->SetValue(str);

    // str = std::to_string(Outputs.Y2Y3.requested_freq / 1e6);
    // m_Y2Y3_FREQ_req->SetValue(str);

    // //Y4 divider
    // str = std::to_string(Outputs.Y4.divider_val);
    // m_Y4_DIV->SetValue(str);

    // //Y4 Frequency
    // str = std::to_string(Outputs.Y4.output_freq / 1e6);
    // m_Y4_FREQ->SetValue(str);

    // str = std::to_string(Outputs.Y4.requested_freq / 1e6);
    // m_Y4_FREQ_req->SetValue(str);

    // //Y5 divider
    // str = std::to_string(Outputs.Y5.divider_val);
    // m_Y5_DIV->SetValue(str);
    // //Y5 Frequency
    // str = std::to_string(Outputs.Y5.output_freq / 1e6);
    // m_Y5_FREQ->SetValue(str);

    // str = std::to_string(Outputs.Y5.requested_freq / 1e6);
    // m_Y5_FREQ_req->SetValue(str);

    // //Y6 divider
    // str = std::to_string(Outputs.Y6.divider_val);
    // m_Y6_DIV->SetValue(str);
    // //Y6 Frequency
    // str = std::to_string(Outputs.Y6.output_freq / 1e6);
    // m_Y6_FREQ->SetValue(str);

    // str = std::to_string(Outputs.Y6.requested_freq / 1e6);
    // m_Y6_FREQ_req->SetValue(str);

    // //Y7 divider
    // str = std::to_string(Outputs.Y7.divider_val);
    // m_Y7_DIV->SetValue(str);
    // //Y7 Frequency
    // str = std::to_string(Outputs.Y7.output_freq / 1e6);
    // m_Y7_FREQ->SetValue(str);

    // str = std::to_string(Outputs.Y7.requested_freq / 1e6);
    // m_Y7_FREQ_req->SetValue(str);

    // //PLL Lock status
    // if (CDCM->IsLocked())
    // {
    //     m_LockStatus->SetLabel("PLL LOCKED");
    //     m_LockStatus->SetForegroundColour(wxColour("#00ff00"));
    // }
    // else
    // {
    //     m_LockStatus->SetLabel("NOT LOCKED");
    //     m_LockStatus->SetForegroundColour(wxColour("#ff0000"));
    // }

    // m_Y0Y1_FREQ_req->Enable(Outputs.Y0Y1.used);
    // m_Y2Y3_FREQ_req->Enable(Outputs.Y2Y3.used);
    // m_Y4_FREQ_req->Enable(Outputs.Y4.used);
    // m_Y5_FREQ_req->Enable(Outputs.Y5.used);
    // m_Y6_FREQ_req->Enable(Outputs.Y6.used);
    // m_Y7_FREQ_req->Enable(Outputs.Y7.used);

    // m_Y0Y1_chk->SetValue(Outputs.Y0Y1.used);
    // m_Y2Y3_chk->SetValue(Outputs.Y2Y3.used);
    // m_Y4_chk->SetValue(Outputs.Y4.used);
    // m_Y5_chk->SetValue(Outputs.Y5.used);
    // m_Y6_chk->SetValue(Outputs.Y6.used);
    // m_Y7_chk->SetValue(Outputs.Y7.used);
}
