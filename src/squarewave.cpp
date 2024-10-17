#include "squarewave.h"

float Signal::SquareWave::generate(float time) const
{

    float t = std::fmod(time * m_frequency + m_phase / (2 * M_PI), 1.0f);
    return m_amplitude * (t < 0.5f ? 1.0f : -1.0f);
}

void Signal::SquareWave::setFrequency(float frequency)
{
    Waveform::m_frequency = frequency;
}

void Signal::SquareWave::setAmplitude(float amplitude)
{
    Waveform::m_amplitude = amplitude;
}

void Signal::SquareWave::setPhase(float phase)
{
    Waveform::m_phase = phase;
}