#include "PluginProcessor.h"

constexpr int numParams = 10000;
constexpr bool useEditor = false;

MaxParamsProcessor::MaxParamsProcessor()
    : AudioProcessorBase(getDefaultProperties())
{
    for (int index = 0; index < numParams; ++index)
    {
        auto name = juce::String(index);
        addParameter(new juce::AudioParameterBool(name, name, false));
    }
}

void MaxParamsProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                      juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(midiMessages);
    buffer.clear();
}
juce::AudioProcessorEditor* MaxParamsProcessor::createEditor()
{
    if (useEditor)
        return AudioProcessorBase::createEditor();
    else
       return nullptr;
}

bool MaxParamsProcessor::hasEditor() const
{
    return useEditor;
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MaxParamsProcessor();
}
