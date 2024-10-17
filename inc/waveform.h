#ifndef WAVEFORM_H
#define WAVEFORM_H
#include "Headers.h"
namespace Signal
{
    class Waveform
    {
    public:
        virtual ~Waveform() = default;

        virtual float generate(float time) const = 0;
        virtual void setFrequency(float frequency) = 0;
        virtual void setAmplitude(float amplitude) = 0;
        virtual void setPhase(float phase) = 0;

    public:
        float m_frequency;
        float m_amplitude;
        float m_phase;
    };
}

#endif