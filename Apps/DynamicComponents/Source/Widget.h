#pragma once

#include "CommonHeader.h"

namespace GuiApp
{
struct Widget : juce::Component
{
    Widget() { setWantsKeyboardFocus(true); }

    bool keyPressed(const juce::KeyPress& key) override
    {
        keyText = key.getTextDescription();
        repaint();

        return true;
    }

    void paint(Graphics& g) override
    {
        g.fillAll(getColor());
        g.setColour(juce::Colours::white);
        g.drawText(keyText, getLocalBounds(), juce::Justification::centred);
    }

    void mouseDown(const juce::MouseEvent&) override
    {
        onClick();
        setHighlight(true);
    }

    juce::Colour getColor() const
    {
        if (highlighted)
            return juce::Colours::red.withAlpha(0.7f);

        return juce::Colours::blue.withAlpha(0.7f);
    }

    void focusLost(FocusChangeType) override { keyText = ""; }

    void setHighlight(bool shouldHighlight)
    {
        if (shouldHighlight)
            grabKeyboardFocus();

        highlighted = shouldHighlight;
        repaint();
    }

    String keyText;
    std::function<void()> onClick = [] {};
    bool highlighted = false;
};
} // namespace GuiApp