#include "engine/Common.hpp"
#include "engine/Sprite.hpp"
#include "core/Paths.hpp"

namespace Engine
{
    Sprite::Sprite(){
        type = Type::SPRITE;
        animated = false;
        frame = (Frame*)malloc(sizeof(Frame));
        w = 10;
        h = 10;
        _pos = {10, 10, 10, 10};
    }

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
        SDL_QueryTexture(tex, NULL, NULL, &w, &h);
        _pos = {0, 0, w, h};
        frame = (Frame*)malloc(sizeof(Frame));
    }

    Sprite::~Sprite(){
        #ifdef USE_SURF
        SDL_FreeSurface(surf);
        #endif
        free(frame);
        SDL_DestroyTexture(tex);
    }

    void Sprite::update(){
        if(animated){
            if(frames[curAnim].size() > 0)
                frameIndex = (SDL_GetTicks() / (fps + 10)) % frames[curAnim].size(); // the plus 10 is a temporary fix until i find something better
            else
                frameIndex = 0;
            frame = &frames[curAnim][frameIndex];
            if(frame != nullptr){
                _pos = {x - frame->frameX, y - frame->frameY, frame->w, frame->h};
                fWidth = frame->w;
                fHeight = frame->h;
            }
            else
                _pos = {x, y, w, h};
            color = {255, 255, 255, alpha};
            SDL_SetTextureAlphaMod(tex, alpha); //what the fuck why are they seperate functions gg sdl devs
            SDL_SetTextureColorMod(tex, color.r, color.g, color.b);
        }
        else
            _pos = {x, y, w, h};
    }

    SDL_Texture* Sprite::getTex(){
        return tex;
    }

    void Sprite::setTex(SDL_Texture* tex){
        this->tex = tex;
    }

    const SDL_Rect* Sprite::getPos(){
        return &_pos;
    }

    const Frame* Sprite::getFrame(){
        return frame;
    }

    std::map<std::string, std::vector<Frame>>* Sprite::getFrames(){
        return &frames;
    }

    void Sprite::setFrames(std::map<std::string, std::vector<Frame>>* frames){
        this->frames = *frames;
    }

    void Sprite::parseSparrowSpritesheet(const char* path, int frameps, const std::string& defaultAnimation, bool looped){
        fps = frameps;
        loop = looped;
        frameIndex = 0;
        tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
        if(doc->LoadFile(path) != tinyxml2::XML_SUCCESS){
            std::cerr << "Error loading spritesheet: " << path << '\n';
        }
        //let's open the root element called TextureAtlas
        tinyxml2::XMLElement* root = doc->FirstChildElement("TextureAtlas");
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
            int frameX = subTexture->IntAttribute("frameX");
            int frameY = subTexture->IntAttribute("frameY");
            //now we can get the next SubTexture
            subTexture = subTexture->NextSiblingElement("SubTexture");
            //and add it to the map
            frames[name].push_back({x, y, w, h, frameX, frameY});
            //frames[name][num] = {x, y, w, h};
        }
        delete doc;
        curAnim = defaultAnimation;
        frame = &frames[curAnim][0];
        animated = true;
    }

    void Sprite::playAnim(const char* anim){
        frameIndex = 0;
        curAnim = anim;
    }
}
