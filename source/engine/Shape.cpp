#include "engine/Shape.hpp"

namespace Engine
{
    Shape::Shape(int x, int y, int w, int h, SDL_Color color)
    {
        type = Type::SHAPE;
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->color = color;
        this->_pos = {x, y, w, h};
    }

    Shape::~Shape()
    {
    }

    void Shape::update()
    {
        _pos = {x, y, w, h};
    }

    const SDL_Rect* Shape::getPos()
    {
        return &_pos;
    }
}