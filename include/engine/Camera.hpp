#pragma once
#include "engine/Common.hpp"
namespace Engine
{
    class Camera : public Basic
    {
        private:
        int internalX = 0, internalY = 0;
        public:
        Camera();
        ~Camera();
        int x = 0, y = 0;
        float lerp = 0.0f, zoom = 1.0f;
        void update();
        void setPosition(int x, int y);
    };
}