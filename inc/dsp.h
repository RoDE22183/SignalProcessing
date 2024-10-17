#ifndef DSP_H
#define DSP_H

#include "Headers.h"
#include "waveform.h"

class DSPFunctions
{
public:
    // Scale the amplitude of a waveform
    static void scaleAmplitude(std::vector<float> &waveform, float scaleFactor);

    // Add white noise to a waveform
    static void addNoise(std::vector<float> &waveform, float noiseMagnitude);

    // Apply a simple moving average filter
    static void applyMovingAverageFilter(std::vector<float> &waveform, int windowSize);

    // Overlay two waveforms
    static std::vector<float> overlayWaveforms(const std::vector<float> &waveform1, const std::vector<float> &waveform2);
};

#endif