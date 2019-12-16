#include "MainGame.h"

MainGame::MainGame()
{
	gameMode = 0;
	loadChecker = true;
	MySettings.antialiasingLevel = 8; //wygladzanie krawedzi bez tego sa one postrzepione
	window.setFramerateLimit(30); //ustawienie klatek na 30
	elapsedTime = clock.restart();
}

MainGame::~MainGame()
{
	delete objMenager; //trzeba posprzatac wskazniki
	delete objDeadMenu;
	delete objMenu;
	delete objWinMenu;
}

void MainGame::Initialize()
{
	window.create(VideoMode(SCRNWIDTH, SCRNHEIGT), "SNAKE THE GAME by. FB!", Style::Close | Style::Titlebar, MySettings); //glowne ustawienie okna
	objMenager = new GameMenager(montserratBold,montserratExtraBold,logoTexture); //wskazniki tworzone w tym miejscu poniewaz wczesniej potrzebne wywolanie ladowania
	objDeadMenu = new DeadMenu(montserratBold, montserratExtraBold, logoTexture, buttonTexture); //wskaznik na deadmenu
	objMenu = new Menu(montserratExtraBold, logoTexture, buttonTexture); //inicjacja wskaznika na obiekt menu
	objWinMenu = new WinMenu(montserratBold, montserratExtraBold, logoTexture, buttonTexture); //inicjacja wskaznika na obiekt winmenu

	while (window.isOpen()) //maingameloop
	{
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed) //jezeli kliknieto x zakoncz petle i zamknij okno
				window.close();
		}
		elapsedTime = clock.restart(); //licznik czasu jednej klatki
		CheckNextFrameMode();

		switch (gameMode) //switch przydzielajacy prawo do wyswietlenia danej sceny w zaleznosci od okolicznosci
		{
		case 0:
			objMenu->Update(window);
			window.clear();
			objMenu->Draw(window);
			break;
		case 1:
			objMenager->Update(elapsedTime);
			window.clear();
			objMenager->Draw(window);
			break;
		case 2:
			objDeadMenu->Update(window,objMenager->GetScoreCount());
			window.clear();
			objDeadMenu->Draw(window);
			break;
		case 3:
			objWinMenu->Update(window, objMenager->GetScoreCount());
			window.clear();
			objWinMenu->Draw(window);
			break;
		default:
			break;
		}

		window.display(); //wyswietlenie bufora
	}
}

void MainGame::CheckNextFrameMode() //sprawdzanie czy nie zmienily sie zmienne aby ustawic nastepna klatke todo switch
{
	if (objMenu->ButtonChecker()) //jezeli w menu i guzik nacisniety rozpocznij gre
		gameMode = 1;
	if (objMenager->GetisWin()) //jezeli w grze i wygrywa winmenu
		gameMode = 3;
	if (!objMenager->GetIsLive()) //jezeli smierc ded menu
		gameMode = 2;
	if (objDeadMenu->ButtonChecker()) //jezeli w dedmenu i nacisniety guzik przejdz i zresetuj gre
	{
		objDeadMenu->RestartDeadMenu();
		objMenager->ResetLive();
		gameMode = 1;
	}
	if (objWinMenu->ButtonChecker()) //jezeli w winmenu i nacisniety guzik przejdz i zresetuj gre
	{
		objWinMenu->RestartWinMenu();
		objMenager->ResetLive();
		gameMode = 1;
	}
		
}

bool MainGame::LoadPrefabs() //ladowanie zewnetrznych assetow
{
	if (!logoTexture.loadFromFile("Textures/snake_logo.png")) //oblusga bledow wbudowana jezeli ktorys z plikow zle sie zaladuje informacja bedzie w konsoli
		loadChecker = false;

	if (!buttonTexture.loadFromFile("Textures/button.png"))
		loadChecker = false;

	if (!montserratBold.loadFromFile("Fonts/Montserrat-Bold.otf"))
		loadChecker = false;

	if (!montserratExtraBold.loadFromFile("Fonts/Montserrat-ExtraBold.otf"))
		loadChecker = false;

	if (loadChecker)
		return true;

	return false;
}
