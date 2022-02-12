#pragma once
#include "engine/Common.hpp"
#include "states/State.hpp"
#include "engine/Sprite.hpp"
#include "audio/Audio.hpp"
#include "core/Paths.hpp"
#include "engine/Containers.hpp"

namespace States
{
    class PlayState : public Engine::State
    {
    private:
    public:
        Engine::Sprite *bf, *gf, *dad;
        PlayState(){};
        ~PlayState(){};
        void create() override;
        void update() override;
    };
}