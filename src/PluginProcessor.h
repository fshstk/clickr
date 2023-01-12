#pragma once
#include "SampleHistory.h"
#include "StereoPluginBase.h"

class PluginProcessor : public StereoPluginBase
{
public:
  using CallbackFunc = std::function<void(int, double)>;

  enum class State
  {
    Idle,
    Started,
    Recording,
  };

  void startMeasurement(const CallbackFunc& callback);

  void prepareToPlay(double sampleRate, int bufferSize) override;
  void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
  void processBlock(juce::AudioBuffer<double>&, juce::MidiBuffer&) override;

  // Callers are expected to take ownership of the returned object.
  auto createEditor() -> juce::AudioProcessorEditor* override;

private:
  template<typename T>
  void processAudio(juce::AudioBuffer<T>&);

  void calculateDelayAndUpdate() const;

  State state = State::Idle;
  SampleHistory history;
  CallbackFunc updateDelay;

  int bufferSize;
  double sampleRate;
};
