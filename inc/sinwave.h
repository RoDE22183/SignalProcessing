#ifndef SINEWAVE_H
#define SINEWAVE_H
#include "waveform.h"

namespace Signal
{

    class SineWave : public Waveform
    {
    public:
        float generate(float time) const override;

        void setFrequency(float frequency) override;
        void setAmplitude(float amplitude) override;
        void setPhase(float phase) override;
    };
}
#endif