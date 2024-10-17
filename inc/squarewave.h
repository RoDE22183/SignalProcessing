#ifndef SQUAREWAVE_H
#define SQUAREWAVE_H
#include "waveform.h"

namespace Signal
{

    class SquareWave : public Waveform
    {
    public:
        float generate(float time) const override;

        void setFrequency(float frequency) override;
        void setAmplitude(float amplitude) override;
        void setPhase(float phase) override;
    };
}
#endif