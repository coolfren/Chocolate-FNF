#pragma once
// Standard Libary Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <thread>
#include <chrono>
#include <map>
#include <memory>
#include <cmath>
// End of Standard Libary Includes
#include "engine/SDL.hpp"
#ifdef __SWITCH__
#include <switch.h>
#endif
#include <unistd.h>
#include <tinyxml2.h>

namespace Engine
{
    enum class Type
    {
        NOTHING,
        SPRITE,
        TEXT,
        GROUP,
        SHAPE
    };

    class Basic
    {
        private:
        static int globalID;
        public:
        Engine::Type type;
        int ID = 0;

        virtual void update();
    };
};