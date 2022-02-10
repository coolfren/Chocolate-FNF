#include "states/TestState.hpp"

namespace States
{
    void TestState::create(){
        //Containers::Group *group = new Containers::Group();
        // Engine::Sprite* sprite = new Engine::Sprite(getImage("boyfriend"));
        // sprite->parseSparrowSpritesheet("romfs/images/boyfriend.xml", 24, "BF idle dance", false);
        // add(sprite);
        // //threads.add("spritesheetParse", [&sprite](){});
        // //group->add(sprite);
        // Engine::Alphabet* te = new Engine::Alphabet("C PLUS PLUS IS BASED AND REDPILLED", 0, 0);
        // add(te);
        
        // Engine::Alphabet* texl = new Engine::Alphabet("MML NEEDS TO BE DELETED", 85, 200);
        // add(texl);
        Audio::Audio* audio = new Audio::Audio("romfs/songs/menu.ogg", true);
        audio->playMusic(true);
        //Engine::Text* text = new Engine::Text("TEST 123 STUFF", 0, 400, 78, {0, 0, 0, 255}, getFont("fnf"));
        //group->add(text);
        //add(group);
        Music::Conductor::changeBPM(102);
        threads.add("musicPos", [](){
            while(true){
                if(!Mix_PlayingMusic())
                    break;
                //set Music::Conductor::songPosition to the current position of the song
                Music::Conductor::songPosition++;
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });
    }
    void TestState::createCoolText(const std::string& funny){
        static int i = 0;
        i++;
        Engine::Alphabet* s = new Engine::Alphabet(funny.c_str(), 0, i * 100);
        add(s);
    }
    void TestState::beatHit(){
        switch(curBeat){
             case 1: createCoolText("YOUR MOM PRESENTS"); break;
             case 2: break;
             case 3: createCoolText("FUNDED BY THE CIA"); break;
         }
        std::cout << ":happyman: " << curBeat << std::endl;
    }
}