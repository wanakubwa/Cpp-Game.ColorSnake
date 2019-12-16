#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"
#include <sstream>

using namespace sf;
using namespace std;

class Game_UI
{
	RectangleShape background; //tlo UI czyli prostokat 50x600
	Sprite logo; //logo gry zeby ladniej wygladala calosc
	Text score;
	Text scoreReal;
	Text author;
	Font montserratBold;
	Font montserratExtraBold;

	Texture logoTexture;

public:
	Game_UI(Font &montserratBold, Font &montserratExtraBold, Texture &logoTexture);
	~Game_UI();

	void Draw(RenderWindow &window);
	void SetScoreOnScene(unsigned int score);
};