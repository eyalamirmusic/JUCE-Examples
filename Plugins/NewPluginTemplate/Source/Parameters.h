#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

struct Parameters
{
    void add(juce::AudioProcessor& processor) const
    {
        processor.addParameter(gain);
        processor.addParameter(enable);
    }

    //Raw pointers. They will be owned by either the processor or the APVTS (if you use it)
    juce::AudioParameterFloat* gain =
        new juce::AudioParameterFloat("Gain", "Gain", 0.f, 1.f, 0.5f);

    juce::AudioParameterBool* enable =
        new juce::AudioParameterBool("Enable", "Enable", true);
};