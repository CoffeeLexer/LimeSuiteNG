set(LMS7002M_GUI_SOURCES
    ILMS7002MTab.cpp
    lms7002_pnlXBUF_view.cpp
    lms7002_pnlRFE_view.cpp
    lms7002_pnlCalibrations_view.cpp
    lms7002_pnlTRF_view.cpp
    lms7002_pnlCDS_view.cpp
    lms7002_pnlLimeLightPAD_view.cpp
    lms7002_pnlBIST_view.cpp
    dlgViewIRAM.cpp
    lms7002_gui_utilities.cpp
    lms7002_pnlSX_view.cpp
    lms7002_pnlTBB_view.cpp
    lms7002_dlgVCOfrequencies.cpp
    lms7002_pnlRBB_view.cpp
    lms7002_pnlLDO_view.cpp
    lms7002_pnlAFE_view.cpp
    lms7002_pnlGains_view.cpp
    lms7002_pnlRxTSP_view.cpp
    lms7002_mainPanel.cpp
    lms7002_pnlCLKGEN_view.cpp
    lms7002_pnlMCU_BD_view.cpp
    lms7002_pnlBIAS_view.cpp
    lms7002_dlgGFIR_Coefficients.cpp
    lms7002_pnlTxTSP_view.cpp
    lms7002_pnlR3.cpp)

target_sources(${GUI_EXECUTABLE_NAME} PRIVATE ${LMS7002M_GUI_SOURCES})
