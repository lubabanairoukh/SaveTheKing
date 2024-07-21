#include "Music.h"


//-----------------------------------------------------------------------------------------------

Music::Music()
{
	/*
	* save the audo of the music of the menu game
	* save the pics of the music of the menu game
	* put the begin of the music to be on wfor the first time
	*/


	m_MenuMusic.openFromFile("MusicMenuGame.ogg");

	for (int i = 0; i < MUSICONOFF; i++)
	{
		auto texturePtr = Texture::instance().getMusicTexture(i);
		m_music[i].setTexture(*texturePtr);
	}

	for (int i = 0; i < MUSICONOFF; i++) {
		m_music[i].setScale(sf::Vector2f((m_SizeMusicP / m_music[1].getGlobalBounds().width),
			(m_SizeMusicP / m_music[1].getGlobalBounds().height)));
		m_music[i].setPosition(sf::Vector2f(1430, 730));
	}

	m_MusicOnOff = true;
}

//-----------------------------------------------------------------------------------------------

Music& Music::instance()
{
	/*
	* define an static object of class and return it
	*/


	static Music music;

	return music;
}

//-----------------------------------------------------------------------------------------------

void Music::startMusic(bool on)
{
	/*
	* set uo the music and play it in loop
	*/
	m_MenuMusic.play();
	m_MenuMusic.setLoop(on);
	m_MenuMusic.setVolume(20);
}

//-----------------------------------------------------------------------------------------------

void Music::pauseMusic()
{
	/*
	* pause the music
	*/


	m_MenuMusic.pause();
}

void Music::draw(sf::RenderWindow& window)
{

	/*
	* draw the picture of the music depends
	* if the music on or off
	*/


	if (!m_MusicOnOff)
		window.draw(m_music[1]);
	else
		window.draw(m_music[0]);

}

void Music::reSetMusic()
{
	m_MusicOnOff = true;
	m_MenuMusic.openFromFile("GamePlay.ogg");
	startMusic();
	
}

bool Music::handleclickMusic(sf::Vector2f location)
{
	/*
	* cheack if the mouse was inside the pic of the music
	* to be able to change the audo to be on or off
	*/

	for (int i = 0; i < MUSICONOFF; i++) {
		if (m_music[i].getGlobalBounds().contains(location))
		{
			m_MusicOnOff = !m_MusicOnOff;
			return true;
			break;
		}
	}
	return false;
}

void Music::MouseButtonReleased(sf::Vector2f location)
{

	/*
	* cheack if the player click the mouse inside the music
	* change the audo of the music to be on or off
	*/


	if (handleclickMusic(location))
	{
		if (!m_MusicOnOff)
		{
			pauseMusic();

		}
		else
		{
			//m_MusicOnOff = !m_MusicOnOff;
			startMusic();
		}
	}

}

void Music::reSetMusicGame()
{
	m_MusicOnOff = true;
	m_MenuMusic.openFromFile("MusicGame.ogg");
	startMusic();
}

void Music::reSetMusicGameOver()
{
	m_MusicOnOff = true;
	m_MenuMusic.openFromFile("GameOver.ogg");
	startMusic(false);
}

void Music::reSetMusicWinGame()
{
	m_MusicOnOff = true;
	m_MenuMusic.openFromFile("LevelUp.ogg");
	m_MenuMusic.setVolume(200);
	startMusic(false);
}


void Music::reSetMusicWinallGame()
{
	m_MusicOnOff = true;
	m_MenuMusic.openFromFile("GameWin.ogg");
	startMusic(false);
}
void Music::reSetMusicTake()
{
	
	m_mus.openFromFile("Tke.ogg");
	update(m_mus);

}

void Music::reSetMusicTel()
{
	
	m_telphort.openFromFile("Telephort.ogg");
	update(m_telphort);
	
}

void Music::reSetMusicMage()
{
	
	m_mage.openFromFile("FireMage.ogg");
	update(m_mage);
}

void Music::reSetMusicKey()
{
	
	m_key.openFromFile("Key.ogg");

	update(m_key);
}
void Music::reSetMusicOrc()
{
	
	m_orc.openFromFile("OrcKill.ogg");
	update(m_orc);

}

void Music::update(sf::Music& musicplay)
{
	m_MusicOnOff = true;
	m_MenuMusic.setVolume(5);
	musicplay.play();
	m_key.setLoop(false);
	m_MenuMusic.setVolume(20);
}