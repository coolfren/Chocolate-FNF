#include "engine/Text.hpp"

namespace Engine
{
    Text::Text(const char* text, int x, int y, int size, SDL_Color color, const char* fontPath)
    {
        this->text = text;
        this->x = x;
        this->y = y;
        this->size = size;
        this->color = color;
        this->type = Type::TEXT;
        this->fontPath = (char*)fontPath;
        font = TTF_OpenFont(fontPath, size);
        surf = TTF_RenderText_Solid(font, text, color);
        tex = SDL_CreateTextureFromSurface(Engine::renderer, surf);
        this->pos = {x, y, surf->w, surf->h};
    }

    Text::~Text()
    {
        TTF_CloseFont(font);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        if(tex2 != nullptr)
            SDL_DestroyTexture(tex2);
    }

    void Text::update()
    {
        pos = {x, y, surf->w, surf->h};
    }

    void Text::applyOutline(SDL_Color color, int outlineSize)
    {
        auto openFont = TTF_OpenFont(fontPath, size + outlineSize);
        auto tmpSurf = TTF_RenderText_Solid(font, text, color);
        tex2 = SDL_CreateTextureFromSurface(Engine::renderer, tmpSurf);
        SDL_FreeSurface(tmpSurf);
        TTF_CloseFont(openFont);
    }
}