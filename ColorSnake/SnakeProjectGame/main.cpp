#include <SFML\Graphics.hpp>
#include "MainGame.h"

using namespace std;


int main()
{
	MainGame game; //stworzenie obiektu sterujacego gra
	if (game.LoadPrefabs()) //inicjacja ladowania assetow jezeli zaladowaly sie poprawnie program rusza w przeciwnym razie informacja bedzie w konsoli
		game.Initialize(); //rozpoczecie gamemainloop

	return 0;
}