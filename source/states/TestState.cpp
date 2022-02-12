#include "states/TestState.hpp"

namespace States
{
    void TestState::create(){
        alphabetGroup = new Containers::Group();
        add(alphabetGroup);
        Audio::Audio* audio = new Audio::Audio("menu", true);
        confirm = new Audio::Audio("confirmMenu", false);
        gf = new Engine::Sprite(getImage("gfDanceTitle"));
        gf->x = (int)round(1280*0.4f);
        gf->y = (int)round(720*0.07f);
        gf->alpha = 0;
        gf->parseSparrowSpritesheet(getXML("gfDanceTitle"), 24, "gfDance", true);
        add(gf);

        logo = new Engine::Sprite(getImage("logoBumpin"));
        logo->x = -150;
        logo->y = -100;
        logo->alpha = 0;
        logo->parseSparrowSpritesheet(getXML("logoBumpin"), 24, "logo bumpin", true);
        add(logo);

        enter = new Engine::Sprite(getImage("titleEnter"));
        enter->x = 100;
        enter->y = (int)round(720*0.8f);
        enter->alpha = 0;
        enter->parseSparrowSpritesheet(getXML("titleEnter"), 24, "Press Enter to Begin", true);
        add(enter);

        white = new Engine::Shape(0, 0, 1280, 720, {255, 255, 255, 0});
        add(white);
        Music::Conductor::changeBPM(102);
        threads.add("musicPos", [&audio](){
            while(true){
                if(!Mix_PlayingMusic()){
                    std::cout << "FUCK";
                    audio->playMusic(true);
                }
                Music::Conductor::songPosition++;
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });
    }
    void TestState::update(){
        State::update();
        if(white->color.a != 0)
            white->color.a -= 1;
        if(keysJustPressed[SDLK_RETURN] && !skippedIntro)
            skipIntro();
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
    void TestState::skipIntro(){
        skippedIntro = true;
        removeText();
        white->color.a = 255; // simulates FlxG.camera.flash()
        gf->alpha = 255;
        logo->alpha = 255;
        enter->alpha = 255;
    }
    void TestState::keyEvent(SDL_Keycode key, bool isPressed){
        if(key == SDLK_RETURN && !skippedIntro){
            skipIntro();
        }
        else if(key == SDLK_RETURN && skippedIntro && !f){
            confirm->play();
            enter->playAnim("ENTER PRESSED");
            f = true;
        };
    }
    void TestState::beatHit(){
        if(skippedIntro)
            return;
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
            case 16:
                skipIntro();
         }
        std::cout << ":happyman: " << curBeat << std::endl;
    }
}