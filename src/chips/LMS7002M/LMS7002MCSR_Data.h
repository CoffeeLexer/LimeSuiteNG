#pragma once
#include <stdint.h>
#include <vector>
#include "limesuiteng/config.h"
#include "limesuiteng/Register.h"
#include "limesuiteng/LMS7002MCSR.h"

namespace lime {
namespace LMS7002MCSR_Data {
struct CSRegister : public lime::Register {
    constexpr CSRegister()
        : CSRegister(0, 0, 0, 0, 0, 0){};
    constexpr CSRegister(uint16_t address, uint8_t msb, uint8_t lsb, uint16_t defaultValue, const char* name, const char* tooltip)
        : lime::Register(address, msb, lsb)
        , defaultValue(defaultValue)
        , name(name)
        , tooltip(tooltip){};

    uint16_t defaultValue; ///< The default value of the parameter.
    const char* name; ///< The name of the parameter.
    const char* tooltip; ///< The tooltip of the parameter.
};

extern CSRegister LRST_TX_B;
extern CSRegister MRST_TX_B;
extern CSRegister LRST_TX_A;
extern CSRegister MRST_TX_A;
extern CSRegister LRST_RX_B;
extern CSRegister MRST_RX_B;
extern CSRegister LRST_RX_A;
extern CSRegister MRST_RX_A;
extern CSRegister SRST_RXFIFO;
extern CSRegister SRST_TXFIFO;
extern CSRegister RXEN_B;
extern CSRegister RXEN_A;
extern CSRegister TXEN_B;
extern CSRegister TXEN_A;
extern CSRegister MAC;
extern CSRegister TX_CLK_PE;
extern CSRegister RX_CLK_PE;
extern CSRegister SDA_PE;
extern CSRegister SDA_DS;
extern CSRegister SCL_PE;
extern CSRegister SCL_DS;
extern CSRegister SDIO_DS;
extern CSRegister SDIO_PE;
extern CSRegister SDO_PE;
extern CSRegister SCLK_PE;
extern CSRegister SEN_PE;
extern CSRegister SPIMODE;
extern CSRegister DIQ2_DS;
extern CSRegister DIQ2_PE;
extern CSRegister IQ_SEL_EN_2_PE;
extern CSRegister TXNRX2_PE;
extern CSRegister FCLK2_PE;
extern CSRegister MCLK2_PE;
extern CSRegister DIQ1_DS;
extern CSRegister DIQ1_PE;
extern CSRegister IQ_SEL_EN_1_PE;
extern CSRegister TXNRX1_PE;
extern CSRegister FCLK1_PE;
extern CSRegister MCLK1_PE;
extern CSRegister DIQDIRCTR2;
extern CSRegister DIQDIR2;
extern CSRegister DIQDIRCTR1;
extern CSRegister DIQDIR1;
extern CSRegister ENABLEDIRCTR2;
extern CSRegister ENABLEDIR2;
extern CSRegister ENABLEDIRCTR1;
extern CSRegister ENABLEDIR1;
extern CSRegister MOD_EN;
extern CSRegister LML2_FIDM;
extern CSRegister LML2_TXNRXIQ;
extern CSRegister LML2_MODE;
extern CSRegister LML1_FIDM;
extern CSRegister LML1_TXNRXIQ;
extern CSRegister LML1_MODE;
extern CSRegister LML1_S3S;
extern CSRegister LML1_S2S;
extern CSRegister LML1_S1S;
extern CSRegister LML1_S0S;
extern CSRegister LML1_BQP;
extern CSRegister LML1_BIP;
extern CSRegister LML1_AQP;
extern CSRegister LML1_AIP;
extern CSRegister LML1_BB2RF_PST;
extern CSRegister LML1_BB2RF_PRE;
extern CSRegister LML1_RF2BB_PST;
extern CSRegister LML1_RF2BB_PRE;
extern CSRegister LML2_S3S;
extern CSRegister LML2_S2S;
extern CSRegister LML2_S1S;
extern CSRegister LML2_S0S;
extern CSRegister LML2_BQP;
extern CSRegister LML2_BIP;
extern CSRegister LML2_AQP;
extern CSRegister LML2_AIP;
extern CSRegister LML2_BB2RF_PST;
extern CSRegister LML2_BB2RF_PRE;
extern CSRegister LML2_RF2BB_PST;
extern CSRegister LML2_RF2BB_PRE;
extern CSRegister FCLK2_DLY;
extern CSRegister FCLK1_DLY;
extern CSRegister RX_MUX;
extern CSRegister TX_MUX;
extern CSRegister TXRDCLK_MUX;
extern CSRegister TXWRCLK_MUX;
extern CSRegister RXRDCLK_MUX;
extern CSRegister RXWRCLK_MUX;
extern CSRegister FCLK2_INV;
extern CSRegister FCLK1_INV;
extern CSRegister MCLK2DLY;
extern CSRegister MCLK1DLY;
extern CSRegister MCLK2SRC;
extern CSRegister MCLK1SRC;
extern CSRegister TXDIVEN;
extern CSRegister RXDIVEN;
extern CSRegister TXTSPCLKA_DIV;
extern CSRegister RXTSPCLKA_DIV;
extern CSRegister MIMO_SISO;
extern CSRegister VER;
extern CSRegister REV;
extern CSRegister MASK;
extern CSRegister EN_DIR_LDO;
extern CSRegister EN_DIR_CGEN;
extern CSRegister EN_DIR_XBUF;
extern CSRegister EN_DIR_AFE;
extern CSRegister ISEL_DAC_AFE;
extern CSRegister MODE_INTERLEAVE_AFE;
extern CSRegister MUX_AFE_1;
extern CSRegister MUX_AFE_2;
extern CSRegister PD_AFE;
extern CSRegister PD_RX_AFE1;
extern CSRegister PD_RX_AFE2;
extern CSRegister PD_TX_AFE1;
extern CSRegister PD_TX_AFE2;
extern CSRegister EN_G_AFE;
extern CSRegister MUX_BIAS_OUT;
extern CSRegister RP_CALIB_BIAS;
extern CSRegister PD_FRP_BIAS;
extern CSRegister PD_F_BIAS;
extern CSRegister PD_PTRP_BIAS;
extern CSRegister PD_PT_BIAS;
extern CSRegister PD_BIAS_MASTER;
extern CSRegister SLFB_XBUF_RX;
extern CSRegister SLFB_XBUF_TX;
extern CSRegister BYP_XBUF_RX;
extern CSRegister BYP_XBUF_TX;
extern CSRegister EN_OUT2_XBUF_TX;
extern CSRegister EN_TBUFIN_XBUF_RX;
extern CSRegister PD_XBUF_RX;
extern CSRegister PD_XBUF_TX;
extern CSRegister EN_G_XBUF;
extern CSRegister SPDUP_VCO_CGEN;
extern CSRegister RESET_N_CGEN;
extern CSRegister EN_ADCCLKH_CLKGN;
extern CSRegister EN_COARSE_CKLGEN;
extern CSRegister EN_INTONLY_SDM_CGEN;
extern CSRegister EN_SDM_CLK_CGEN;
extern CSRegister PD_CP_CGEN;
extern CSRegister PD_FDIV_FB_CGEN;
extern CSRegister PD_FDIV_O_CGEN;
extern CSRegister PD_SDM_CGEN;
extern CSRegister PD_VCO_CGEN;
extern CSRegister PD_VCO_COMP_CGEN;
extern CSRegister EN_G_CGEN;
extern CSRegister FRAC_SDM_CGEN_LSB;
extern CSRegister INT_SDM_CGEN;
extern CSRegister FRAC_SDM_CGEN_MSB;
extern CSRegister REV_SDMCLK_CGEN;
extern CSRegister SEL_SDMCLK_CGEN;
extern CSRegister SX_DITHER_EN_CGEN;
extern CSRegister CLKH_OV_CLKL_CGEN;
extern CSRegister DIV_OUTCH_CGEN;
extern CSRegister TST_CGEN;
extern CSRegister REV_CLKDAC_CGEN;
extern CSRegister CMPLO_CTRL_CGEN;
extern CSRegister REV_CLKADC_CGEN;
extern CSRegister REVPH_PFD_CGEN;
extern CSRegister IOFFSET_CP_CGEN;
extern CSRegister IPULSE_CP_CGEN;
extern CSRegister ICT_VCO_CGEN;
extern CSRegister CSW_VCO_CGEN;
extern CSRegister COARSE_START_CGEN;
extern CSRegister COARSE_STEPDONE_CGEN;
extern CSRegister COARSEPLL_COMPO_CGEN;
extern CSRegister VCO_CMPHO_CGEN;
extern CSRegister VCO_CMPLO_CGEN;
extern CSRegister CP2_CGEN;
extern CSRegister CP3_CGEN;
extern CSRegister CZ_CGEN;
extern CSRegister EN_LDO_DIG;
extern CSRegister EN_LDO_DIGGN;
extern CSRegister EN_LDO_DIGSXR;
extern CSRegister EN_LDO_DIGSXT;
extern CSRegister EN_LDO_DIVGN;
extern CSRegister EN_LDO_DIVSXR;
extern CSRegister EN_LDO_DIVSXT;
extern CSRegister EN_LDO_LNA12;
extern CSRegister EN_LDO_LNA14;
extern CSRegister EN_LDO_MXRFE;
extern CSRegister EN_LDO_RBB;
extern CSRegister EN_LDO_RXBUF;
extern CSRegister EN_LDO_TBB;
extern CSRegister EN_LDO_TIA12;
extern CSRegister EN_LDO_TIA14;
extern CSRegister EN_G_LDO;
extern CSRegister EN_LOADIMP_LDO_TLOB;
extern CSRegister EN_LOADIMP_LDO_TPAD;
extern CSRegister EN_LOADIMP_LDO_TXBUF;
extern CSRegister EN_LOADIMP_LDO_VCOGN;
extern CSRegister EN_LOADIMP_LDO_VCOSXR;
extern CSRegister EN_LOADIMP_LDO_VCOSXT;
extern CSRegister EN_LDO_AFE;
extern CSRegister EN_LDO_CPGN;
extern CSRegister EN_LDO_CPSXR;
extern CSRegister EN_LDO_TLOB;
extern CSRegister EN_LDO_TPAD;
extern CSRegister EN_LDO_TXBUF;
extern CSRegister EN_LDO_VCOGN;
extern CSRegister EN_LDO_VCOSXR;
extern CSRegister EN_LDO_VCOSXT;
extern CSRegister EN_LDO_CPSXT;
extern CSRegister EN_LOADIMP_LDO_CPSXT;
extern CSRegister EN_LOADIMP_LDO_DIG;
extern CSRegister EN_LOADIMP_LDO_DIGGN;
extern CSRegister EN_LOADIMP_LDO_DIGSXR;
extern CSRegister EN_LOADIMP_LDO_DIGSXT;
extern CSRegister EN_LOADIMP_LDO_DIVGN;
extern CSRegister EN_LOADIMP_LDO_DIVSXR;
extern CSRegister EN_LOADIMP_LDO_DIVSXT;
extern CSRegister EN_LOADIMP_LDO_LNA12;
extern CSRegister EN_LOADIMP_LDO_LNA14;
extern CSRegister EN_LOADIMP_LDO_MXRFE;
extern CSRegister EN_LOADIMP_LDO_RBB;
extern CSRegister EN_LOADIMP_LDO_RXBUF;
extern CSRegister EN_LOADIMP_LDO_TBB;
extern CSRegister EN_LOADIMP_LDO_TIA12;
extern CSRegister EN_LOADIMP_LDO_TIA14;
extern CSRegister BYP_LDO_TBB;
extern CSRegister BYP_LDO_TIA12;
extern CSRegister BYP_LDO_TIA14;
extern CSRegister BYP_LDO_TLOB;
extern CSRegister BYP_LDO_TPAD;
extern CSRegister BYP_LDO_TXBUF;
extern CSRegister BYP_LDO_VCOGN;
extern CSRegister BYP_LDO_VCOSXR;
extern CSRegister BYP_LDO_VCOSXT;
extern CSRegister EN_LOADIMP_LDO_AFE;
extern CSRegister EN_LOADIMP_LDO_CPGN;
extern CSRegister EN_LOADIMP_LDO_CPSXR;
extern CSRegister BYP_LDO_AFE;
extern CSRegister BYP_LDO_CPGN;
extern CSRegister BYP_LDO_CPSXR;
extern CSRegister BYP_LDO_CPSXT;
extern CSRegister BYP_LDO_DIG;
extern CSRegister BYP_LDO_DIGGN;
extern CSRegister BYP_LDO_DIGSXR;
extern CSRegister BYP_LDO_DIGSXT;
extern CSRegister BYP_LDO_DIVGN;
extern CSRegister BYP_LDO_DIVSXR;
extern CSRegister BYP_LDO_DIVSXT;
extern CSRegister BYP_LDO_LNA12;
extern CSRegister BYP_LDO_LNA14;
extern CSRegister BYP_LDO_MXRFE;
extern CSRegister BYP_LDO_RBB;
extern CSRegister BYP_LDO_RXBUF;
extern CSRegister SPDUP_LDO_DIVSXR;
extern CSRegister SPDUP_LDO_DIVSXT;
extern CSRegister SPDUP_LDO_LNA12;
extern CSRegister SPDUP_LDO_LNA14;
extern CSRegister SPDUP_LDO_MXRFE;
extern CSRegister SPDUP_LDO_RBB;
extern CSRegister SPDUP_LDO_RXBUF;
extern CSRegister SPDUP_LDO_TBB;
extern CSRegister SPDUP_LDO_TIA12;
extern CSRegister SPDUP_LDO_TIA14;
extern CSRegister SPDUP_LDO_TLOB;
extern CSRegister SPDUP_LDO_TPAD;
extern CSRegister SPDUP_LDO_TXBUF;
extern CSRegister SPDUP_LDO_VCOGN;
extern CSRegister SPDUP_LDO_VCOSXR;
extern CSRegister SPDUP_LDO_VCOSXT;
extern CSRegister SPDUP_LDO_AFE;
extern CSRegister SPDUP_LDO_CPGN;
extern CSRegister SPDUP_LDO_CPSXR;
extern CSRegister SPDUP_LDO_CPSXT;
extern CSRegister SPDUP_LDO_DIG;
extern CSRegister SPDUP_LDO_DIGGN;
extern CSRegister SPDUP_LDO_DIGSXR;
extern CSRegister SPDUP_LDO_DIGSXT;
extern CSRegister SPDUP_LDO_DIVGN;
extern CSRegister RDIV_VCOSXR;
extern CSRegister RDIV_VCOSXT;
extern CSRegister RDIV_TXBUF;
extern CSRegister RDIV_VCOGN;
extern CSRegister RDIV_TLOB;
extern CSRegister RDIV_TPAD;
extern CSRegister RDIV_TIA12;
extern CSRegister RDIV_TIA14;
extern CSRegister RDIV_RXBUF;
extern CSRegister RDIV_TBB;
extern CSRegister RDIV_MXRFE;
extern CSRegister RDIV_RBB;
extern CSRegister RDIV_LNA12;
extern CSRegister RDIV_LNA14;
extern CSRegister RDIV_DIVSXR;
extern CSRegister RDIV_DIVSXT;
extern CSRegister RDIV_DIGSXT;
extern CSRegister RDIV_DIVGN;
extern CSRegister RDIV_DIGGN;
extern CSRegister RDIV_DIGSXR;
extern CSRegister RDIV_CPSXT;
extern CSRegister RDIV_DIG;
extern CSRegister RDIV_CPGN;
extern CSRegister RDIV_CPSXR;
extern CSRegister RDIV_SPIBUF;
extern CSRegister RDIV_AFE;
extern CSRegister SPDUP_LDO_SPIBUF;
extern CSRegister SPDUP_LDO_DIGIp2;
extern CSRegister SPDUP_LDO_DIGIp1;
extern CSRegister BYP_LDO_SPIBUF;
extern CSRegister BYP_LDO_DIGIp2;
extern CSRegister BYP_LDO_DIGIp1;
extern CSRegister EN_LOADIMP_LDO_SPIBUF;
extern CSRegister EN_LOADIMP_LDO_DIGIp2;
extern CSRegister EN_LOADIMP_LDO_DIGIp1;
extern CSRegister PD_LDO_SPIBUF;
extern CSRegister PD_LDO_DIGIp2;
extern CSRegister PD_LDO_DIGIp1;
extern CSRegister EN_G_LDOP;
extern CSRegister RDIV_DIGIp2;
extern CSRegister RDIV_DIGIp1;
extern CSRegister BSIGT;
extern CSRegister BSTATE;
extern CSRegister EN_SDM_TSTO_SXT;
extern CSRegister EN_SDM_TSTO_SXR;
extern CSRegister EN_SDM_TSTO_CGEN;
extern CSRegister BENC;
extern CSRegister BENR;
extern CSRegister BENT;
extern CSRegister BSTART;
extern CSRegister BSIGR;
extern CSRegister BSIGC;
extern CSRegister CDS_MCLK2;
extern CSRegister CDS_MCLK1;
extern CSRegister CDSN_TXBTSP;
extern CSRegister CDSN_TXATSP;
extern CSRegister CDSN_RXBTSP;
extern CSRegister CDSN_RXATSP;
extern CSRegister CDSN_TXBLML;
extern CSRegister CDSN_TXALML;
extern CSRegister CDSN_RXBLML;
extern CSRegister CDSN_RXALML;
extern CSRegister CDSN_MCLK2;
extern CSRegister CDSN_MCLK1;
extern CSRegister CDS_TXBTSP;
extern CSRegister CDS_TXATSP;
extern CSRegister CDS_RXBTSP;
extern CSRegister CDS_RXATSP;
extern CSRegister CDS_TXBLML;
extern CSRegister CDS_TXALML;
extern CSRegister CDS_RXBLML;
extern CSRegister CDS_RXALML;
extern CSRegister EN_LOWBWLOMX_TMX_TRF;
extern CSRegister EN_NEXTTX_TRF;
extern CSRegister EN_AMPHF_PDET_TRF;
extern CSRegister LOADR_PDET_TRF;
extern CSRegister PD_PDET_TRF;
extern CSRegister PD_TLOBUF_TRF;
extern CSRegister PD_TXPAD_TRF;
extern CSRegister EN_G_TRF;
extern CSRegister F_TXPAD_TRF;
extern CSRegister L_LOOPB_TXPAD_TRF;
extern CSRegister LOSS_LIN_TXPAD_TRF;
extern CSRegister LOSS_MAIN_TXPAD_TRF;
extern CSRegister EN_LOOPB_TXPAD_TRF;
extern CSRegister GCAS_GNDREF_TXPAD_TRF;
extern CSRegister ICT_LIN_TXPAD_TRF;
extern CSRegister ICT_MAIN_TXPAD_TRF;
extern CSRegister VGCAS_TXPAD_TRF;
extern CSRegister SEL_BAND1_TRF;
extern CSRegister SEL_BAND2_TRF;
extern CSRegister LOBIASN_TXM_TRF;
extern CSRegister LOBIASP_TXX_TRF;
extern CSRegister CDC_I_TRF;
extern CSRegister CDC_Q_TRF;
extern CSRegister STATPULSE_TBB;
extern CSRegister LOOPB_TBB;
extern CSRegister PD_LPFH_TBB;
extern CSRegister PD_LPFIAMP_TBB;
extern CSRegister PD_LPFLAD_TBB;
extern CSRegister PD_LPFS5_TBB;
extern CSRegister EN_G_TBB;
extern CSRegister ICT_LPFS5_F_TBB;
extern CSRegister ICT_LPFS5_PT_TBB;
extern CSRegister ICT_LPF_H_PT_TBB;
extern CSRegister ICT_LPFH_F_TBB;
extern CSRegister ICT_LPFLAD_F_TBB;
extern CSRegister ICT_LPFLAD_PT_TBB;
extern CSRegister CG_IAMP_TBB;
extern CSRegister ICT_IAMP_FRP_TBB;
extern CSRegister ICT_IAMP_GG_FRP_TBB;
extern CSRegister RCAL_LPFH_TBB;
extern CSRegister RCAL_LPFLAD_TBB;
extern CSRegister TSTIN_TBB;
extern CSRegister BYPLADDER_TBB;
extern CSRegister CCAL_LPFLAD_TBB;
extern CSRegister RCAL_LPFS5_TBB;
extern CSRegister CDC_I_RFE;
extern CSRegister CDC_Q_RFE;
extern CSRegister PD_LNA_RFE;
extern CSRegister PD_RLOOPB_1_RFE;
extern CSRegister PD_RLOOPB_2_RFE;
extern CSRegister PD_MXLOBUF_RFE;
extern CSRegister PD_QGEN_RFE;
extern CSRegister PD_RSSI_RFE;
extern CSRegister PD_TIA_RFE;
extern CSRegister EN_G_RFE;
extern CSRegister SEL_PATH_RFE;
extern CSRegister EN_DCOFF_RXFE_RFE;
extern CSRegister EN_INSHSW_LB1_RFE;
extern CSRegister EN_INSHSW_LB2_RFE;
extern CSRegister EN_INSHSW_L_RFE;
extern CSRegister EN_INSHSW_W_RFE;
extern CSRegister EN_NEXTRX_RFE;
extern CSRegister DCOFFI_RFE;
extern CSRegister DCOFFQ_RFE;
extern CSRegister ICT_LOOPB_RFE;
extern CSRegister ICT_TIAMAIN_RFE;
extern CSRegister ICT_TIAOUT_RFE;
extern CSRegister ICT_LNACMO_RFE;
extern CSRegister ICT_LNA_RFE;
extern CSRegister ICT_LODC_RFE;
extern CSRegister CAP_RXMXO_RFE;
extern CSRegister CGSIN_LNA_RFE;
extern CSRegister CCOMP_TIA_RFE;
extern CSRegister CFB_TIA_RFE;
extern CSRegister G_LNA_RFE;
extern CSRegister G_RXLOOPB_RFE;
extern CSRegister G_TIA_RFE;
extern CSRegister RCOMP_TIA_RFE;
extern CSRegister RFB_TIA_RFE;
extern CSRegister EN_LB_LPFH_RBB;
extern CSRegister EN_LB_LPFL_RBB;
extern CSRegister PD_LPFH_RBB;
extern CSRegister PD_LPFL_RBB;
extern CSRegister PD_PGA_RBB;
extern CSRegister EN_G_RBB;
extern CSRegister R_CTL_LPF_RBB;
extern CSRegister RCC_CTL_LPFH_RBB;
extern CSRegister C_CTL_LPFH_RBB;
extern CSRegister RCC_CTL_LPFL_RBB;
extern CSRegister C_CTL_LPFL_RBB;
extern CSRegister INPUT_CTL_PGA_RBB;
extern CSRegister ICT_LPF_IN_RBB;
extern CSRegister ICT_LPF_OUT_RBB;
extern CSRegister OSW_PGA_RBB;
extern CSRegister ICT_PGA_OUT_RBB;
extern CSRegister ICT_PGA_IN_RBB;
extern CSRegister G_PGA_RBB;
extern CSRegister RCC_CTL_PGA_RBB;
extern CSRegister C_CTL_PGA_RBB;
extern CSRegister RESET_N;
extern CSRegister SPDUP_VCO;
extern CSRegister BYPLDO_VCO;
extern CSRegister EN_COARSEPLL;
extern CSRegister CURLIM_VCO;
extern CSRegister EN_DIV2_DIVPROG;
extern CSRegister EN_INTONLY_SDM;
extern CSRegister EN_SDM_CLK;
extern CSRegister PD_FBDIV;
extern CSRegister PD_LOCH_T2RBUF;
extern CSRegister PD_CP;
extern CSRegister PD_FDIV;
extern CSRegister PD_SDM;
extern CSRegister PD_VCO_COMP;
extern CSRegister PD_VCO;
extern CSRegister EN_G;
extern CSRegister FRAC_SDM_LSB;
extern CSRegister INT_SDM;
extern CSRegister FRAC_SDM_MSB;
extern CSRegister PW_DIV2_LOCH;
extern CSRegister PW_DIV4_LOCH;
extern CSRegister DIV_LOCH;
extern CSRegister TST_SX;
extern CSRegister SEL_SDMCLK;
extern CSRegister SX_DITHER_EN;
extern CSRegister REV_SDMCLK;
extern CSRegister VDIV_VCO;
extern CSRegister ICT_VCO;
extern CSRegister RSEL_LDO_VCO;
extern CSRegister CSW_VCO;
extern CSRegister SEL_VCO;
extern CSRegister COARSE_START;
extern CSRegister REVPH_PFD;
extern CSRegister IOFFSET_CP;
extern CSRegister IPULSE_CP;
extern CSRegister COARSE_STEPDONE;
extern CSRegister COARSEPLL_COMPO;
extern CSRegister VCO_CMPHO;
extern CSRegister VCO_CMPLO;
extern CSRegister CP2_PLL;
extern CSRegister CP3_PLL;
extern CSRegister CZ;
extern CSRegister EN_DIR_SXRSXT;
extern CSRegister EN_DIR_RBB;
extern CSRegister EN_DIR_RFE;
extern CSRegister EN_DIR_TBB;
extern CSRegister EN_DIR_TRF;
extern CSRegister TSGFC_TXTSP;
extern CSRegister TSGFCW_TXTSP;
extern CSRegister TSGDCLDQ_TXTSP;
extern CSRegister TSGDCLDI_TXTSP;
extern CSRegister TSGSWAPIQ_TXTSP;
extern CSRegister TSGMODE_TXTSP;
extern CSRegister INSEL_TXTSP;
extern CSRegister BSTART_TXTSP;
extern CSRegister EN_TXTSP;
extern CSRegister GCORRQ_TXTSP;
extern CSRegister GCORRI_TXTSP;
extern CSRegister HBI_OVR_TXTSP;
extern CSRegister IQCORR_TXTSP;
extern CSRegister DCCORRI_TXTSP;
extern CSRegister DCCORRQ_TXTSP;
extern CSRegister GFIR1_L_TXTSP;
extern CSRegister GFIR1_N_TXTSP;
extern CSRegister GFIR2_L_TXTSP;
extern CSRegister GFIR2_N_TXTSP;
extern CSRegister GFIR3_L_TXTSP;
extern CSRegister GFIR3_N_TXTSP;
extern CSRegister CMIX_GAIN_TXTSP;
extern CSRegister CMIX_SC_TXTSP;
extern CSRegister CMIX_BYP_TXTSP;
extern CSRegister ISINC_BYP_TXTSP;
extern CSRegister GFIR3_BYP_TXTSP;
extern CSRegister GFIR2_BYP_TXTSP;
extern CSRegister GFIR1_BYP_TXTSP;
extern CSRegister DC_BYP_TXTSP;
extern CSRegister GC_BYP_TXTSP;
extern CSRegister PH_BYP_TXTSP;
extern CSRegister BSIGI_TXTSP;
extern CSRegister BSTATE_TXTSP;
extern CSRegister BSIGQ_TXTSP;
extern CSRegister DC_REG_TXTSP;
extern CSRegister DTHBIT_TX;
extern CSRegister SEL_TX;
extern CSRegister MODE_TX;
extern CSRegister PHO_TX;
extern CSRegister CAPTURE;
extern CSRegister CAPSEL;
extern CSRegister CAPSEL_ADC;
extern CSRegister TSGFC_RXTSP;
extern CSRegister TSGFCW_RXTSP;
extern CSRegister TSGDCLDQ_RXTSP;
extern CSRegister TSGDCLDI_RXTSP;
extern CSRegister TSGSWAPIQ_RXTSP;
extern CSRegister TSGMODE_RXTSP;
extern CSRegister INSEL_RXTSP;
extern CSRegister BSTART_RXTSP;
extern CSRegister EN_RXTSP;
extern CSRegister GCORRQ_RXTSP;
extern CSRegister GCORRI_RXTSP;
extern CSRegister HBD_OVR_RXTSP;
extern CSRegister IQCORR_RXTSP;
extern CSRegister HBD_DLY;
extern CSRegister DCCORR_AVG_RXTSP;
extern CSRegister GFIR1_L_RXTSP;
extern CSRegister GFIR1_N_RXTSP;
extern CSRegister GFIR2_L_RXTSP;
extern CSRegister GFIR2_N_RXTSP;
extern CSRegister GFIR3_L_RXTSP;
extern CSRegister GFIR3_N_RXTSP;
extern CSRegister AGC_K_RXTSP;
extern CSRegister AGC_ADESIRED_RXTSP;
extern CSRegister RSSI_MODE;
extern CSRegister AGC_MODE_RXTSP;
extern CSRegister AGC_AVG_RXTSP;
extern CSRegister DC_REG_RXTSP;
extern CSRegister CMIX_GAIN_RXTSP;
extern CSRegister CMIX_SC_RXTSP;
extern CSRegister CMIX_BYP_RXTSP;
extern CSRegister AGC_BYP_RXTSP;
extern CSRegister GFIR3_BYP_RXTSP;
extern CSRegister GFIR2_BYP_RXTSP;
extern CSRegister GFIR1_BYP_RXTSP;
extern CSRegister DC_BYP_RXTSP;
extern CSRegister GC_BYP_RXTSP;
extern CSRegister PH_BYP_RXTSP;
extern CSRegister CAPD;
extern CSRegister DTHBIT_RX;
extern CSRegister SEL_RX;
extern CSRegister MODE_RX;
extern CSRegister PHO_RX;
extern CSRegister TRX_GAIN_SRC;

extern CSRegister LML2_TRXIQPULSE;
extern CSRegister LML2_SISODDR;
extern CSRegister LML1_TRXIQPULSE;
extern CSRegister LML1_SISODDR;
extern CSRegister MCLK2_DLY;
extern CSRegister MCLK1_DLY;
extern CSRegister MCLK2_INV;
extern CSRegister MCLK1_INV;

extern CSRegister CMIX_GAIN_TXTSP_R3;
extern CSRegister CMIX_GAIN_RXTSP_R3;
extern CSRegister R5_LPF_BYP_TBB;
extern CSRegister CG_IAMP_TBB_R3;
extern CSRegister LOSS_LIN_TXPAD_R3;
extern CSRegister LOSS_MAIN_TXPAD_R3;
extern CSRegister C_CTL_PGA_RBB_R3;
extern CSRegister G_PGA_RBB_R3;
extern CSRegister G_LNA_RFE_R3;
extern CSRegister G_TIA_RFE_R3;
extern CSRegister RZ_CTRL;
extern CSRegister CMPLO_CTRL_SX;
extern CSRegister CMPLO_CTRL_CGEN_R3;
extern CSRegister ISINK_SPIBUFF;

extern CSRegister DCMODE;
extern CSRegister PD_DCDAC_RXB;
extern CSRegister PD_DCDAC_RXA;
extern CSRegister PD_DCDAC_TXB;
extern CSRegister PD_DCDAC_TXA;
extern CSRegister PD_DCCMP_RXB;
extern CSRegister PD_DCCMP_RXA;
extern CSRegister PD_DCCMP_TXB;
extern CSRegister PD_DCCMP_TXA;

extern CSRegister DCCAL_CALSTATUS_RXBQ;
extern CSRegister DCCAL_CALSTATUS_RXBI;
extern CSRegister DCCAL_CALSTATUS_RXAQ;
extern CSRegister DCCAL_CALSTATUS_RXAI;
extern CSRegister DCCAL_CALSTATUS_TXBQ;
extern CSRegister DCCAL_CALSTATUS_TXBI;
extern CSRegister DCCAL_CALSTATUS_TXAQ;
extern CSRegister DCCAL_CALSTATUS_TXAI;

extern CSRegister DCCAL_CMPSTATUS_RXBQ;
extern CSRegister DCCAL_CMPSTATUS_RXBI;
extern CSRegister DCCAL_CMPSTATUS_RXAQ;
extern CSRegister DCCAL_CMPSTATUS_RXAI;
extern CSRegister DCCAL_CMPSTATUS_TXBQ;
extern CSRegister DCCAL_CMPSTATUS_TXBI;
extern CSRegister DCCAL_CMPSTATUS_TXAQ;
extern CSRegister DCCAL_CMPSTATUS_TXAI;

extern CSRegister DCCAL_CMPCFG_RXBQ;
extern CSRegister DCCAL_CMPCFG_RXBI;
extern CSRegister DCCAL_CMPCFG_RXAQ;
extern CSRegister DCCAL_CMPCFG_RXAI;
extern CSRegister DCCAL_CMPCFG_TXBQ;
extern CSRegister DCCAL_CMPCFG_TXBI;
extern CSRegister DCCAL_CMPCFG_TXAQ;
extern CSRegister DCCAL_CMPCFG_TXAI;

extern CSRegister DCCAL_START_RXBQ;
extern CSRegister DCCAL_START_RXBI;
extern CSRegister DCCAL_START_RXAQ;
extern CSRegister DCCAL_START_RXAI;
extern CSRegister DCCAL_START_TXBQ;
extern CSRegister DCCAL_START_TXBI;
extern CSRegister DCCAL_START_TXAQ;
extern CSRegister DCCAL_START_TXAI;

extern CSRegister DCWR_TXAI;
extern CSRegister DCRD_TXAI;
extern CSRegister DC_TXAI;
extern CSRegister DCWR_TXAQ;
extern CSRegister DCRD_TXAQ;
extern CSRegister DC_TXAQ;
extern CSRegister DCWR_TXBI;
extern CSRegister DCRD_TXBI;
extern CSRegister DC_TXBI;
extern CSRegister DCWR_TXBQ;
extern CSRegister DCRD_TXBQ;
extern CSRegister DC_TXBQ;
extern CSRegister DCWR_RXAI;
extern CSRegister DCRD_RXAI;
extern CSRegister DC_RXAI;
extern CSRegister DCWR_RXAQ;
extern CSRegister DCRD_RXAQ;
extern CSRegister DC_RXAQ;
extern CSRegister DCWR_RXBI;
extern CSRegister DCRD_RXBI;
extern CSRegister DC_RXBI;
extern CSRegister DCWR_RXBQ;
extern CSRegister DCRD_RXBQ;
extern CSRegister DC_RXBQ;
extern CSRegister DC_RXCDIV;
extern CSRegister DC_TXCDIV;
extern CSRegister HYSCMP_RXB;
extern CSRegister HYSCMP_RXA;
extern CSRegister HYSCMP_TXB;
extern CSRegister HYSCMP_TXA;
extern CSRegister DAC_CLKDIV;
extern CSRegister RSSI_RSSIMODE;
extern CSRegister RSSI_PD;
extern CSRegister INTADC_CMPSTATUS_TEMPREF;
extern CSRegister INTADC_CMPSTATUS_TEMPVPTAT;
extern CSRegister INTADC_CMPSTATUS_RSSI2;
extern CSRegister INTADC_CMPSTATUS_RSSI1;
extern CSRegister INTADC_CMPSTATUS_PDET2;
extern CSRegister INTADC_CMPSTATUS_PDET1;
extern CSRegister RSSI_BIAS;
extern CSRegister RSSI_HYSCMP;
extern CSRegister INTADC_CMPCFG_TEMPREF;
extern CSRegister INTADC_CMPCFG_TEMPVPTAT;
extern CSRegister INTADC_CMPCFG_RSSI2;
extern CSRegister INTADC_CMPCFG_RSSI1;
extern CSRegister INTADC_CMPCFG_PDET2;
extern CSRegister INTADC_CMPCFG_PDET1;
extern CSRegister RSSI_DAC_VAL;
extern CSRegister RSSI_PDET2_VAL;
extern CSRegister RSSI_PDET1_VAL;
extern CSRegister RSSI_RSSI2_VAL;
extern CSRegister RSSI_RSSI1_VAL;
extern CSRegister RSSI_TREF_VAL;
extern CSRegister RSSI_TVPTAT_VAL;
extern CSRegister RSSIDC_CMPSTATUS;
extern CSRegister RSSIDC_RSEL;
extern CSRegister RSSIDC_HYSCMP;
extern CSRegister RSSIDC_PD;
extern CSRegister RSSIDC_DCO2;
extern CSRegister RSSIDC_DCO1;
extern CSRegister DCLOOP_STOP;
} // namespace LMS7002MCSR_Data
} // namespace lime
