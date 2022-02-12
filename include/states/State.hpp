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
        friend class State;
    };

    class State
    {
        public:
        bool keysPressed[256];
        int keysJustPressed[256];
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

        virtual void keyEvent(SDL_Keycode key, bool isPressed);
        virtual void keyRelease(SDL_Keycode key);
        virtual void stepHit();
        virtual void beatHit();
    };
}