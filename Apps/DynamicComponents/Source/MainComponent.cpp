#include "MainComponent.h"

namespace GuiApp
{
MainComponent::MainComponent()
{
    addAndMakeVisible(canvas);
    setSize(600, 400);
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    canvas.setBounds(getLocalBounds());
}

} // namespace GuiApp
