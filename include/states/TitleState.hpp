#pragma once
#include "states/State.hpp"
#include "engine/Sprite.hpp"
#include "engine/Text.hpp"
#include "core/Paths.hpp"
#include "engine/Containers.hpp"
#include "engine/Alphabet.hpp"
#include "audio/Audio.hpp"
#include "engine/Shape.hpp"
#include "engine/Engine.hpp"
#include "states/MainMenuState.hpp"

namespace States
{
    class TitleState : public virtual Engine::State
    {
        public:
        bool f = false, u = false;
        Engine::Sprite* logo, *gf, *enter;
        Engine::Shape* white;
        Audio::Audio* confirm;
        bool skippedIntro = false;
        TitleState(){};
        ~TitleState(){};
        void create() override;
        void update() override;
        Containers::Group* alphabetGroup;
        void beatHit() override;
        void createCoolText(const std::vector<std::string> funny);
        void createMoreCoolText(const std::string& funny);
        void removeText();
        void skipIntro();
    };
}