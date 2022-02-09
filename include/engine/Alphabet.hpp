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
        Engine::Sprite* baseSpr;
        Alphabet(const char *text);
        virtual ~Alphabet();
    };
}