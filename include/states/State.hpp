#pragma once
#include "engine/Common.hpp"
#include "engine/Conductor.hpp"

namespace Engine
{
    class threadManager
    {
        std::map<const char*, std::thread*> _threads;
        public:
        void add(const char* name, std::thread& thread);
        void add(const char* name, std::function<void()> func);
        void remove(const char* name);
        std::thread& operator[](const char* name);
    };

    class State
    {
        public:
        float lastBeat, lastStep;
        unsigned int curStep, curBeat;
        std::vector<Engine::Basic*> objects;
        threadManager threads;
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