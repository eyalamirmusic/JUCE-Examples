#pragma once

#include "PluginProcessor.h"

class TempoSyncEditor : public juce::AudioProcessorEditor
{
public:
    explicit TempoSyncEditor(TempoSyncPlugin& processorToUse)
        : juce::AudioProcessorEditor(processorToUse)
        , genericEditor(processorToUse)
    {
        addAndMakeVisible(genericEditor);
        setSize(400, 300);
    }

    void resized() override { genericEditor.setBounds(getLocalBounds()); }

    juce::GenericAudioProcessorEditor genericEditor;
};
