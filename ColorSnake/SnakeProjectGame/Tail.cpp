#include "Tail.h"

Tail::Tail()
{
	this->tail.setOutlineThickness(-2.f);
	this->tail.setSize(Vector2f(SIZE, SIZE));
}

Tail::~Tail()
{
}

void Tail::Update(Time & elapsedTime)
{
}

void Tail::Draw(RenderWindow & window)
{
	window.draw(tail);
}

void Tail::SetTailPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
	this->tail.setPosition(position);
}

void Tail::SetTailColor(int tailLenght) //funkcja wybierajaca kolor ogona zaleznie od jego dlugosci 
{
	Color thisTailColor;

	switch ((tailLenght % 150) / 25) //po 150 ogonach kolory zaczynaja od poczatku sekwencje, dzieki temu przejscie bd delikatne miedzy kolorami
	{
	case 0:
		thisTailColor = Color(0,255, 10 * (tailLenght % 25)); //pojedyncza wartosc nie bedzie wieksza niz 255, skladowa b rosnie do 255
		break;
	case 1:
		thisTailColor = Color(0,255 - 10 * (tailLenght % 22),255); //skladowa r spada do zera
		break;
	case 2:
		thisTailColor = Color(10 * (tailLenght % 25),0,255);//skladowa g rosnie do 255
		break;
	case 3:
		thisTailColor = Color( 255,0, 255 - 10 * (tailLenght % 25));//skladowa b spada do 0
		break;
	case 4:
		thisTailColor = Color(255,10 * (tailLenght % 25), 0);//skladowa r rosnie do 255
		break;
	case 5:
		thisTailColor = Color(255 - 10 * (tailLenght % 25),255,0); //skladowa g spada do 0 czyli stanu poczatkowego z jakiego zaczynal kolor
		break;

	}
	thisTailColor.a = 60;
	this->tail.setFillColor(thisTailColor);
	thisTailColor.a = 80;
	this->tail.setOutlineColor(thisTailColor);
}

Color Tail::GetTailColor() const
{

	return this->tail.getFillColor();
}

float Tail::GetPositionX() const
{
	return this->position.x;
}

float Tail::GetPositionY() const
{
	return this->position.y;
}
