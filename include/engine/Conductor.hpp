#pragma once
namespace Music
{
    //ripped straight out of Conductor.hx
    class Conductor
    {
        public:
        static int bpm;
        static float crochet; // beats in milliseconds
        static float stepCrochet; // steps in milliseconds
        static float songPosition;
        static float lastSongPos;
        static float offset;

        static int safeFrames;
        static float safeZoneOffset; // is calculated in create(), is safeFrames in milliseconds

        static void changeBPM(int newBpm);
    };
}