#pragma once
#include "engine/Common.hpp"

namespace Engine
{
    class Sprite : public Basic
    {
        private:
        SDL_Rect _pos;
        SDL_Rect *frame;

        SDL_Texture* tex; 
#ifdef USE_SURF //abandoning surfaces (for now)
        SDL_Surface* surf;
#endif
        std::map<std::string, std::vector<SDL_Rect>> frames;
        
        public:
        bool animated;
        std::string curAnim;

        unsigned int frameIndex;
        int fps;
        int x = 0, y = 0;
        int w = 0, h = 0;

        Sprite(const char* path);
        virtual ~Sprite();

        virtual void update();

        SDL_Texture* getTex();

        const SDL_Rect* getPos();
        const SDL_Rect* getFrame();

        void parseSparrowSpritesheet(const char* path, int frameps, const std::string& defaultAnimation);
    };
}