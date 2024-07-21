#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>



class Board {

public:
	~Board() = default;//close board.txt file

	static Board& instance();
	static int m_width;
	static int m_height;
	bool readlevel();
	int getWidthMap()const;
	int getHeightMap()const;
	char getCharMap(int row, int col)const;
	bool finishAllLevels();

private:
	Board();
	std::ifstream m_fileRead;
	std::vector<std::string> m_map;

};

