#pragma once
#include "engine/Common.hpp"
#include "core/Paths.hpp"
namespace Audio
{
    class Audio : public Engine::Basic
    {
        private:
        Mix_Music *music;
        Mix_Chunk *audio;
        public:
        Audio();
        Audio(const char* path, bool music);
        void play();
        void playMusic(bool loop);
        int getMusicPosition();
    };
}