#include "PluginProcessor.h"
#include "PluginEditor.h"



TempoSyncPlugin::TempoSyncPlugin()
    : AudioProcessorBase(getDefaultProperties())
{
    addParameter(subDiv);
}

void TempoSyncPlugin::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    transport.prepare(sampleRate, samplesPerBlock);
}

void TempoSyncPlugin::processBlock(juce::AudioBuffer<float>& buffer,
                                   juce::MidiBuffer&)
{
    transport.process(getPlayHead(), buffer.getNumSamples());

    auto currentSubDiv = subDiv->getDivisionPPQ();
    auto halfSubDiv = currentSubDiv / 2.0;

    auto channelData = buffer.getWritePointer(0);

    for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
    {
        auto& sampleData = channelData[sample];
        auto relativePosition = fmod(transport.ppqPositions[sample], currentSubDiv);

        if (transport.info.isPlaying && relativePosition < halfSubDiv)
            sampleData = noise.getNextSample();
        else
            sampleData = 0.f;
    }

    for (int index = 1; index < buffer.getNumChannels(); ++index)
        buffer.copyFrom(index, 0, channelData, buffer.getNumSamples());

    buffer.applyGain(0.03f);
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
