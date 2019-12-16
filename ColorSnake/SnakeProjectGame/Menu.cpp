#include "Menu.h"

Menu::Menu(Font & montserratExtraBold, Texture & logoTexture, Texture & buttonTexture)
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

	menu.setFont(montserratExtraBold); //inicjacja napisu gameover
	menu.setString("MAIN MENU");
	menu.setCharacterSize(72);
	menu.setPosition(SCRNWIDTH / 2 - menu.getGlobalBounds().width / 2, logo.getPosition().y + logo.getGlobalBounds().height + 10.f); //ustawienie na srodku wzgledem srodka ekranu
	menu.setFillColor(Color(122, 179, 23));

	buttonTexture.setSmooth(true); //inicjacja guzika 'play'
	button.setTexture(buttonTexture);
	button.setScale(1.5, 1.5);
	button.setPosition(SCRNWIDTH / 2 - button.getGlobalBounds().width / 2, menu.getPosition().y + menu.getGlobalBounds().height + 50.f);

	isButtonClicked = false;
}

Menu::~Menu()
{
}

void Menu::Update(RenderWindow & window)
{
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

void Menu::Draw(RenderWindow & window)
{
	window.draw(background);
	window.draw(logo);
	window.draw(menu);
	window.draw(button);
}

bool Menu::ButtonChecker() const
{
	return isButtonClicked;
}
