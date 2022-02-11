#pragma once
#include "states/State.hpp"
#include "engine/Sprite.hpp"
#include "engine/Text.hpp"
#include "core/Paths.hpp"
#include "engine/Containers.hpp"
#include "engine/Alphabet.hpp"
#include "audio/Audio.hpp"

namespace States
{
    class TestState : public Engine::State
    {
        public:
        TestState(){};
        ~TestState(){};
        void create();
        Containers::Group* alphabetGroup;
        virtual void beatHit();
        virtual void createCoolText(const std::vector<std::string> funny);
        virtual void createMoreCoolText(const std::string& funny);
        virtual void removeText();
    };
}