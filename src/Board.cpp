#include "Board.h"

int Board::m_width = 0;
int Board::m_height = 0;

Board::Board()
{
	m_fileRead.open("Board.txt");

}

bool Board::readlevel()
{
	m_map.clear();
	if (m_fileRead.eof())
		return false;
	std::string number;
	m_fileRead >> number;
	if (m_fileRead.eof())
		return false;
	m_height = std::stoi(number);
	m_fileRead >> number;
	m_width = std::stoi(number);


	if (m_fileRead.eof())
		return false;
	m_fileRead.ignore();
	if (m_fileRead.eof())
		return false;
	auto line = std::string();
	for (int row = 0; row < m_height; row++)
	{
		getline(m_fileRead, line);
		m_map.push_back(line);

	}
	return true;
}

int Board::getWidthMap()const
{
	return m_width;
}

int Board::getHeightMap()const
{
	return m_height;
}

char Board::getCharMap(int row, int col)const
{
	return m_map[row][col];
}

bool Board::finishAllLevels()
{
	if (m_fileRead.eof())
		return true;
	return false;
}

Board& Board::instance()
{
	/*
	*
	* make an static object of class and return it
	*
	*/

	static Board board;
	return board;
}

