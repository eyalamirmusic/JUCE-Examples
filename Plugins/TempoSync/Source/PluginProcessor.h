#pragma once

#include <shared_plugin_helpers/shared_plugin_helpers.h>
#include <shared_processing_code/shared_processing_code.h>
#include "Transport.h"
#include "SubdivisionParam.h"

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
