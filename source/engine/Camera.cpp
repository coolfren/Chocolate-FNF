#include "engine/Camera.hpp"

namespace Engine
{
    Camera::Camera()
    {
    }
    
    Camera::~Camera()
    {
        
    }
    
    void Camera::update()
    {
    }
    
    void Camera::setPosition(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
}