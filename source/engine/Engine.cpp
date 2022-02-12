#include "engine/Engine.hpp"

namespace Engine
{
    State* curState;
    int transX = 0, transY = -720;
    bool switcharoo = false, shouldUpdate = true;

    void _switchState(State* state)
    {
        switcharoo = false;
        // switcharoo1.a = 255;
        // switcharoo2.a = 0;
        while(transY != 720){
            transY += 1;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        shouldUpdate = false;
        delete curState;

        curState = state;
        curState->create();
        shouldUpdate = true;
        switcharoo = true;
        // switcharoo1.a = 0;
        // switcharoo2.a = 255;
        transY = -720;
        while(transY != 720)
        {
            transY += 1;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        switcharoo = false;
        shouldUpdate = true;
    }

    void switchState(State* state)
    {  
        std::thread sT(_switchState, state);
        sT.detach();
    }

    void drawHorizontalGradientBox(SDL_Renderer * renderer,
            const int x, const int y, const int w, const int h, const float steps,
            const SDL_Color c1, const SDL_Color c2, const int fill)
    {

        /* Acumulator initial position */
        float yt = y;
        float rt = c1.r;
        float gt = c1.g;
        float bt = c1.b;
        float at = c1.a;
        
        /* Changes in each attribute */
        float ys = h/steps;
        float rs = (c2.r - c1.r)/steps;
        float gs = (c2.g - c1.g)/steps;
        float bs = (c2.b - c1.b)/steps;
        float as = (c2.a - c1.a)/steps;

        for(int i = 0; i < steps ; i++)
        {
            /* Create an horizontal rectangle sliced by the number of steps */
            SDL_Rect rect = { x, (int)(yt), w, (int)(ys+1) };

            /* Sets the rectangle color based on iteration */
            SDL_SetRenderDrawColor(renderer, rt, gt, bt, at);

            /* Paint it or coverit*/
            if(fill)
                SDL_RenderFillRect(renderer, &rect);
            else
                SDL_RenderDrawRect(renderer, &rect);

            /* Update colors and positions */
            yt += ys;
            rt += rs;
            gt += gs;
            bt += bs;
            at += as;
        }
    }
    void render(Engine::Basic* obj)
    {
        switch(obj->type){
            case Type::SPRITE:
                SDL_RenderCopy(Engine::renderer, ((Sprite*)obj)->getTex(), (SDL_Rect*)(((Sprite*)obj)->getFrame()), ((Sprite*)obj)->getPos());
                break;
            case Type::TEXT:
                if(((Text*)obj)->tex2 != nullptr)
                    SDL_RenderCopy(Engine::renderer, ((Text*)obj)->tex2, nullptr, &((Text*)obj)->pos);
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
            case Type::SHAPE:{
                SDL_Color shapeColor = ((Engine::Shape*)obj)->color;
                SDL_SetRenderDrawColor(Engine::renderer, shapeColor.r, shapeColor.g, shapeColor.b, shapeColor.a);
                SDL_RenderFillRect(Engine::renderer, ((Engine::Shape*)obj)->getPos());
                break;
            }
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
        SDL_SetRenderDrawBlendMode(Engine::renderer, SDL_BLENDMODE_BLEND);
        curState = beginState;
        curState->create();
        SDL_Keycode prevKey = SDLK_UNKNOWN;
        SDL_KeyCode buf = SDLK_UNKNOWN;
        while(true){
            SDL_Event event;
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT){
                    return destruct();
                }
                if(event.type == SDL_KEYDOWN){
                    if(event.key.keysym.sym > 256)
                        continue;
                    curState->keysPressed[event.key.keysym.sym] = true;
                    if(prevKey != event.key.keysym.sym){
                        curState->keyEvent(event.key.keysym.sym, true);
                        prevKey = event.key.keysym.sym;
                    }
                }
                if(event.type == SDL_KEYUP){
                    if(event.key.keysym.sym > 256)
                        continue;
                    curState->keyEvent(event.key.keysym.sym, false);
                    prevKey = SDLK_UNKNOWN;
                }
            }

            SDL_SetRenderDrawColor(Engine::renderer, 0, 0, 0, 255);
            SDL_RenderClear(Engine::renderer);
            if(shouldUpdate){
                curState->update();
                curState->keyRelease(prevKey);

            }
            for(auto& obj : curState->objects){
                render(obj);
            }
            int thething = 0;
            if(switcharoo)
                thething = -720;
            else
                thething = 720;
            SDL_Rect cu = {transX, transY - thething, 1280, 720};
            SDL_SetRenderDrawColor(Engine::renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(Engine::renderer, &cu);
            drawHorizontalGradientBox(Engine::renderer, transX, transY, 1280, 720, 100, {0,0,0,(Uint8)(switcharoo?0:255)}, {0,0,0,(Uint8)(switcharoo?255:0)}, true);
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