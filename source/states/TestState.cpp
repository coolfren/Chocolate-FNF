#include "states/TestState.hpp"

namespace States
{
    void TestState::create(){
        //Containers::Group *group = new Containers::Group();
        Engine::Sprite* sprite = new Engine::Sprite(getImage("boyfriend"));
        sprite->parseSparrowSpritesheet("romfs/images/boyfriend.xml", 24, "BF idle dance");
        add(sprite);
        //threads.add("spritesheetParse", [&sprite](){});
        //group->add(sprite);
        Engine::Alphabet* te = new Engine::Alphabet("C PLUS PLUS IS BASED AND REDPILLED");
        add(te);
        Audio::Audio* audio = new Audio::Audio("romfs/audio/menu.ogg", true);
        audio->playMusic(true);
        //Engine::Text* text = new Engine::Text("TEST 123 STUFF", 0, 400, 78, {0, 0, 0, 255}, getFont("fnf"));
        //group->add(text);
        //add(group);
        Music::Conductor::changeBPM(102);
        threads.add("musicPos", [](){
            while(true){
                //set Music::Conductor::songPosition to the current position of the song
                Music::Conductor::songPosition++;
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });
    }
    void TestState::createCoolText(const std::string& funny){
        static Engine::Text* text = new Engine::Text(funny.c_str(), 0, 400, 78, {0, 0, 0, 255}, getFont("fnf"));
        if(text != nullptr){
            remove(text);
            delete text;
        }
        else
            add(text);
    }
    void TestState::beatHit(){
        // switch(curBeat){
        //     case 1: createCoolText("your mom presents"); break;
        //     case 2: createCoolText(""); break;
        //     case 3: createCoolText("i am breaking your neck"); break;
        // }
        //std::cout << ":happyman: " << curBeat << std::endl;
    }
}