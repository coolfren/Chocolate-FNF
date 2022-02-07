#include "states/TestState.hpp"

namespace States
{
    void TestState::create(){
        Containers::Group *group = new Containers::Group();
        Engine::Sprite* sprite = new Engine::Sprite(getImage("boyfriend"));
        sprite->parseSparrowSpritesheet("romfs/images/boyfriend.xml", 24, "bf_idle");
        Engine::Text* text = new Engine::Text("MML DESERVES TO BE DELETED", 0, 400, 78, {0, 0, 0, 255}, getFont("fnf"));
        group->add(sprite);
        group->add(text);
        add(group);
    }
}