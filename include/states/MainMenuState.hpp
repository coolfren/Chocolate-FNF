#pragma once
#include "engine/Common.hpp"
#include "states/State.hpp"
#include "engine/Sprite.hpp"
#include "audio/Audio.hpp"
#include "core/Paths.hpp"
#include "engine/Containers.hpp"
#include "engine/Text.hpp"
#include "states/PlayState.hpp"
#include "engine/Engine.hpp"

namespace States
{
    class MainMenuState : public virtual Engine::State
    {
        public:
        Containers::Group* theOptions;
        Audio::Audio* scroll, *confirm;
        int selected = 0;
        MainMenuState(){};
        ~MainMenuState(){};
        void create() override;
        void update() override;
        void switchMenu(int index);
    };
}