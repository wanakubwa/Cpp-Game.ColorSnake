#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"

using namespace sf;

class Menu
{
	RectangleShape background; //tlo niebieskie
	Sprite logo; //logo
	Sprite button; //guzki 'play'
	Text menu; //napis menu

	bool isButtonClicked; //zmienna informujaca czy uruchomic gre

public:
	Menu(Font & montserratExtraBold, Texture & logoTexture, Texture &buttonTexture);
	~Menu();

	void Update(RenderWindow &window);
	void Draw(RenderWindow &window);
	bool ButtonChecker() const;
};
