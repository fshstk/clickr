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

## If Clickr doesn't appear in your DAW (macOS only)

Clickr may not work properly until you
[de-quarantine](https://eclecticlight.co/2020/11/19/getting-unnotarized-apps-out-of-quarantine/) the
app/plug-in. Apps under quarantine will fail to show up in your DAW's plug-in list and refuse to
open when double-clicked. (You will get an error message along the lines of "Clickr.app can't be
opened because Apple cannot check it for malicious software.")

There are two workarounds:

1. _Standalone only:_ Instead of double-clicking the app, right-click it and select "Open" from the
   contextual menu. This wil allow you to open the app.
2. _All versions:_ Open Terminal and enter the following:

   ```bash
   # Copy-paste the following line:
   $ xattr -d com.apple.quarantine /path/to/Clickr.component
   ```

   where `path/to/Clickr.component` is the full system path to the Clickr app or plug-in. You can
   get this easily by entering the first part of the command (`xattr -d com.apple.quarantine`
   followed by a space) and then dragging the AU/VST/app into yout Terminal window. This will
   automatically enter the correct path for the command.

   After this you will need to trigger a plug-in re-scan and/or restart your DAW.

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
