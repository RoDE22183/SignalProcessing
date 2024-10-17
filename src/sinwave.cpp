#include "sinwave.h"

float Signal::SineWave::generate(float time) const
{

    return m_amplitude * std::sin(2 * M_PI * m_frequency * time + m_phase);
}

void Signal::SineWave::setFrequency(float frequency)
{
    Waveform::m_frequency = frequency;
}

void Signal::SineWave::setAmplitude(float amplitude)
{
    Waveform::m_amplitude = amplitude;
}

void Signal::SineWave::setPhase(float phase)
{
    Waveform::m_phase = phase;
}