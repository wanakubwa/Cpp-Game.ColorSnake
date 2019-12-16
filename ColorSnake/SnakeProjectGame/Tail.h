#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"

using namespace sf;

class Tail
{
	RectangleShape tail;
	Vector2f position;

public:
	Tail();
	~Tail();

	void Update(Time &elapsedTime);
	void Draw(RenderWindow &window);
	void SetTailPosition(float x, float y);
	void SetTailColor(int tailLenght);

	Color GetTailColor() const;
	float GetPositionX() const;
	float GetPositionY() const;
};