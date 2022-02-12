#pragma once
#include "engine/Common.hpp"

namespace Engine
{
    class Shape : public Engine::Basic
    {
        SDL_Rect _pos = {0, 0, 0, 0};
        public:
        int x = 0, y = 0, w = 0, h = 0;
        SDL_Color color = {0, 0, 0, 0};
        Shape(int x, int y, int w, int h, SDL_Color color);
        virtual ~Shape();
        virtual void update();
        const SDL_Rect* getPos();
    };
}