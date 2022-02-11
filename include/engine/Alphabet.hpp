#pragma once
#include "engine/Common.hpp"
#include "engine/Containers.hpp"
#include "engine/Sprite.hpp"
#include "core/Paths.hpp"

namespace Engine
{
    class Alphabet : public Containers::Group
    {
        public:
        static Engine::Sprite* baseSpr; //making this static so more optimizerinos
        Alphabet(const char *text, int x, int y);
        virtual ~Alphabet();
        void screenCenter(Axes axis);
    };
}