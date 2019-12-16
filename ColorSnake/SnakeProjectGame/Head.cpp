#include "Head.h"

Head::Head()
{
	speed = SIZE; //speed = size 
	head.setSize(Vector2f(SIZE, SIZE));
	head.setFillColor(Color(0, 255, 0, 200));
	position = Vector2f(SCRNWIDTH/2, (SCRNHEIGT + UI_HEIGHT) /2); //ustawienie na srodku ekranu - pozycja startowa z uwzglednieniem gameUI
	head.setPosition(position);
}

Head::~Head()
{
}

void Head::Update(Time &elapsedTime, unsigned int nextDirection)
{
		Vector2f movement(0.f, 0.f); //wektor przesuniecia deklarowany jako 0,0

		switch (nextDirection)
		{
		case 0:
			movement.x -= speed;
			break;
		case 1:
			movement.x += speed;
			break;
		case 2:
			movement.y -= speed;
			break;
		case 3:
			movement.y += speed;
			break;
		default:
			break;
		}

		head.move(movement);
		position = head.getPosition(); //wykorzystywane dla namierzenia przesuniecia glowy w poprzedniej/nastepnej klatce
		prevDirection = nextDirection; //aktualny staje sie poprzednim
}

void Head::Draw(RenderWindow & window)
{
		window.draw(head);
}

void Head::SetDirection(unsigned int nextDirection)
{
	this->nextDirection = nextDirection;
}

void Head::ChangeColor(Color newHeadColor)
{
	newHeadColor.a = 200;
	head.setFillColor(newHeadColor);
}

void Head::RestartHead()
{
	position = Vector2f(SCRNWIDTH / 2, (SCRNHEIGT + UI_HEIGHT) / 2); //ustawienie na srodku ekranu - pozycja startowa z uwzglednieniem gameUI
	head.setPosition(position);
	head.setFillColor(Color(0, 255, 0, 200));
}

unsigned int Head::GetPrevDirection() const
{
	return prevDirection;
}

float Head::GetPositionX() const
{
	return position.x;
}

float Head::GetPositionY() const
{
	return position.y;
}

