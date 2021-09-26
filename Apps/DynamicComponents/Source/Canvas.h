#pragma once

#include "Widget.h"

namespace GuiApp
{
struct Canvas : juce::Component
{
    Canvas() {}

    void mouseDown(const juce::MouseEvent& event) override
    {
        clearHighlighted();

        objects.emplace_back(std::make_unique<Widget>());
        auto& newComp = *objects.back();
        addAndMakeVisible(newComp);
        juce::Rectangle<int> bounds {0, 0, 50, 50};
        bounds.setCentre(event.getPosition());
        newComp.setBounds(bounds);
        newComp.setHighlight(true);
        newComp.onClick = [&] { clearHighlighted(); };
    }

    void clearHighlighted()
    {
        for (auto& obj: objects)
            obj->setHighlight(false);
    }

    std::vector<std::unique_ptr<Widget>> objects;
};
} // namespace GuiApp