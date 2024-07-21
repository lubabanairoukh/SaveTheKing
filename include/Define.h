
#pragma once
#include <SFML/Graphics.hpp>


const int MenuStart = 3;
const int M_WidthWindow = 1500;
const int M_HieghtWindow = 800;
const float ICON_SIZE = 170;
const int m_ToolBar = 100;
constexpr auto ShapeSize = 50.f;
constexpr auto ShapeSpeed = ShapeSize * 3;
const int withouttoolbar = 1200;
const int m_HiegthText = M_HieghtWindow - m_ToolBar;
const int TIME = 60;
const int SIZEPIC = 46;
const int MENUTEXT = 2;
const int MENUSTART = 3;
const int SIZECHARACTER = 35;
const int P_SIZE = 50;
const int LEFTTIME = 10;
const int TOOLBARPLAYER = 40;
const int SIZEY = 40;
const int m_SizeMusicP = 70;
const int NumOfObjects = 14;
const int MUSICONOFF = 2;
enum  Objects {
	KingObj, MageObj, WarriorObj, ThiefObj, FireObj, WallObj, KeyObj, GateObj, OrcObj, TelObj, ChairKingObj,
	EnemyObj,ThiefWithKey,GiftsObj
};
enum gifts {
	EnTime, DECTIME, ERASEO,NONE
};

