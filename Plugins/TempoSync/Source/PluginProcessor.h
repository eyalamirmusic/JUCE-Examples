#pragma once

#include <shared_plugin_helpers/shared_plugin_helpers.h>
#include <shared_processing_code/shared_processing_code.h>
#include "Transport.h"

//Inhereting from AudioProcessorBase, which is just inhereting from juce::AudioProcessor
//And adding some default implementations

struct SubdivisionParameter : juce::AudioParameterChoice
{
    SubdivisionParameter()
        : juce::AudioParameterChoice("Subdivision", "Subdivision", getChoices(), 3)
    {
    }

    double getDivisionPPQ()
    {
        switch (getIndex())
        {
            case 0:
                return 4.0;

            case 1:
                return 2.0;

            case 2:
                return 1.0;

            case 3:
                return 0.5;

            case 4:
                return 0.25;
        }

        return 1.0;
    }

    juce::StringArray getChoices() { return {"1/1", "1/2", "1/4", "1/8", "1/16"}; }
};

class TempoSyncPlugin : public AudioProcessorBase
{
public:
    TempoSyncPlugin();

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;

    void processBlock(juce::AudioBuffer<float>& buffer,
                      juce::MidiBuffer& midiMessages) override;

    juce::AudioProcessorEditor* createEditor() override;

    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    Transport transport;
    WhiteNoise::Oscillator noise;

    SubdivisionParameter* subDiv = new SubdivisionParameter();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TempoSyncPlugin)
};
