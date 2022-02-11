#include "engine/Engine.hpp"

namespace Engine
{
    State* curState;

    void switchState(State* state)
    {
        if(curState != nullptr)
            delete curState;
        curState = state;
        curState->create();
    }

    void render(Engine::Basic* obj)
    {
        switch(obj->type){
            case Type::SPRITE:
                SDL_RenderCopy(Engine::renderer, ((Sprite*)obj)->getTex(), ((Sprite*)obj)->getFrame(), ((Sprite*)obj)->getPos());
                break;
            case Type::TEXT:
                SDL_RenderCopy(Engine::renderer, ((Text*)obj)->tex, nullptr, &((Text*)obj)->pos);
                break;
            case Type::ALPHABET:
                for(auto& object : ((Engine::Alphabet*)obj)->objects){
                    render(object);
                }
                break;
            case Type::GROUP:
                for(auto& object : ((Containers::Group*)obj)->objects){
                    render(object);
                }
                break;
            case Type::SHAPE:
                break;
            case Type::AUDIO:
                break;
            case Type::NOTHING:
                break;
        }
    }

    void initialize(launchOptions launch, Engine::State* beginState){
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG);
	    TTF_Init();
        Mix_Init(MIX_INIT_OGG);
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

        #ifdef __SWITCH__
        romfsInit();
        chdir("romfs:/");
        #endif
        Engine::window = SDL_CreateWindow(launch.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, launch.width, launch.height, SDL_WINDOW_SHOWN);
        Engine::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        curState = beginState;
        curState->create();
        while(true){
            SDL_Event event;
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT){
                    return destruct();
                }
            }
            SDL_RenderClear(Engine::renderer);
            curState->update();
            for(auto& obj : curState->objects){
                render(obj);
            }
            SDL_RenderPresent(Engine::renderer);
            SDL_Delay(1000/60);
        }
    }

    void destruct(){
        SDL_DestroyRenderer(Engine::renderer);
        SDL_DestroyWindow(Engine::window);
        delete curState;
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
    }
};