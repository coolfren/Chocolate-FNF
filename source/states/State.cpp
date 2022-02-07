#include "states/State.hpp"

namespace Engine
{
    State::State(){}

    State::~State()
    {
        for(auto& object : objects)
        {
            delete object;
        }
    }

    void State::create(){}
    void State::update(){
        for(auto& object : objects){
            object->update();
        }
    }
    void State::add(Engine::Basic* object){
        objects.push_back(object);
    }
    
    void State::remove(Basic* object)
    {
        auto found = std::find(objects.begin(), objects.end(), object);
        if(found != objects.end())
        {
            objects.erase(found);
        }
    }
}