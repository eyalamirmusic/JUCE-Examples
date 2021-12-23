#pragma once

#include <shared_plugin_helpers/shared_plugin_helpers.h>

struct Transport
{
    Transport();
    void prepare(double sampleRate, int maxBlockSize);
    double getPPQPerSample() const;
    void process(juce::AudioPlayHead* playHead, int numSamples);

    std::atomic<double> currentPosition {0};
    double samplesInMinute = 0.0;
    juce::AudioPlayHead::CurrentPositionInfo info;
    std::vector<double> ppqPositions;
};