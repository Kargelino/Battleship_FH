#include "pch.h"
#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::init()
{
	string Name;
	cout << "Spieler 1 Bitte geben sie ihren Namen ein:";
	cin >> Name;
	S1.setName(Name);
	system("cls");
	cout << "Spieler 2 Bitte geben sie ihren Namen ein:";
	cin >> Name;
	S2.setName(Name);
	system("clr");
	S1.SchiffePlatzieren();

}
