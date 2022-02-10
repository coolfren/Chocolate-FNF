# FNF SDL2
This is a rewrite of Friday Night Funkin' to C++ and just purely SDL2.
## Platforms
as of now, this supports:
* Desktop
* Switch
* Really anything that supports SDL2
## What is currently implemented
* Sprites
* Sparrow parser
* Alphabet
* Conductors
* States
* Groups
## What is planned
* Gameplay
* Easy input
* Chart parser
* Saves
## What I will not add
* Scripting (like implementing luajit, if you wish to somehow make it work be my guest)
* Charter (if you make one that works hit me with a PR!)
## Building
### Desktop
Windows is not supported at the moment.

You will need Clang or GCC (either will work but I prefer Clang)

Install these dependencies:
* SDL2
* SDL_Image
* SDL_TTF
* SDL_Mixer
* tinyxml2

run ./make_pc.sh and it will output ./sdlproj
### Switch
You will need devkitA64 for this.

First install the portlibs with (dkp-)pacman -S switch-portlibs

just run make and it will output an NRO
