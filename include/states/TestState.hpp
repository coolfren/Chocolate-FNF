#pragma once
#include "states/State.hpp"
#include "engine/Sprite.hpp"
#include "engine/Text.hpp"
#include "core/Paths.hpp"
#include "engine/Containers.hpp"

namespace States
{
    class TestState : public Engine::State
    {
        public:
        TestState(){};
        ~TestState(){};
        void create();
        virtual void beatHit();
    };
}