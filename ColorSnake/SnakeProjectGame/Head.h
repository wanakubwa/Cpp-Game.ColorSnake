#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"

using namespace sf;

class Head
{
	RectangleShape head;
	float speed;
	unsigned int nextDirection;
	unsigned int prevDirection;
	Vector2f position;

public:
	Head();
	~Head();

	void Update(Time &elapsedTime, unsigned int direction);
	void Draw(RenderWindow &window);
	void SetDirection(unsigned int nextDirection);
	void ChangeColor(Color newHeadColor);
	void RestartHead();

	unsigned int GetPrevDirection() const;
	float GetPositionX() const;
	float GetPositionY() const;
};