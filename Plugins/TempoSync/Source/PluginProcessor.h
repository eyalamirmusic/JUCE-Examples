#pragma once

#include <shared_plugin_helpers/shared_plugin_helpers.h>

//Inhereting from AudioProcessorBase, which is just inhereting from juce::AudioProcessor
//And adding some default implementations

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

    std::atomic<double> currentPosition {0};
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TempoSyncPlugin)
};
