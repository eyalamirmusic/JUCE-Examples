#include "Transport.h"

Transport::Transport()
{
    info.isPlaying = true;
}

void Transport::prepare(double sampleRate, int maxBlockSize)
{
    samplesInMinute = sampleRate * 60;
    ppqPositions.resize(maxBlockSize);
}

double Transport::getPPQPerSample() const
{
    auto samplesPerBeat = samplesInMinute / info.bpm;
    return 1.0 / samplesPerBeat;
}

void Transport::process(juce::AudioPlayHead* playHead, int numSamples)
{
    if (playHead != nullptr)
        playHead->getCurrentPosition(info);

    auto ppqPerSample = getPPQPerSample();
    double offset = 0.0;

    for (int sample = 0; sample < numSamples; ++sample)
    {
        ppqPositions[sample] = info.ppqPosition + offset;
        offset += ppqPerSample;
    }

    info.ppqPosition += offset;

    currentPosition.store(info.ppqPosition);
}
