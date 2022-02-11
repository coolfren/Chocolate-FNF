#pragma once
// Standard Libary Includes
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <functional>
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

#define screenCenterX (1280 / 2)
#define screenCenterY (720 / 2)

namespace Engine
{
    enum class Type
    {
        NOTHING,
        SPRITE,
        TEXT,
        ALPHABET,
        GROUP,
        SHAPE,
        AUDIO
    };

    enum class Axes
    {
        X,
        Y,
        XY
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