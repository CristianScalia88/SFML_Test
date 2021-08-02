#pragma once


class SoundManager
{
private:
	map<std::string, sf::SoundBuffer*> buffersMap;
	map<std::string, sf::Sound*> soundsMap;
	void CreateSound(string name, string fileName);
public:
	static SoundManager* instance;
	SoundManager();
	void Play(std::string name);
	
};

