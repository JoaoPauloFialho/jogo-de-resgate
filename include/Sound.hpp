#ifndef SOUND_HPP
#define SOUND_HPP
using namespace std;

#include <string>


class Sound
{
public:
	Sound(string soundName) : soundName(soundName),PID_child(-1),paused(false){}
	~Sound();

	bool play(unsigned = 1);
	bool playloop();
	bool stop();
	bool pause();
	bool unpause();
	bool ispaused() const {return paused;}
	bool isplaying() const;
	

private:
	string soundName;
	int PID_child;
	
	bool paused;
};

#endif // SOUND_HPP
