#pragma once

#include <stdint.h>
#include <string.h>
#include <memory>
#include "Register.h"

namespace lime {

class ISPI;

/** @brief Class for interfacing with the equalizer. */
class Equalizer
{
  public:
    /** @brief Structure containing the configuration of the equalizer. */
    struct Config {
        /** @brief Crest Factor Reduction (CFR) controls. */
        struct CFR {
            bool bypass;
            bool sleep;
            bool bypassGain;
            uint8_t order;
            uint8_t interpolation;
            uint16_t threshold;
            uint16_t thresholdGain;
        } cfr[2];

        /** @brief Post-CFR Finite Impulse Response (FIR) information */
        struct FIR {
            bool sleep;
            bool bypass;
            int16_t coefficients[32];
            uint8_t coefficientsCount;
        } fir[2];
        bool bypassRxEqualizer[2];
        bool bypassTxEqualizer[2];

        Config() { memset(this, 0, sizeof(Config)); }
    };

    Equalizer(std::shared_ptr<ISPI> comms, uint32_t spiBusAddr);
    ~Equalizer();
    void Configure(const Equalizer::Config& cfg);

    void SetOversample(uint8_t oversample);
    uint8_t GetOversample();

  private:
    std::shared_ptr<ISPI> m_Comms;
    uint32_t mSPIbusAddr;
    void WriteRegister(const Register& reg, uint16_t value);
    uint16_t ReadRegister(const Register& reg);

    void SetFIRCoefficients(const int16_t* coefficients, uint16_t count);
    void UpdateHannCoeff(uint16_t Filt_N);

public:
    static constexpr Register EN_RXTSP{0x00A0, 0, 0, 0, 0};
    static constexpr Register EN_TXTSP{0x0080, 0, 0, 0, 0};

    static constexpr Register RX_DCCORR_BYP{0x00AC, 2, 2, 0, 0};
    static constexpr Register RX_PHCORR_BYP{0x00AC, 0, 0, 0, 0};
    static constexpr Register RX_GCORR_BYP{0x00AC, 1, 1, 0, 0};

    static constexpr Register RX_EQU_BYP{0x00AC, 5, 5, 0, 0};

    static constexpr Register RX_DCLOOP_BYP{0x00AC, 8, 8, 0, 0};
    static constexpr Register RX_DCLOOP_AVG{0x00A4, 2, 0, 0, 0};

    static constexpr Register TX_HB_BYP{0x0088, 0, 0, 1, 0};
    static constexpr Register TX_HB_DEL{0x0088, 1, 1, 0, 0};
    static constexpr Register SLEEP_CFR{0x0088, 2, 2, 1, 0};
    static constexpr Register BYPASS_CFR{0x0088, 3, 3, 1, 0};
    static constexpr Register ODD_CFR{0x0088, 4, 4, 1, 0};
    static constexpr Register BYPASSGAIN_CFR{0x0088, 5, 5, 1, 0};
    static constexpr Register SLEEP_FIR{0x0088, 6, 6, 1, 0};
    static constexpr Register BYPASS_FIR{0x0088, 7, 7, 1, 0};

    static constexpr Register ODD_FIR{0x0088, 8, 8, 0, 0};
    static constexpr Register TX_PHCORR_BYP{0x0088, 9, 9, 0, 0};
    static constexpr Register TX_GCORR_BYP{0x0088, 10, 10, 0, 0};
    static constexpr Register TX_DCCORR_BYP{0x0088, 11, 11, 0, 0};
    static constexpr Register TX_ISINC_BYP{0x0088, 12, 12, 1, 0};
    static constexpr Register TX_EQU_BYP{0x0088, 13, 13, 1, 0};
    static constexpr Register TX_INVERTQ{0x0088, 15, 15, 0, 0};

    static constexpr Register TX_GCORRQ{0x0081, 11, 0, 2047, 0};
    static constexpr Register TX_GCORRI{0x0082, 11, 0, 2047, 0};
    static constexpr Register TX_PHCORR{0x0083, 11, 0, 0, 1};
    static constexpr Register TX_DCCORRI{0x0084, 15, 0, 0, 0};
    static constexpr Register TX_DCCORRQ{0x0085, 15, 0, 0, 0};
    static constexpr Register thresholdSpin{0x0086, 15, 0, 0, 0};
    static constexpr Register thresholdGain{0x0087, 15, 0, 0, 0};
    static constexpr Register CFR_ORDER{0x008C, 7, 0, 0, 0}; // dummy register

    static constexpr Register RX_GCORRQ{0x00A1, 11, 0, 2047, 0};
    static constexpr Register RX_GCORRI{0x00A2, 11, 0, 2047, 0};
    static constexpr Register RX_PHCORR{0x00A3, 11, 0, 0, 1};

    static constexpr Register cmbInsel{0x0080, 2, 2, 0, 0};

    static constexpr Register MAC{0xFFFF, 1, 0, 0, 0};
};

} // namespace lime
