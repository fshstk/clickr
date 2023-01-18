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
  GIT_TAG        7.0.4)
FetchContent_MakeAvailable(JUCE)
