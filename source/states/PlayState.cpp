#include "states/PlayState.hpp"

namespace States
{
    void PlayState::create()
    {
        Engine::Sprite* beg = new Engine::Sprite(getImage("menuBG"));
        beg->x = -80;
        beg->w = (int)(beg->w * 1.1f);
        add(beg);
        using namespace Engine; //got tired of typing Engine::
        Sprite *bg = new Sprite(getImage("stages/stageback"));
        //bg->setPosition(-600, -200);

        Sprite *sf = new Sprite(getImage("stages/stagefront"));
        //sf->setPosition(-650, 600);

        Sprite *sc = new Sprite(getImage("stages/stagecurtains"));
        //sc->setPosition(-500, -300);

        add(bg);
        add(sf);
        add(sc);
    }
    
    void PlayState::update()
    {
        State::update();
    }
}