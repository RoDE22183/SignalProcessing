#include "dsp.h"

// Scale the amplitude of a waveform
void DSPFunctions::scaleAmplitude(std::vector<float> &waveform, float scaleFactor)
{
    for (auto &sample : waveform)
    {
        sample *= scaleFactor;
    }
}

// Add  noise to a waveform
void DSPFunctions::addNoise(std::vector<float> &waveform, float noiseMagnitude)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-noiseMagnitude, noiseMagnitude);

    for (auto &sample : waveform)
    {
        sample += dis(gen);
    }
}

// Apply a simple moving average filter
void DSPFunctions::applyMovingAverageFilter(std::vector<float> &waveform, int windowSize)
{
    std::vector<float> filteredWaveform(waveform.size());

    for (size_t i = 0; i < waveform.size(); ++i)
    {
        int start = std::max(0, static_cast<int>(i) - windowSize / 2);
        int end = std::min(static_cast<int>(waveform.size()), static_cast<int>(i) + windowSize / 2 + 1);

        float sum = std::accumulate(waveform.begin() + start, waveform.begin() + end, 0.0f);
        filteredWaveform[i] = sum / (end - start);
    }

    waveform = std::move(filteredWaveform);
}

// Overlay two waveforms
std::vector<float> DSPFunctions::overlayWaveforms(const std::vector<float> &waveform1, const std::vector<float> &waveform2)
{
    std::vector<float> result(std::max(waveform1.size(), waveform2.size()), 0.0f);

    for (size_t i = 0; i < result.size(); ++i)
    {
        if (i < waveform1.size())
            result[i] += waveform1[i];
        if (i < waveform2.size())
            result[i] += waveform2[i];
    }

    return result;
}
