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

        font = TTF_OpenFont(fontPath, size);
        surf = TTF_RenderText_Solid(font, text, color);
        tex = SDL_CreateTextureFromSurface(Engine::renderer, surf);
        this->pos = {x, y, surf->w, surf->h};
    }

    Text::~Text()
    {
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
    }

    void Text::update()
    {
        pos = {x, y, surf->w, surf->h};
    }

    void Text::applyOutline(SDL_Color color, int outlineSize)
    {

    }
}