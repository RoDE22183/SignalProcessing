#include "trianglewave.h"

float Signal::TriangelWave::generate(float time) const
{
    float t = std::fmod(time * m_frequency + m_phase / (2 * M_PI), 1.0f);
    return m_amplitude * (t < 0.5f ? 4 * t - 1 : 3 - 4 * t);
}

void Signal::TriangelWave::setFrequency(float frequency)
{
    Waveform::m_frequency = frequency;
}

void Signal::TriangelWave::setAmplitude(float amplitude)
{
    Waveform::m_amplitude = amplitude;
}

void Signal::TriangelWave::setPhase(float phase)
{
    Waveform::m_phase = phase;
}