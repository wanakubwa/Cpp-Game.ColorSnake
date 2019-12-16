#include "Food.h"

Food::Food()
{
	size = SIZE;
	srand(time(NULL));
	food.setSize(Vector2f(SIZE, SIZE));
	food.setFillColor(Color::Magenta);
	numOfColumns = SCRNWIDTH / size; //przeniesione zostanie do fukncji menager
	numOfRows = (SCRNHEIGT-UI_HEIGHT) / size;
	PickRandPosition();
	food.setPosition(position);
	actualFrame = 0;
}

Food::~Food()
{
}

void Food::Update()
{
		PickRandPosition();
		food.setPosition(position);
}

void Food::Draw(RenderWindow & window)
{
	window.draw(food);
}

void Food::PickRandPosition() //wybor losowej pozycji
{
	position = Vector2f((rand() % numOfColumns)*size, (rand() % numOfRows)*size+UI_HEIGHT); //wybor pozycjii tak aby pasowala to siatki
}

void Food::ChangeColor() //funkcja losowania koloru aby jedzenie migalo 
{
	int random = rand() % 500; //500 dlatego aby wszystkie kolory byly widoczne dosc czasu 

	switch (random % 25)
	{
	case 0:
		foodColor = Color(0, 203, 231);
		break;
	case 1:
		foodColor = Color(223, 21, 26);
		break;
	case 2:
		foodColor = Color(253, 134, 3);
		break;
	case 3:
		foodColor = Color(244, 243, 40);
		break;
	case 4:
		foodColor = Color(0, 218, 60);
		break;
	default:
		break;
	}
		foodColor.a = 255;
		food.setFillColor(foodColor);
		actualFrame++;
}

float Food::GetPositionX() const
{
	return position.x;
}

float Food::GetPositionY() const
{
	return position.y;
}
