#pragma once
#include "engine/Common.hpp"

namespace Engine
{
    struct Frame
    {
        int x;
        int y;
        int w;
        int h;
        int frameX;
        int frameY;
        int frameWidth;
        int frameHeight;
    };

    class Sprite : public Basic
    {
        private:
        SDL_Rect _pos;
        Frame *frame;

        SDL_Texture* tex; 
#ifdef USE_SURF //abandoning surfaces (for now)
        SDL_Surface* surf;
#endif
        std::map<std::string, std::vector<Frame>> frames;
        
        public:
        bool animated;
        std::string curAnim;

        unsigned int frameIndex;
        int fps = 24;
        int x = 0, y = 0, frameX = 0, frameY = 0;
        int w = 0, h = 0;

        Sprite();
        Sprite(const char* path);
        virtual ~Sprite();

        virtual void update();

        SDL_Texture* getTex();
        void setTex(SDL_Texture* tex);

        const SDL_Rect* getPos();
        const SDL_Rect* getFrame();

        std::map<std::string, std::vector<Frame>>* getFrames();
        void setFrames(std::map<std::string, std::vector<Frame>>* frames);

        void parseSparrowSpritesheet(const char* path, int frameps, const std::string& defaultAnimation);

        void playAnim(const char* anim);
    };
}