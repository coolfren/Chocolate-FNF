//#include "engine/Engine.hpp"
#include <SDL2/SDL.h>
#include <thread>
#include <chrono>
#include "engine/Engine.hpp"
#include "states/TestState.hpp"
#define SDL_MAIN_HANDLED

Engine::launchOptions launch = {
    "dog water",
    1280,
    720
};

int main(){
    Engine::initialize(launch, new States::TestState());
    return 0;
}