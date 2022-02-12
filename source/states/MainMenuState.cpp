#include "states/MainMenuState.hpp"

namespace States
{
    const char* options[4] = {"story mode", "freeplay", "donate", "options"};
    void MainMenuState::create()
    {
        Engine::Sprite* bg = new Engine::Sprite(getImage("menuBG"));
        bg->x = -80;
        bg->w = (int)(bg->w * 1.1f);
        add(bg);
        scroll = new Audio::Audio("scrollMenu", false);
        Engine::Sprite* mmAssets = new Engine::Sprite(getImage("FNF_main_menu_assets"));
        mmAssets->parseSparrowSpritesheet(getXML("FNF_main_menu_assets"), 24, "story mode basic", true);

        theOptions = new Containers::Group();
        for(int i = 0; i < 4; i++){
            Engine::Sprite* option = new Engine::Sprite();
            option->y = 60 + (i * 160);
            option->ID = i;
            option->setTex(mmAssets->getTex());
            option->setFrames(mmAssets->getFrames());
            option->animated = true;
            std::string baseAnim(options[i]);
            baseAnim.append(" basic");
            option->playAnim(baseAnim.c_str());
            const auto& leframes = option->getFrames();
            option->x = (1280 / 2) - (leframes->at(baseAnim)[0].w / 2);
            theOptions->add(option);
        }
        add(theOptions);
        Engine::Text* verText = new Engine::Text("v0.2.7.1", 5, 720 - 28, 24, {12, 52, 255, 255}, getFont("vcr"));
        verText->applyOutline({0, 0, 0, 255}, 8);
        add(verText);
        
        switchMenu(0);
    }
    
    void MainMenuState::update()
    {
        State::update();
        if(keysJustPressed[SDLK_w]){
            switchMenu(1);
        }
        if(keysJustPressed[SDLK_s]){
            switchMenu(-1);
        }
        if(keysJustPressed[SDLK_RETURN]){
            switchState(new PlayState());
        }
    }

    void MainMenuState::switchMenu(int index){
        #define EzCast(x) ((Engine::Sprite*)( x ))
        selected -= index;
        if(selected < 0){
            selected = 3;
        }
        if(selected > 3){
            selected = 0;
        }
        for(auto& op : theOptions->objects){
            if(op->ID == selected){
                std::string baseAnim(options[op->ID]);
                baseAnim.append(" white");
                EzCast(op)->playAnim(baseAnim.c_str());
                EzCast(op)->x = (1280 / 2) - (((Engine::Sprite*)(theOptions->objects[selected]))->getFrames()->at(baseAnim)[0].w / 2);
            }
            else{
                std::string baseAnim(options[op->ID]);
                baseAnim.append(" basic");
                EzCast(op)->playAnim(baseAnim.c_str());
                EzCast(op)->x = (1280 / 2) - (((Engine::Sprite*)(theOptions->objects[selected]))->getFrames()->at(baseAnim)[0].w / 2);
            }
        }
        scroll->play();
    }
}