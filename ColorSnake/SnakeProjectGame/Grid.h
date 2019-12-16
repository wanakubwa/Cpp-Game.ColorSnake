#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"

using namespace sf;

class Grid
{
	RectangleShape grid;

public:
	Grid(Vector2f position,Vector2f size);
	~Grid();

	void Draw(RenderWindow &window);
};