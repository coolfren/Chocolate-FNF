#pragma once
extern "C" {
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
}
namespace Engine
{
    extern SDL_Window* window;
    extern SDL_Renderer* renderer;
}