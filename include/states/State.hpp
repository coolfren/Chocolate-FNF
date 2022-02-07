#pragma once
#include "engine/Common.hpp"
#include "engine/Conductor.hpp"

namespace Engine
{
    class State
    {
        public:
        float lastBeat, lastStep;
        unsigned int curStep, curBeat;
        std::vector<Engine::Basic*> objects;
        State();
        virtual ~State();
        virtual void create();
        virtual void update();
        virtual void add(Engine::Basic* object);
        virtual void remove(Engine::Basic* object);
        void updateBeat();
        void updateCurStep();
        virtual void stepHit();
        virtual void beatHit();
    };
}