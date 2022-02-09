#include "engine/Alphabet.hpp"

namespace Engine
{
    Alphabet::Alphabet(const char* text){
        type = Engine::Type::ALPHABET;
        baseSpr = new Engine::Sprite(getImage("alphabet"));
        baseSpr->parseSparrowSpritesheet(getXML("alphabet"), 24, "a lowercase");
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
            spr->x = (50 * i);
            spr->animated = true;
            add(spr);
        }
        //baseSpr->parseSparrowSpritesheet(getXML("alphabet"));
    }

    Alphabet::~Alphabet(){
        delete baseSpr;
    }
}