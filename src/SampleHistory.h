#pragma once
#include <juce_audio_basics/juce_audio_basics.h>

class SampleHistory
{
public:
  using BufferType = std::vector<double>;
  auto get() const -> const BufferType&;

  void add(const juce::AudioBuffer<float>&);
  void add(const juce::AudioBuffer<double>&);

  void setSampleRate(double);
  auto full() const -> bool;
  void reset();

private:
  auto numSamplesToKeep() const -> size_t;

  BufferType history;
  double sampleRate = 0.0;

  const double lengthInSeconds = 1.0;
};
