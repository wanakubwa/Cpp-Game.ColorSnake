#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"
#include <random>

using namespace sf;

class Food
{
	RectangleShape food;
	Vector2f position; //wektor przechowujacy zmienne typu int pozycja jedzenia ma sztywna wartosc na siatce gry
	float size; //predkosc poruszania jest jednoczesnie wielkoscia obiektow 
	int numOfColumns;
	int numOfRows;
	unsigned int score;
	int actualFrame;
	Color foodColor;
	

public:
	Food();
	~Food();

	//void Update(Time &elapsedTime, Head &head);
	void Update();
	void Draw(RenderWindow &window);
	void PickRandPosition();
	void ChangeColor(); //miganie kolorow jedzenia

	float GetPositionX() const;
	float GetPositionY() const;
};