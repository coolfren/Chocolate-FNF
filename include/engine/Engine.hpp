#pragma once
#include "engine/Common.hpp"
#include "engine/Sprite.hpp"
#include "engine/Text.hpp"
#include "engine/Containers.hpp"
#include "core/Paths.hpp"
#include "states/State.hpp"

namespace Engine
{
    /**
     * @brief This struct contains the launch option parameters.
     * @param title The title of the window.
     * @param width The width of the window.
     * @param height The height of the window.
     */
    struct launchOptions
    {
        const char* title;
        const int width;
        const int height;
    };
    
    extern State* curState;
    void switchState(State* state);
    void render(Engine::Basic* object);
    // This will initialize the main SDL window.
    extern void initialize(Engine::launchOptions launch, Engine::State* beginState);
    void destruct();
}