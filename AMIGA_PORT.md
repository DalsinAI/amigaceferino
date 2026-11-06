Don Ceferino Hazaña 0.97.8 for AmigaOS 3.x
==========================================

Don Ceferino Hazaña (Hugo Ruscitti, Losers Juegos), the Pang-style action
game: aliens have landed on Don Ceferino's farm, and the old gaucho shoots
the bouncing balls apart, smaller and smaller, level after level, with
ladders, blocks, bonuses and a story told in pictures. For AmigaOS 3.x on
a 68040 or 68060 with an FPU and an RTG screen, on OpenGPU's SDL 1.2
(sdl12-compat).

Base: ceferino_0.97.8+svn37.orig.tar.gz from Debian (sha256
b52ccce6051e78d8c368d76335d027442162e6bac44709ef06627a8fa8cb2fc6); Debian
has no patches for it. Branch team2/ceferino-amiga.

Status: plays in the lab (Instance-45 on GFOpenUp 0.8.19, 6 November
2026): the intro, the menu, New Game, level 1 (Ceferino moved and
firing, the balls bouncing, the time and score), Escape to the menu, and
Exit back to the Shell, with the sounds, music, intro and presentation
loading without an error. Screenshots from that run are in
amiga/screenshots (ceferino-intro.png, ceferino-menu.png,
ceferino-level1.png). The lab is muted, so the music and sounds were not
heard there.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later (LIBS:OpenGPU/SDL2.module). Everything else is
  in the program.


How to play
-----------

Open the Ceferino icon, or run Ceferino from a Shell. It opens a 640x480
window. The cursor keys and Return choose in the menu. In the game the
cursor keys move Don Ceferino and climb, X fires, Z or C sweeps, F
switches to the full screen, Escape is the menu and Q quits at once. The
game is in English and Spanish as upstream made it (its menus and story
are pictures). ReadMe-upstream in the drawer is upstream's README. The
pictures, sounds, music and levels are in the drawer's data/; the scores
and saved game are kept in user/.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers, the OpenGPU kit and
the Team's static libpng, libjpeg and zlib (see the Makefile's head). The
drawer is dist/Ceferino (and dist/Ceferino.info).


What was changed
----------------

- src/audio.h: room for the 12 sounds the game loads (upstream's array
  held 11; on AmigaOS the twelfth wrote over the next name and the sounds
  were switched off).
- src/mundo.cc: the window title in Latin-1, as Intuition shows it.
- src/int.h: no gettext.
- $HOME is the drawer's user/ (amiga/amiga_env.c, -Wl,--wrap=getenv), for
  the scores, settings and saved game.
- amiga/Makefile.amigaos builds src/Makefile.am's ceferino (not the editor
  or the setup program), the data at PROGDIR:data. amiga/amiga_prefix.hpp:
  the C++ streams first in every file.
- No SDL_image or SDL_mixer 1.2 for OpenGPU's SDL 1.2: the Team's
  amiga/sdl_image_lite.c (PNG on libpng, JPEG on libjpeg), from the Penguin
  Command port, and amiga/sdl_mixer_lite.c (WAV, with libmikmod 3.3.16 for
  the music: amiga/libmikmod, its player, XM loader and no-sound driver, at
  most 16 voices), from the Critical Mass port.
- amiga/stack.c: 256 KB of stack.


Licences
--------

Don Ceferino Hazaña, its pictures, sounds and music: GPL 2 or later
(COPYING.txt; AUTHORS in the source names Walter Velazquez for the
pictures and story and Javier Da Silva for the music). libmikmod: LGPL 2
or later (COPYING-libmikmod.txt). The Amiga files (amiga/): the AmiCradle
Team, GPL 2 or later, except the mixer, which comes from the Team's Wizznic
port and is GPL 3 or later, so the program as built here is GPL 3 or
later; the icon is upstream's data/ima/icono.png.
