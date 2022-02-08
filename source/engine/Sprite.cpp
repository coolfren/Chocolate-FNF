#include "engine/Common.hpp"
#include "engine/Sprite.hpp"
#include "core/Paths.hpp"

namespace Engine
{
    Sprite::Sprite(const char* path){
        type = Type::SPRITE;
        animated = false;
        #ifdef USE_SURF
        surf = IMG_Load(path);
        if(surf == NULL){
            surf = IMG_Load(getImage("missing"));
        }
        #endif
        tex = IMG_LoadTexture(Engine::renderer, path);//SDL_CreateTextureFromSurface(Engine::renderer, surf);
        int wd, hi;
        SDL_QueryTexture(tex, NULL, NULL, &wd, &hi);
        _pos = {0, 0, wd, hi};
        frame = nullptr;

        w = wd;
        h = hi;
    }

    Sprite::~Sprite(){
        #ifdef USE_SURF
        SDL_FreeSurface(surf);
        #endif
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
            if(frame != nullptr)
                _pos = {x, y, frame->w, frame->h};
            else
                _pos = {x, y, w, h};
        }
        else
            _pos = {x, y, w, h};
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
        if(doc.LoadFile(path) != tinyxml2::XML_SUCCESS){
            std::cerr << "Error loading spritesheet: " << path << std::endl;
        }
        //let's open the root element called TextureAtlas
        tinyxml2::XMLElement* root = doc.FirstChildElement("TextureAtlas");
        //now we can get all the children called "SubTexture" of the root element
        tinyxml2::XMLElement* subTexture = root->FirstChildElement("SubTexture");
        while(subTexture != nullptr){
            //now we can get all the attributes of the SubTexture
            std::string tmpname = subTexture->Attribute("name");
            std::string name = tmpname.substr(0, tmpname.size() - 4);
            //int num = std::stoi(tmpname.substr(tmpname.size() - 4, tmpname.size()));
            int x = subTexture->IntAttribute("x");
            int y = subTexture->IntAttribute("y");
            int w = subTexture->IntAttribute("width");
            int h = subTexture->IntAttribute("height");
            //now we can get the next SubTexture
            subTexture = subTexture->NextSiblingElement("SubTexture");
            //and add it to the map
            frames[name].push_back({x, y, w, h});
            //frames[name][num] = {x, y, w, h};
        }
        std::cout << "passed!" << std::endl;
        curAnim = defaultAnimation;
        animated = true;
    }
}