//#include "engine/Engine.hpp"
#include <SDL2/SDL.h>
#include "engine/Engine.hpp"
#include "states/TitleState.hpp"
#include "states/MainMenuState.hpp"
#include "states/PlayState.hpp"
#define SDL_MAIN_HANDLED

Engine::launchOptions launch = {
    "dog water",
    1280,
    720
};

int main(){
    Engine::initialize(launch, new States::MainMenuState());
    return 0;
}