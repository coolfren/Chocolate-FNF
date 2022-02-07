#pragma once
#include "engine/Common.hpp"

namespace Engine
{
    class State
    {
        public:
        std::vector<Engine::Basic*> objects;
        State();
        virtual ~State();
        virtual void create();
        virtual void update();
        virtual void add(Engine::Basic* object);
        virtual void remove(Engine::Basic* object);
    };
}