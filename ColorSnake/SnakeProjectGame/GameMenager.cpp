#include "GameMenager.h"

GameMenager::GameMenager(Font & montserratBold, Font & montserratExtraBold, Texture & logoTexture)
{
	objFood = new Food(); //inicjacja wskaznika na food
	objHead = new Head(); //inicjacja wskaznika na head
	objUI = new Game_UI(montserratBold,montserratExtraBold,logoTexture); //inicjacja wskaznika na gameui z przekazaniem adresow czcionek i logo

	prevDirection = 0; //poprzedni kierunek ustawiono domyslnie na 0-'lewo'; 1-prawo; 2-gora; 3-dol
	nextDirection = 0;
	score = 0;
	scoreCount = 0;
	islive = true;
	isHeadMove = false;
	isWin = false;
	numOfColumns = SCRNWIDTH / SIZE;
	numOfRows = SCRNHEIGT / SIZE;
	prevMovement = milliseconds(0); //slyzy do zachowania sumy czasu trwania klatek 
	movementDelay = milliseconds(200); //odstep miedzy "skokiem" czyli wczytaniem kolejnej pozycji glowy
	winScoreCount = numOfColumns*numOfRows - (UI_HEIGHT / SIZE)*(SCRNWIDTH / SIZE) - 1; //inicjacja zmiennej z warunkiem wygranej uzeleznionej od wielkosci ekranu oraz UI
	GridMaker();
}

GameMenager::~GameMenager()
{
	delete objUI; //sprzatanie wskaznikow
	delete objFood;
	delete objHead;
}

void GameMenager::Update(Time & elapsedTime)
{
	KeyUpdate();
	objFood->ChangeColor();
	prevMovement += elapsedTime;

	if (prevMovement >= movementDelay) //warunek synchronizacji
	{
		IsCollide();
		TailUpdate();
		objHead->Update(elapsedTime, nextDirection);
		if (HeadEatFood())
		{
			objFood->Update();
			FoodCheckPosition();
			BumpScore();
			if (score == winScoreCount) //sprawdzenie czy nie wygrana -1 poniewaz glowa zajmuje jedna kratke
			{
				isWin = true;
				score = 0;
				vTail.clear();
			}
				
		}

		isHeadMove = true; //warunek do narysowania siatki
		prevMovement -= movementDelay; //wyzerownie czasu klatki
	}
}

void GameMenager::KeyUpdate()
{
	if (Keyboard::isKeyPressed(Keyboard::A)||Keyboard::isKeyPressed(Keyboard::Left)) //sterowanie w,s,a,d lub strzalkami
	{
		if (objHead->GetPrevDirection() != 1) //nie jest mozliwe najechanie na siebie ruchem wstecz
			this->nextDirection = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (objHead->GetPrevDirection() != 0)
			this->nextDirection = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (objHead->GetPrevDirection() != 3)
			this->nextDirection = 2;
	}

	if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
	{
		if (objHead->GetPrevDirection() != 2)
			this->nextDirection = 3;
	}
}

void GameMenager::TailUpdate()
{
	if (score == vTail.size())
	{
		for (int i = 0; i < (int)vTail.size() - 1; i++)
		{
			vTail.at(i).SetTailPosition(vTail.at(i + 1).GetPositionX(), vTail.at(i + 1).GetPositionY()); //przesuniecie polozenia obiektow
		}
	}
	else
	{
		Tail newTail;
		vTail.push_back(newTail); //powiekszenie obiektow w wektorze vTail
		vTail.back().SetTailColor(vTail.size());
		objHead->ChangeColor(vTail.back().GetTailColor()); //zmiena koloru glowy na kolor nowego elementu ogona
	}

	if (score>0)
	{
		vTail.at(score - 1).SetTailPosition(objHead->GetPositionX(), objHead->GetPositionY()); //aktualizacja pozycji obiektu pierwszego
	}
}

void GameMenager::Draw(RenderWindow & window)
{
	for (int i = 0; i < vTail.size(); i++)
	{
		vTail.at(i).Draw(window);
	}

	objFood->Draw(window);
	objHead->Draw(window);
	
	for (int i = 0; i < vGrid.size(); i++)
	{
		vGrid.at(i).Draw(window);
	}

	objUI->Draw(window);
}

void GameMenager::IsCollide()
{
	for (int i = 0; i < vTail.size(); i++)
	{
		if (objHead->GetPositionX() == vTail.at(i).GetPositionX() && 
			objHead->GetPositionY() == vTail.at(i).GetPositionY())
		{
			vTail.clear(); //czyszcenie listy z ogonem
			score = 0;
			islive = false;
			//nadaj komunikat o smierci
		}
	}
	
		if (objHead->GetPositionX() < 0 || objHead->GetPositionY() < UI_HEIGHT ||
			objHead->GetPositionX() >= SCRNWIDTH || objHead->GetPositionY() >= SCRNHEIGT) //jezeli glowa poza ekranem ginie lub gracz wjedzie pod ui
		{
			if (vTail.size() > 0)
				vTail.clear(); //czyszczenie listy z ogonem
				score = 0;
				islive = false;
			//nadaj komunikat o smierci
		}
}

bool GameMenager::HeadEatFood()
{
	
	if(objFood->GetPositionX() == objHead->GetPositionX() && objFood->GetPositionY() == objHead->GetPositionY()) //wykrycie kolizji nie jest potrzebna synchronizacja za pomoca zmiennej poniewaz pozycja head podmieniana jest w tempo wejscia klatki
	{
		return true;
	}

	return false;
}

void GameMenager::BumpScore()
{
	score++;
	scoreCount++;
	objUI->SetScoreOnScene(score);
}

void GameMenager::GridMaker()
{
	for (int i = 0; i < numOfColumns; i++)
	{
		gridPosition = Vector2f(i*SIZE, 0);
		gridSize = Vector2f(1,SCRNHEIGT);
		Grid newgrid(gridPosition,gridSize);
		vGrid.push_back(newgrid);
	}
	for (int i = 0; i < numOfRows; i++)
	{
		gridPosition = Vector2f(0, i*SIZE);
		gridSize = Vector2f(SCRNWIDTH, 1);
		Grid newgrid(gridPosition, gridSize);
		vGrid.push_back(newgrid);
	}
}

void GameMenager::FoodCheckPosition()
{
	int i = 0;
	foodChecker = false; //nie koliduje pozycja startowa
	if (objHead->GetPositionX() == objFood->GetPositionX() && objHead->GetPositionY() == objFood->GetPositionY())
		foodChecker = true;
	while (i<vTail.size() && !foodChecker)
	{
		if (objFood->GetPositionX() == vTail.at(i).GetPositionX() && objFood->GetPositionY() == vTail.at(i).GetPositionY())
			foodChecker = true; //warunek przerwania petli
		i++;
	}
	if (foodChecker)
	{
		objFood->Update();
		FoodCheckPosition(); //ponowne sprawdzenie czy nie koliduje po zmianie
	}
}

void GameMenager::ResetLive()
{
	islive = true;
	isWin = false;
	scoreCount = 0;
	objUI->SetScoreOnScene(score);
	objHead->RestartHead();
}

bool GameMenager::GetIsLive() const
{
	return islive;
}

bool GameMenager::GetisWin() const
{
	return isWin;
}

unsigned int GameMenager::GetScoreCount() const
{
	return scoreCount;
}
