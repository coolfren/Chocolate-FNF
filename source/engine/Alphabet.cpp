#include "engine/Alphabet.hpp"

namespace Engine
{
    Engine::Sprite* Alphabet::baseSpr = nullptr;

    Alphabet::Alphabet(const char* text, int x, int y){
        type = Engine::Type::ALPHABET;
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
            baseAnim.append(1, c).append(isupper(c) ? " bold" : " lowercase");
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
}