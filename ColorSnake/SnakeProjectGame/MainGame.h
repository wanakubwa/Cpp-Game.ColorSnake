#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"
#include "GameMenager.h"
#include "DeadMenu.h"
#include "Menu.h"
#include "WinMenu.h"

using namespace sf;

class MainGame
{
	unsigned int gameMode; //0 - menu, 1-glowna gra, 2 - dedmenu, 3 - win menu
	bool loadChecker;
	Event evnt;
	Clock clock;
	ContextSettings MySettings;
	RenderWindow window;
	Time elapsedTime;

	GameMenager *objMenager;
	DeadMenu *objDeadMenu;
	Menu *objMenu;
	WinMenu *objWinMenu;

	Texture logoTexture;
	Texture buttonTexture;
	Font montserratBold;
	Font montserratExtraBold;

public:
	MainGame();
	~MainGame();

	void Initialize();
	void CheckNextFrameMode();
	bool LoadPrefabs();

};