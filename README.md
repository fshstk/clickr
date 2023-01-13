# Clickr

![CI build](https://github.com/fshstk/clickr/actions/workflows/build-release.yml/badge.svg)
![CI lint](https://github.com/fshstk/clickr/actions/workflows/lint.yml/badge.svg)

## What is it?

Clickr is a free plug-in that measures the round-trip latency between its audio output and input.
It does this by sending an impulse out and seeing how fast it comes back. Simple really.

Of course, for it to make sense you will have to connect the inputs and outputs via some signal path
that you want to measure. Usually this would be via physical audio ports in order to measure the
latency through some piece of outboard gear, but it works just the same with virtual routing in e.g.
a DAW.

Clickr is available for Windows/Mac/Linux as a VST3 plug-in and a Standalone app. An AU plug-in is
additionally available for Mac.

## Get it

Download the latest release [here](https://github.com/fshstk/clickr/releases/latest).
Using it should be pretty self-explanatory. There's only one button.

## Buy me a Coffee/Beer

Clickr is free and open-source. If it helps you in some way, that's fantastic.
I don't expect anything in return, but you can feel free to drop a tip.

[![Support me on Ko-fi](https://storage.ko-fi.com/cdn/brandasset/kofi_button_stroke.png)](https://ko-fi.com/fshstk)

## Feedback

This is still very much in development. If you have suggestions, or if Clickr doesn't work for your
particular use case, please [open an issue](https://github.com/fshstk/clickr/issues).

## Building from Source

If you want to attempt this, you should first be familiar with CMake and have a working
git/cmake/compiler set-up. Building is pretty straightforward as the required project dependencies
are automatically downloaded and built at configure-time.

If you are using Linux, you may need some basic dev libraries installed. Please see the
[CI workflow](.github/workflows/build-release.yml) for a complete list (for Ubuntu).

## License

This project is licensed under the GNU General Public License version 3 (GPLv3).
