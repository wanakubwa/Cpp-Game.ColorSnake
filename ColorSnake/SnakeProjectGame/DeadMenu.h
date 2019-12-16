#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"
#include <sstream>

using namespace sf;
using namespace std;

class DeadMenu
{
	RectangleShape background; //tlo niebieskie
	Sprite logo; //logo
	Sprite button; //guzki 'play'
	Text gameOver; //napisa gameover
	Text score;

	bool isButtonClicked; //zmienna informujaca czy resetowac gre

public:
	DeadMenu(Font & montserratBold, Font & montserratExtraBold, Texture & logoTexture, Texture &buttonTexture);
	~DeadMenu();

	void Update(RenderWindow &window, unsigned int scoreGame);
	void Draw(RenderWindow &window);
	void RestartDeadMenu();
	bool ButtonChecker() const;
};
