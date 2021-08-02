#include "pch.h"
#include "SoundManager.h"

SoundManager* SoundManager::instance;

SoundManager::SoundManager()
{
	instance = this;
	CreateSound("fireBall", "Assets/FX-Fireball.wav");
	CreateSound("playerDamage", "Assets/FX-CharacterDamage.wav");
}

void SoundManager::CreateSound(string name, string fileName) 
{
	sf::SoundBuffer* sb = new sf::SoundBuffer();
	
	if (!sb->loadFromFile(fileName))
		cout << "Error Getting the Sound File " << fileName;

	sf::Sound* sound = new sf::Sound();
	sound->setBuffer(*sb);

	buffersMap.insert(pair<string, sf::SoundBuffer*>(name, sb));
	soundsMap.insert(pair<string, sf::Sound*>(name, sound));
}

void SoundManager::Play(std::string name)
{
	sf::Sound* s = soundsMap[name];
	s->play();
}
