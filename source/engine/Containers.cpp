#include "engine/Containers.hpp"

namespace Containers
{
    Group::Group(){
        type = Engine::Type::GROUP;
    }
    Group::~Group(){
        for(auto& object : objects){
            delete object;
        }
    }
    void Group::update(){
        for(auto& object : objects){
            object->update();
        }        
    }
    
    void Group::add(Basic* object)
    {
        objects.push_back(object);
    }

    void Group::remove(Basic* object)
    {
        auto found = std::find(objects.begin(), objects.end(), object);
        if(found != objects.end())
        {
            objects.erase(found);
        }
    }
    
    void Group::remove(int index)
    {
        objects.erase(objects.begin() + index);
    }

    int Group::size(){
        return objects.size();
    }
    inline Engine::Basic* &Group::operator[](int index)
    {
        return objects[index];
    }
} // namespace containers