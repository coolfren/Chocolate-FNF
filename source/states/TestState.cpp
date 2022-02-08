#include "states/TestState.hpp"

namespace States
{
    void TestState::create(){
        Containers::Group *group = new Containers::Group();
        Engine::Sprite* sprite = new Engine::Sprite(getImage("boyfriend"));
        sprite->parseSparrowSpritesheet("romfs/images/boyfriend.xml", 24, "BF idle dance");
        //threads.add("spritesheetParse", [&sprite](){});
        group->add(sprite);

        Engine::Text* text = new Engine::Text("TEST 123 STUFF", 0, 400, 78, {0, 0, 0, 255}, getFont("fnf"));
        group->add(text);
        add(group);
        Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
        Mix_Chunk *music = Mix_LoadWAV("romfs/songs/menu.wav");
        if(music == nullptr){
            printf("Mix_LoadMUS: %s\n", Mix_GetError());
            return;
        }
        Mix_PlayChannel(-1, music, 0);
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