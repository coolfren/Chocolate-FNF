#include "engine/Alphabet.hpp"

namespace Engine
{
    Engine::Sprite* Alphabet::baseSpr = nullptr;

    Alphabet::Alphabet(const char* text, int x, int y){
        type = Engine::Type::ALPHABET;
        char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char symbols[10] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
        if(baseSpr == nullptr){
            baseSpr = new Engine::Sprite(getImage("alphabet"));
            baseSpr->parseSparrowSpritesheet(getXML("alphabet"), 24, "a lowercase", true);
        }
        for (int i = 0; i < strlen(text); i++){
            char c = text[i];
            if (c == ' '){
                continue;
            }
            Engine::Sprite* spr = new Engine::Sprite();
            std::string baseAnim;
            bool isNum = false;
            int numIndex = 0;
            for(int j = 0; j < 10; j++){
                isNum = c == numbers[j];
                if(isNum){
                    numIndex = j;
                    break;
                }
            }
            if(!isNum)
                baseAnim.append(1, c).append(isupper(c) ? " bold" : " lowercase");
            else
                baseAnim.append(1, numbers[numIndex]);
            spr->ID = i;
            spr->curAnim = baseAnim;
            spr->setTex(baseSpr->getTex());
            spr->setFrames(baseSpr->getFrames());
            spr->w = baseSpr->w;
            spr->h = baseSpr->h;
            spr->x = x + (50 * i);
            spr->y = y;
            spr->animated = true;
            add(spr);
        }
    }

    Alphabet::~Alphabet(){
        delete baseSpr;
    }

    void Alphabet::screenCenter(Axes axis){
        for(auto& o : objects){
            switch(axis){
                case Axes::X:
                    ((Engine::Sprite*)o)->x += ((1280 / 2) - (((Engine::Sprite*)o)->w));
                    break;
                case Axes::Y:
                    ((Engine::Sprite*)o)->y = (720 / 2) - (((Engine::Sprite*)o)->h / 2);
                    break;
                case Axes::XY:
                    ((Engine::Sprite*)o)->x = (1280 / 2) - (((Engine::Sprite*)o)->w / 2);
                    ((Engine::Sprite*)o)->y = (720 / 2) - (((Engine::Sprite*)o)->h / 2);
                    break;
            }
        }
    }
}