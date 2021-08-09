#include "PluginProcessor.h"
#include "PluginEditor.h"

TempoSyncPlugin::TempoSyncPlugin()
    : AudioProcessorBase(getDefaultProperties())
{
}

void TempoSyncPlugin::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(sampleRate, samplesPerBlock);
}

void TempoSyncPlugin::processBlock(juce::AudioBuffer<float>& buffer,
                                   juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(buffer, midiMessages);
}

juce::AudioProcessorEditor* TempoSyncPlugin::createEditor()
{
    return new TempoSyncEditor(*this);
}

void TempoSyncPlugin::getStateInformation(juce::MemoryBlock& destData)
{
    juce::ignoreUnused(destData);
}

void TempoSyncPlugin::setStateInformation(const void* data, int sizeInBytes)
{
    juce::ignoreUnused(data, sizeInBytes);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TempoSyncPlugin();
}
