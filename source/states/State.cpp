#include "states/State.hpp"

namespace Engine
{
    State::State(){
        lastBeat = 0;
        lastStep = 0;
        curStep = 0;
        curBeat = 0;
    }

    State::~State()
    {
        for(auto& object : objects)
        {
            delete object;
        }
    }

    void State::create(){}
    void State::update(){
        unsigned int oldStep = curStep;
        updateCurStep();
        updateBeat();
        if(oldStep != curStep && curStep > 0)
            stepHit();
        
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

    void State::updateBeat()
    {
        curBeat = floor(curStep / 4);
    }

    void State::updateCurStep()
    {
        curStep = std::floor((Music::Conductor::songPosition) / Music::Conductor::stepCrochet);
    }

    void State::stepHit()
    {
        if(curStep % 4 == 0)
            beatHit();
    }

    void State::beatHit(){}

    void threadManager::add(const char* name, std::thread& thread)
    {
        _threads[name] = &thread;
        thread.detach();
    }
    
    void threadManager::add(const char* name, std::function<void()> func){
        std::thread _tempThread(func);
        _threads[name] = &_tempThread;
        _tempThread.detach();
    }

    void threadManager::remove(const char* name)
    {
        _threads.erase(name);
    }

    std::thread& threadManager::operator[](const char* name){
        return *_threads[name];
    }
}