#include "Game_UI.h"

Game_UI::Game_UI(Font & montserratBold, Font & montserratExtraBold, Texture & logoTexture)
{
	background.setSize(Vector2f(SCRNWIDTH, UI_HEIGHT)); //inicjacja background
	background.setFillColor(Color(11, 46, 89));
	background.setPosition(0.f, 0.f);

	//inicjacja tekstury z logo gry
	logoTexture.setSmooth(true); //dzieki temu tekstura lepiej wyglada i jest wygladzona
	logo.setTexture(logoTexture);
	logo.setPosition(400.f, 0.f);

	//inicjacja autora "Fabian Berda"
	author.setFont(montserratBold);
	author.setString("Fabian Berda");
	author.setCharacterSize(12);
	author.setPosition(100.f, 0);

	//inicjacja napisu score
	score.setFont(montserratExtraBold);
	score.setString("SCORE");
	score.setCharacterSize(24);
	score.setPosition(author.getPosition().x, author.getPosition().y + 30.f);
	score.setFillColor(Color(136, 196, 37));

	scoreReal.setFont(montserratBold); //przygotowanie realnego wyniku sam wypis znajduje sie w osobnej funkcji
	scoreReal.setString("0"); //inicjacja jako 0
	scoreReal.setCharacterSize(32);
	scoreReal.setFillColor(Color(136, 196, 37));
	scoreReal.setPosition(score.getPosition().x, score.getPosition().y + 30.f);
}

Game_UI::~Game_UI()
{
}

void Game_UI::Draw(RenderWindow & window)
{
	window.draw(background);
	window.draw(logo);
	window.draw(author);
	window.draw(score);
	window.draw(scoreReal);
}

void Game_UI::SetScoreOnScene(unsigned int score)
{
	stringstream newScore;
	newScore << score;
	scoreReal.setString(newScore.str());
}
