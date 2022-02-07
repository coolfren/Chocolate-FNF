#include "engine/Conductor.hpp"
namespace Music
{
    int Conductor::bpm = 100;
    float Conductor::crochet = ((60 / bpm) * 1000); // beats in milliseconds
    float Conductor::stepCrochet = crochet / 4; // steps in milliseconds
    float Conductor::songPosition;
    float Conductor::lastSongPos;
    float Conductor::offset = 0;
    
    int Conductor::safeFrames = 10;
    float Conductor::safeZoneOffset = (safeFrames / 60) * 1000; // is calculated in create(), is safeFrames in milliseconds

    static void changeBPM(int newBpm)
	{
		Conductor::bpm = newBpm;

		Conductor::crochet = ((60 / Conductor::bpm) * 1000);
		Conductor::stepCrochet = Conductor::crochet / 4;
	}
}