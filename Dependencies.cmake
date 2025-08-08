################################################################################
# FetchContent
################################################################################

include(FetchContent)

################################################################################
# JUCE - AU/VST plugin framework
################################################################################

FetchContent_Declare(
  JUCE
  GIT_REPOSITORY https://github.com/juce-framework/JUCE
  GIT_TAG        8.0.8)
FetchContent_MakeAvailable(JUCE)
