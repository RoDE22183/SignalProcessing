#include "waveform.h"
#include "squarewave.h"
#include "sinwave.h"
#include "dsp.h"

using Signal::SineWave;
using Signal::SquareWave;
using Signal::Waveform;

// Generating Wave forms
void generateWaveform(const std::unique_ptr<Waveform> &waveform, float duration, float sampleRate, std::vector<float> &timeValues, std::vector<float> &waveformValues)
{

    float timeStep = 1.0f / sampleRate;
    for (float t = 0; t < duration; t += timeStep)
    {
        timeValues.push_back(t);
        waveformValues.push_back(waveform->generate(t));
    }
}

// Saving Output in .csv format
void saveToCSV(const std::vector<float> &timeValues, const std::vector<float> &waveformValues, const std::string &filename)
{
    std::ofstream file(filename);
    file << "Time,Value\n";
    for (size_t i = 0; i < timeValues.size(); ++i)
    {
        file << timeValues[i] << "," << waveformValues[i] << "\n";
    }
}

int main()
{
    std::string waveformType;
    float frequency, amplitude, phase, duration, sampleRate;

    std::cout << "Enter waveform type (sine/square): ";
    std::cin >> waveformType;
    if (waveformType != "sine" && waveformType != "square")
    {
        std::cerr << "Error: Invalid waveform type. Please enter 'sine' or 'square'.\n";
        return 1;
    }

    std::cout << "Enter frequency (Hz): ";
    if (!(std::cin >> frequency) || frequency <= 0)
    {
        std::cerr << "Error: Invalid frequency. Please enter a positive number.\n";
        return 1;
    }

    std::cout << "Enter amplitude: ";
    if (!(std::cin >> amplitude))
    {
        std::cerr << "Error: Invalid amplitude. Please enter a number.\n";
        return 1;
    }

    std::cout << "Enter phase shift (radians): ";
    if (!(std::cin >> phase))
    {
        std::cerr << "Error: Invalid phase shift. Please enter a number.\n";
        return 1;
    }

    std::cout << "Enter duration (seconds): ";
    if (!(std::cin >> duration) || duration <= 0)
    {
        std::cerr << "Error: Invalid duration. Please enter a positive number.\n";
        return 1;
    }

    std::cout << "Enter sample rate (samples/second): ";
    if (!(std::cin >> sampleRate) || sampleRate <= 0)
    {
        std::cerr << "Error: Invalid sample rate. Please enter a positive number.\n";
        return 1;
    }

    std::unique_ptr<Waveform> waveform;
    if (waveformType == "sine")
    {
        waveform = std::make_unique<SineWave>();
    }
    else if (waveformType == "square")
    {
        waveform = std::make_unique<SquareWave>();
    }

    waveform->setFrequency(frequency);
    waveform->setAmplitude(amplitude);
    waveform->setPhase(phase);

    std::vector<float> timeValues, waveformValues;
    generateWaveform(waveform, duration, sampleRate, timeValues, waveformValues);

    saveToCSV(timeValues, waveformValues, waveformType + "_waveform.csv");

    char applyDSP;
    std::cout << "Do you want to apply DSP functions? (y/n): ";
    std::cin >> applyDSP;

    if (applyDSP == 'y' || applyDSP == 'Y')
    {
        float scaleFactor;
        std::cout << "Enter scale factor for amplitude: ";
        if (!(std::cin >> scaleFactor))
        {
            std::cerr << "Error: Invalid scale factor. Please enter a number.\n";
            return 1;
        }
        DSPFunctions::scaleAmplitude(waveformValues, scaleFactor);

        float noiseMagnitude;
        std::cout << "Enter noise magnitude: ";
        if (!(std::cin >> noiseMagnitude) || noiseMagnitude < 0)
        {
            std::cerr << "Error: Invalid noise magnitude. Please enter a non-negative number.\n";
            return 1;
        }
        DSPFunctions::addNoise(waveformValues, noiseMagnitude);

        int filterWindowSize;
        std::cout << "Enter moving average filter window size: ";
        if (!(std::cin >> filterWindowSize) || filterWindowSize <= 0)
        {
            std::cerr << "Error: Invalid filter window size. Please enter a positive integer.\n";
            return 1;
        }
        DSPFunctions::applyMovingAverageFilter(waveformValues, filterWindowSize);

        saveToCSV(timeValues, waveformValues, waveformType + "_processed_waveform.csv");
        std::cout << "Processed waveform data saved to " << waveformType << "_processed_waveform.csv\n";

        char overlayWaveforms;
        std::cout << "Do you want to overlay with another waveform? (y/n): ";
        std::cin >> overlayWaveforms;

        if (overlayWaveforms == 'y' || overlayWaveforms == 'Y')
        {
            std::string secondWaveformType;
            std::cout << "Enter second waveform type (sine/square): ";
            std::cin >> secondWaveformType;
            if (secondWaveformType != "sine" && secondWaveformType != "square")
            {
                std::cerr << "Error: Invalid waveform type. Please enter 'sine' or 'square'.\n";
                return 1;
            }

            std::unique_ptr<Waveform> secondWaveform;
            if (secondWaveformType == "sine")
            {
                secondWaveform = std::make_unique<SineWave>();
            }
            else if (secondWaveformType == "square")
            {
                secondWaveform = std::make_unique<SquareWave>();
            }

            secondWaveform->setFrequency(frequency);
            secondWaveform->setAmplitude(amplitude);
            secondWaveform->setPhase(phase);

            std::vector<float> secondTimeValues, secondWaveformValues;
            generateWaveform(secondWaveform, duration, sampleRate, secondTimeValues, secondWaveformValues);

            std::vector<float> overlaidWaveform = DSPFunctions::overlayWaveforms(waveformValues, secondWaveformValues);

            saveToCSV(timeValues, overlaidWaveform, "overlaid_waveform.csv");
            std::cout << "Overlaid waveform data saved to overlaid_waveform.csv\n";
        }
    }

    return 0;
}