#pragma once
#include "engine/Common.hpp"

namespace Engine
{
    class Text : public Basic
    {
        public:
        const char* text;
        int x, y, size;
        SDL_Rect pos;
        TTF_Font* font;
        SDL_Surface* surf;
        SDL_Texture* tex, *tex2;
        char* fontPath;
        SDL_Color color;
        Text(const char* text, int x, int y, int size, SDL_Color color, const char* fontPath);
        ~Text();
        void update();
        void applyOutline(SDL_Color color, int outlineSize);
    };
}