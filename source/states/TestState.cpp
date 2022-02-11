#include "states/TestState.hpp"

namespace States
{
    void TestState::create(){
        alphabetGroup = new Containers::Group();
        add(alphabetGroup);
        Audio::Audio* audio = new Audio::Audio("romfs/songs/menu.ogg", true);
        audio->playMusic(true);
        Music::Conductor::changeBPM(102);
        threads.add("musicPos", [](){
            while(true){
                if(!Mix_PlayingMusic())
                    continue;
                Music::Conductor::songPosition++;
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });
    }
    void TestState::createCoolText(const std::vector<std::string> funny){
        for(int i = 0; i < funny.size(); i++){
            Engine::Alphabet* s = new Engine::Alphabet(funny[i].c_str(), 0, (i * 60) + 200);
            s->screenCenter(Engine::Axes::X);
            alphabetGroup->add(s);
        }

    }
    void TestState::createMoreCoolText(const std::string& funny){
        Engine::Alphabet* s = new Engine::Alphabet(funny.c_str(), 0, (alphabetGroup->size() * 60) + 200);
        s->screenCenter(Engine::Axes::X);
        alphabetGroup->add(s);
    }
    void TestState::removeText(){
        for(auto& o : alphabetGroup->objects){
            alphabetGroup->remove(o);
        }
        for(auto& o : alphabetGroup->objects){
            alphabetGroup->remove(o);
        } //sometimes it doesn't want to remove so i have to do this twice
    }
    void TestState::beatHit(){
        switch(curBeat){
			case 1:
				createCoolText({"NINJAMUFFIN99", "PHANTONARCADE", "KAWAISPRITE", "EVILSKER"});
                break;
			case 3:
				createMoreCoolText("PRESENT");
                break;                
			case 4:
				removeText();
                break;
			case 5:
				createCoolText({"IN ASSOCIATION", "WITH"});
                break;
			case 7:
				createMoreCoolText("NEWGROUNDS");
                break;
			case 8:
				removeText();
                break;
			case 9:
				createCoolText({"PLACEHOLDER FOR WACKY"});
                break;
			case 11:
				createCoolText({"PLACEHOLDER FOR WACKY"});
                break;
			case 12:
				removeText();
                break;
			case 13:
				createMoreCoolText("FRIDAY");
                break;
			case 14:
				createMoreCoolText("NIGHT");
                break;
			case 15:
				createMoreCoolText("FUNKIN");
                break;
         }
        std::cout << ":happyman: " << curBeat << std::endl;
    }
}