#include "WinMenu.h"

WinMenu::WinMenu(Font & montserratBold, Font & montserratExtraBold, Texture & logoTexture, Texture & buttonTexture)
{
	background.setPosition(0.f, 0.f);
	background.setFillColor(Color(11, 46, 89));
	background.setOutlineThickness(-10.f);
	background.setOutlineColor(Color(11, 46, 150));
	background.setSize(Vector2f(SCRNWIDTH, SCRNHEIGT));

	logoTexture.setSmooth(true); //ustawienie wygladzenia pomagajace w skalowaniu aby textura ladnie wygladala
	logo.setTexture(logoTexture);
	logo.setScale(2, 2);
	logo.setPosition(SCRNWIDTH / 2 - logo.getGlobalBounds().width / 2, 25.f); //dokladny srodek ekranu

	wictory.setFont(montserratExtraBold); //inicjacja napisu wictory
	wictory.setString("WICTORY");
	wictory.setCharacterSize(72);
	wictory.setPosition(SCRNWIDTH / 2 - wictory.getGlobalBounds().width / 2, logo.getPosition().y + logo.getGlobalBounds().height + 10.f); //ustawienie na srodku wzgledem srodka ekranu
	wictory.setFillColor(Color(122, 179, 23));

	score.setFont(montserratBold); //inicjacja liczby punktow bez podawania wypelnienia stringiem poniewaz przyjdzie w momencie smierci
	score.setCharacterSize(54);
	score.setString("0");
	score.setPosition(SCRNWIDTH / 2 - score.getGlobalBounds().width / 2, wictory.getPosition().y + wictory.getGlobalBounds().height + 25.f); //ustawienie na srodku wzgledem srodka ekranu
	score.setFillColor(Color(122, 179, 23));

	buttonTexture.setSmooth(true); //inicjacja guzika 'play'
	button.setTexture(buttonTexture);
	button.setScale(1.5, 1.5);
	button.setPosition(SCRNWIDTH / 2 - button.getGlobalBounds().width / 2, score.getPosition().y + score.getGlobalBounds().height + 50.f);

	isButtonClicked = false;
}

WinMenu::~WinMenu()
{
}

void WinMenu::Update(RenderWindow & window, unsigned int scoreGame)
{
	stringstream streamScore;
	streamScore << scoreGame;
	score.setString(streamScore.str());

	if (button.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) //sprawdzenie czy kursor myszy nie najechal na guzik
	{
		button.setColor(Color(255, 255, 255, 150)); //jezeli tak zmiena graficzna
		if (Mouse::isButtonPressed(Mouse::Left)) //sprawdzenie czy kursor nie naciska guzika
		{
			isButtonClicked = true;
		}
	}
	else
	{
		button.setColor(Color(255, 255, 255, 255)); //jezeli mysz nie najezdza na guzik lub byla na nim ale uzytkownik nie kliknal przyrwaca domyslny wyglad
	}
}

void WinMenu::Draw(RenderWindow & window)
{
	window.draw(background);
	window.draw(logo);
	window.draw(wictory);
	window.draw(button);
	window.draw(score);
}

void WinMenu::RestartWinMenu()
{
	isButtonClicked = false;
}

bool WinMenu::ButtonChecker() const
{
	return isButtonClicked;
}
