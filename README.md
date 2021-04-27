# Hands-Down
Various implementations of the [Hands
Down](https://sites.google.com/alanreiser.com/handsdown) (Reference) keyboard
layout.  This layout was designed by R. Alan Reiser and is under a [CC BY-SA 3.0 license](https://creativecommons.org/licenses/by-sa/3.0/).

From the Hands-Down website:

> Legal Blurb: Hands Down when used to refer to a keyboard or a keyboard layout (the specific arrangement of keys and any variation that substantially resembles the Hands Down layouts described herein) are copyright ©2020 by R. Alan Reiser, under a Creative Commons Attribution-ShareAlike 3.0 United States (CC BY-SA 3.0 US) license. You are free to use, distribute, and modify, so long as distributed or derived works explicitly state their derivation and give appropriate attribution, and redistribute with the same license. There are no warranties, express or implied, and I hereby disclaim all implied warranties, including any warranty of merchantability and warranty of fitness for a particular purpose, or possible harm or loss to persons or equipment. Nobody gets to make money off this work. Not even me. It's free, because it should be free. That is all.

Alan's implemenation is specifically for a [Kyria](https://splitkb.com/)
keyboard and uses CAGS [home-row](https://precondition.github.io/home-row-mods)
modifiers.  He has a link to the QMK source files and a MacOS Keyboard Layout bundle in his Downloads section.

I am currently using GACS.  Kmonad doesn't support chords directly, so I don't
have any of Alan's chords in kmonad.  The layers are influenced by Alan's, the
layers in the
[Miryoku](https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org)
layout and some of my own ideas.  A conventionally-shaped keyboard also
pretty-much eliminates thumb layer control.  The standalone numpad is currently
disabled (use the layer one).


There are reference, pg and py implementations for kmonad and MKLC. 
The kmonad pg version has symbols and numbers modified to match [Programmer's Dvorak](https://www.kaufmann.no/roland/dvorak/).  The py version is more like the Workman-P numbers/symbols (regular placement but shift-swapped), however [/{ and ]/} haven't been swapped and :/; have.  That makes it better for Python.
I'm not following Alan's layers in my QMK source, but I'd call it a work-in-progress, so they may converge.  I like what he now has up on his website a lot more than what was in the original QMK source he had linked when I first started with Hands Down.

Implementations:
   * kmonad config for a 104-key ANSI Dvorak keyboard with 3 CTRL keys, capslock and an ESC tap-mod on the home CTRL. (previous version of HD ~2021-04-10)
   * Microsoft Keyboard Layout Creator (no tap mods) (HD # ordering, :/; swap)
   * Iris QMK source (123... # ordering, :/; swap)

