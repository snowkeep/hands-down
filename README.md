# Hands-Down
Various implementations of the [Hands
Down](https://sites.google.com/alanreiser.com/handsdown) (Reference) keyboard
layout.  This layout was designed by R. Alan Reiser and is under a [CC BY-SA 3.0 license](https://creativecommons.org/licenses/by-sa/3.0/).

From the Hands-Down website:

> Legal Blurb: Hands Down when used to refer to a keyboard or a keyboard layout (the specific arrangement of keys and any variation that substantially resembles the Hands Down layouts described herein) are copyright ©2020 by R. Alan Reiser, under a Creative Commons Attribution-ShareAlike 3.0 United States (CC BY-SA 3.0 US) license. You are free to use, distribute, and modify, so long as distributed or derived works explicitly state their derivation and give appropriate attribution, and redistribute with the same license. There are no warranties, express or implied, and I hereby disclaim all implied warranties, including any warranty of merchantability and warranty of fitness for a particular purpose, or possible harm or loss to persons or equipment. Nobody gets to make money off this work. Not even me. It's free, because it should be free. That is all.

Alen's implemenation is specifically for a [Kyria](https://splitkb.com/)
keyboard and uses CAGS [home-row](https://precondition.github.io/home-row-mods)
modifiers.

I am currently using GACS.  Kmonad doesn't support chords directly, so I don't have any of Alan's chords in kmonad.  The layers are
influenced by Alan's, the layers in the [Miryoku](https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org) layout and some of my own ideas.  A conventionally-shared keyboard also pretty-much eliminates thumb layer control.  The standalone numpad is currently disabled (use the layer one).  I am very unhappy with the current symbol layer, so expect that to change.

Implementations:
   * kmonad config for a 104-key ANSI Dvorak keyboard with 3 CTRL keys and no capslock.
   * kmonad config for the same keyboard that also modifies symbols and numbers to match [Programmer's Dvorak](https://www.kaufmann.no/roland/dvorak/)

Coming soon:
   * [Iris] keyboard files.

Thoughts
   * I don't like the symbol layer - considering splitting enclosures and the rest of the symbols - it would work on the Iris, but not a conventional keyboard
   * Miryoku's symbol layer is the shift-numbers (conventional mapping) with [] added on the number level - it's a pretty good idea
   * Alan split out enclosures, but the rest of the symbols seem pretty random - I don't see a logical pattern.
   * should the numpad be completely reworked?  There's some ideas [here](https://geekhack.org/index.php?topic=72149.0), but they admit the studies were all from dialing phone numbers.  Should hex symbols be added?  Pure entry, w/ $ and %, or stay with basic calculator layout?

Concerns
   * Programmer Dvorak number ordering is a PITA for desktop switching on tiling window managers.  Maybe it will be easier once I'm used to it?  But that may be the deal-breaker to keep me with a conventional number row - this will also probably stop me from moving to a Kyria.  
