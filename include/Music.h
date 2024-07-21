#pragma once
#include <SFML/Audio.hpp>
#include <array>
#include <SFML/Graphics.hpp>
#include "Define.h"
#include "Texture.h"

/*
*
* class upload an music file
* define static object class
* start the music of the game
* pause the music of the game
*
*
*/


class Music
{

public:
	virtual ~Music() = default; // close music file

	static Music& instance();

	void startMusic(bool on=true);

	void pauseMusic();

	void draw(sf::RenderWindow& window);
	void reSetMusic();

	bool handleclickMusic(sf::Vector2f location);

	void MouseButtonReleased(sf::Vector2f location);
	void reSetMusicGame();
	void reSetMusicGameOver();
	void reSetMusicWinGame();
	void reSetMusicTake();
	void reSetMusicTel();
	void reSetMusicMage();
	void reSetMusicKey();
	void reSetMusicOrc();
	void reSetMusicWinallGame();
	void update(sf::Music& musicplay);

private:

	Music();

	sf::Music m_MenuMusic;
	sf::Music m_mus;
	sf::Music m_telphort;
	sf::Music m_mage;
	sf::Music m_key;
	sf::Music m_orc;
	sf::SoundBuffer m_buffers;

	sf::Sprite m_music[MUSICONOFF];

	bool m_MusicOnOff;

};