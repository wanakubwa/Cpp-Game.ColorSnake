#pragma once
#include <SFML\Graphics.hpp>
#include "Head.h"
#include "Food.h"
#include "Tail.h"
#include "Grid.h"
#include "Game_UI.h"
#include "Settings.h"
#include <vector>

using namespace sf;

class GameMenager
{
	unsigned int score; //wynik aktualizowany dynamicznie pozniej przekazywany w tempo klatki do cout
	unsigned int scoreCount; //przechowywanie wyniku w cely wyswietlenia go dzieki temu prawdziwy wynik moze byc wyzerowany
	unsigned int nextDirection; //kolejny kierunke odczytany z klawitury
	unsigned int prevDirection; //poprzedni kierunek odczytany z klawiatury
	unsigned int winScoreCount; //wynik ktory trzeba uzyskac do wygranej
	bool islive; //czy zyje przydatne jako komunikat do wyswietlenia menusmierci
	bool isHeadMove;
	bool isWin; //czy nie zostaly spelnione warunki zwycieztwa
	bool foodChecker; //czy jedzenie koliduje z ogonem
	int numOfColumns; //liczba kolum 
	int numOfRows; //liczba wierszy
	Time prevMovement; // ms
	Time movementDelay; // ms
	Vector2f gridPosition;
	Vector2f gridSize;

	vector<Tail> vTail; //lista przechowujaca obiekty tail poniewaz mozna nimi latwo zarzadzac oraz dodawac dynamicznie
	vector<Grid> vGrid; //lista przechowujaca obiekty typu grid w celu narysowania siatki
	Food *objFood; //wskaznik na objekt food
	Head *objHead; //wskaznik na objekt glowy
	Game_UI *objUI; //wskaznik na element ui lepszy od wektora w tym przypadku

public:
	GameMenager(Font &montserratBold, Font &montserratExtraBold, Texture &logoTexture);
	~GameMenager();

	void Update(Time &elapsedTime);
	void KeyUpdate();
	void TailUpdate();
	void Draw(RenderWindow &window);
	void IsCollide();
	bool HeadEatFood();
	void BumpScore();
	void GridMaker();
	void FoodCheckPosition();
	void ResetLive();

	//getersy
	bool GetIsLive() const;
	bool GetisWin() const;
	unsigned int GetScoreCount() const;
};