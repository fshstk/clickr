#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SampleHistory.h"
#include <algorithm>
#include <cassert>
#include <numeric>

namespace {
template<typename T>
void playImpulse(juce::AudioBuffer<T>& audio)
{
  assert(audio.getNumChannels() == 2);
  audio.setSample(0, 0, 1.0);
  audio.setSample(1, 0, 1.0);
}
} // namespace

void PluginProcessor::startMeasurement(const CallbackFunc& callback)
{
  state = State::Started;
  updateDelay = callback;
  history.reset();
}

void PluginProcessor::prepareToPlay(double newSampleRate, int newBufferSize)
{
  juce::ignoreUnused(newBufferSize);
  sampleRate = newSampleRate;
  history.setSampleRate(newSampleRate);
}

void PluginProcessor::processBlock(juce::AudioBuffer<float>& audio, juce::MidiBuffer& midi)
{
  juce::ignoreUnused(midi);
  processAudio(audio);
}

void PluginProcessor::processBlock(juce::AudioBuffer<double>& audio, juce::MidiBuffer& midi)
{
  juce::ignoreUnused(midi);
  processAudio(audio);
}

auto PluginProcessor::createEditor() -> juce::AudioProcessorEditor*
{
  return new PluginEditor(*this);
}

template<typename T>
void PluginProcessor::processAudio(juce::AudioBuffer<T>& audio)
{
  switch (state) {
    using enum PluginProcessor::State;
    case State::Idle:
      audio.clear();
      return;
    case State::Started:
      audio.clear();
      playImpulse(audio);

      // Note: you might think that getting the buffer size is better to do inside prepareToPlay(),
      // or in processBlock() using getBlockSize(). This works for 90% of use cases. However, Logic
      // Pro has an annoying quirk where the buffer size reported by the host to the plug-in is
      // *always* 1024, regardless of the actually chosen buffer size. The only way to guarantee a
      // correct value is by checking the actual number of samples inside the buffer we are given:
      bufferSize = audio.getNumSamples();

      state = State::Recording;
      return;
    case State::Recording:
      history.add(audio);
      audio.clear();

      if (!history.full())
        return;

      calculateDelayAndUpdate();
      state = PluginProcessor::State::Idle;
      history.reset();
      return;
  }
}

void PluginProcessor::calculateDelayAndUpdate() const
{
  const auto& samples = history.get();
  auto differences = std::vector<double>(samples.size());
  std::adjacent_difference(samples.cbegin(),
                           samples.cend(),
                           differences.begin(),
                           [](auto a, auto b) { return std::abs(a - b); });

  const auto largestElement = std::max_element(differences.cbegin(), differences.cend());
  const auto index = std::distance(differences.cbegin(), largestElement);

  const auto delayInSamples = static_cast<int>(index) - bufferSize;
  const auto delayInMilliseconds = delayInSamples * 1e3 / sampleRate;

  assert(updateDelay);
  updateDelay(delayInSamples, delayInMilliseconds);
}
