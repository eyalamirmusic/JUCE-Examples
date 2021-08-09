#pragma once

#include "PluginProcessor.h"

struct AtomicLabel
    : juce::Component
    , juce::Timer
{
    AtomicLabel(std::atomic<double>& valueToUse)
        : value(valueToUse)
    {
        startTimerHz(60);
        addAndMakeVisible(label);
    }

    void resized() override { label.setBounds(getLocalBounds()); }

    void timerCallback() override
    {
        label.setText(juce::String(value.load()), juce::dontSendNotification);
    }

    juce::Label label;
    std::atomic<double>& value;
};

class TempoSyncEditor : public juce::AudioProcessorEditor
{
public:
    explicit TempoSyncEditor(TempoSyncPlugin& processorToUse)
        : juce::AudioProcessorEditor(processorToUse)
        , positionLabel(processorToUse.currentPosition)

    {
        addAndMakeVisible(positionLabel);
        setSize(400, 300);
    }

    void resized() override { positionLabel.setBounds(getLocalBounds()); }

    AtomicLabel positionLabel;
};
