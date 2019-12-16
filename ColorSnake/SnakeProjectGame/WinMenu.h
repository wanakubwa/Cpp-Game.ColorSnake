#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"
#include <sstream>

using namespace sf;
using namespace std;

class WinMenu
{
	RectangleShape background; //tlo niebieskie
	Sprite logo; //logo
	Sprite button; //guzk 'play'
	Text wictory; //napis 'wictory'
	Text score;

	bool isButtonClicked; //zmienna informujaca czy resetowac gre

public:
	WinMenu(Font & montserratBold, Font & montserratExtraBold, Texture & logoTexture, Texture &buttonTexture);
	~WinMenu();

	void Update(RenderWindow &window, unsigned int scoreGame);
	void Draw(RenderWindow &window);
	void RestartWinMenu();
	bool ButtonChecker() const;
};
