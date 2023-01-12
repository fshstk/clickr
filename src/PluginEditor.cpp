#include "PluginEditor.h"
#include "PluginProcessor.h"

PluginEditor::PluginEditor(PluginProcessor& p)
  : AudioProcessorEditor(&p)
{
  setSize(400, 300);
  addAndMakeVisible(button);

  button.setButtonText("Press to measure latency\nbetween output and input.");

  button.onClick = [&]() {
    button.setEnabled(false);
    button.setButtonText("Measuring...");

    p.startMeasurement([&](int latencySamples, double latencyMilliseconds) {
      juce::MessageManagerLock lock;
      button.setButtonText(("Latency: " + juce::String{ latencySamples } + " samples") +
                           (" (~" + juce::String{ latencyMilliseconds, 1 } + " ms)"));
      button.setEnabled(true);
    });
  };
}

void PluginEditor::paint(juce::Graphics& g)
{
  const auto link = "github.com/fshstk/clickr";
  const auto version = PLUGIN_VERSION;
  const auto textArea = getLocalBounds().removeFromBottom(50).reduced(2);

  g.setColour(juce::Colours::white);
  g.drawText(link, textArea, juce::Justification::centredBottom);
  g.drawText(version, textArea, juce::Justification::bottomRight);
}

void PluginEditor::resized()
{
  button.setBounds(getLocalBounds().reduced(50));
}
