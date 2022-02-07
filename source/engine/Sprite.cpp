#include "engine/Common.hpp"
#include "engine/Sprite.hpp"
#include "core/Paths.hpp"

namespace Engine
{
    Sprite::Sprite(const char* path){
        type = Type::SPRITE;
        animated = false;

        surf = IMG_Load(path);
        if(surf == NULL){
            surf = IMG_Load(getImage("missing"));
        }
        tex = SDL_CreateTextureFromSurface(Engine::renderer, surf);

        _pos = {0, 0, surf->w, surf->h};
        frame = nullptr;

        w = surf->w;
        h = surf->h;
    }

    Sprite::~Sprite(){
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
    }

    void Sprite::update(){
        if(animated){
            frame = &frames[curAnim][frameIndex];
            if(frames[curAnim].size() > frameIndex)
            //increment frameIndex, the frame index will determine the frame to be rendered. it will increment by 1 each 24 frame in 60 frames
            frameIndex = (SDL_GetTicks() / 24) % frames[curAnim].size();
            else
                frameIndex = 0;
            _pos = {x, y, frame->w, frame->h};
        }
        else
            _pos = {x, y, surf->w, surf->h};
    }

    SDL_Texture* Sprite::getTex(){
        return tex;
    }

    const SDL_Rect* Sprite::getPos(){
        return &_pos;
    }

    const SDL_Rect* Sprite::getFrame(){
        return frame;
    }

    void Sprite::parseSparrowSpritesheet(const char* path, int frameps, const std::string& defaultAnimation){
        fps = frameps;
        tinyxml2::XMLDocument doc;
        doc.LoadFile(path);
        //let's open the root element called TextureAtlas
        tinyxml2::XMLElement* root = doc.FirstChildElement("TextureAtlas");
        //now we can get all the children called "SubTexture" of the root element
        tinyxml2::XMLElement* subTexture = root->FirstChildElement("SubTexture");
        while(subTexture != nullptr){
            //now we can get all the attributes of the SubTexture
            std::string name = subTexture->Attribute("name");
            name = name.substr(0, name.size() - 4);
            int x = subTexture->IntAttribute("x");
            int y = subTexture->IntAttribute("y");
            int w = subTexture->IntAttribute("width");
            int h = subTexture->IntAttribute("height");
            //now we can get the next SubTexture
            subTexture = subTexture->NextSiblingElement("SubTexture");
            //and add it to the map
            frames[name].push_back({x, y, w, h});
        }
        curAnim = defaultAnimation;
        animated = true;
    }
}