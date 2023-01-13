#include "SampleHistory.h"
#include <cassert>

namespace {
template<typename T>
void addSamples(const juce::AudioBuffer<T>& buf, SampleHistory::BufferType& vec)
{
  assert(buf.getNumChannels() == 2);

  const auto left = buf.getReadPointer(0);
  const auto right = buf.getReadPointer(1);

  for (auto i = 0; i < buf.getNumSamples(); ++i)
    vec.emplace_back(left[i] + right[i]);
}
} // namespace

void SampleHistory::add(const juce::AudioBuffer<float>& b)
{
  addSamples(b, history);
}

void SampleHistory::add(const juce::AudioBuffer<double>& b)
{
  addSamples(b, history);
}

auto SampleHistory::get() const -> const SampleHistory::BufferType&
{
  return history;
}

void SampleHistory::setSampleRate(double newSampleRate)
{
  sampleRate = newSampleRate;
}

auto SampleHistory::full() const -> bool
{
  return history.size() >= numSamplesToKeep();
}

void SampleHistory::reset()
{
  history.clear();
  history.reserve(numSamplesToKeep());
}

auto SampleHistory::numSamplesToKeep() const -> size_t
{
  return static_cast<size_t>(sampleRate * lengthInSeconds);
}
