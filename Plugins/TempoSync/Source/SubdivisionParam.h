#pragma once

#include <juce_audio_utils/juce_audio_utils.h>

struct SubdivisionParameter : juce::AudioParameterChoice
{
    SubdivisionParameter();

    double getDivisionPPQ();
};