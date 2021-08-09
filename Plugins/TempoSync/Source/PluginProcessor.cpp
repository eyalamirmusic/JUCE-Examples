#include "PluginProcessor.h"
#include "PluginEditor.h"

TempoSyncPlugin::TempoSyncPlugin()
    : AudioProcessorBase(getDefaultProperties())
{
}

void TempoSyncPlugin::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    transport.prepare(sampleRate, samplesPerBlock);
}

void TempoSyncPlugin::processBlock(juce::AudioBuffer<float>& buffer,
                                   juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(buffer, midiMessages);
    transport.process(getPlayHead(), buffer.getNumSamples());

    for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
    {
        auto relativePosition = fmod(transport.ppqPositions[sample], 1.0);

        float sampleVal = 0.f;

        if (transport.info.isPlaying && relativePosition < 0.5)
            sampleVal = noise.getNextSample();

        for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
            buffer.setSample(channel, sample, sampleVal);
    }

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
