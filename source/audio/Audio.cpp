#include "audio/Audio.hpp"

namespace Audio
{
    Audio::Audio()
    {
        type = Engine::Type::AUDIO;
        audio = nullptr;
        music = nullptr;
    }

    Audio::Audio(const char* path, bool music)
    {
        type = Engine::Type::AUDIO;
        std::string* str = getSound(path, music);
        if (music)
        {
            this->music = Mix_LoadMUS(str->c_str());
            if(!this->music)
            {
                printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
            }
        }
        else
        {
            this->audio = Mix_LoadWAV(str->c_str());
            if(!audio)
            {
                printf("Failed to load chunk! SDL_mixer Error: %s\n", Mix_GetError());
            }
        }
        delete str;
    }

    void Audio::play()
    {
        if(audio != nullptr)
            Mix_PlayChannel(-1, audio, 0);
    }

    void Audio::playMusic(bool loop)
    {
        if(music != nullptr)
            Mix_PlayMusic(music, loop ? -1 : 0);
    }

    int Audio::getMusicPosition()
    {
        return -1;
    }
}