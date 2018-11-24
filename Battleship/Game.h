#pragma once
#include "Spieler.h"
#include <string>
#include <iostream>

class Game
{
public:
	Game();
	~Game();
	Spieler S1;
	Spieler S2;

	void init();
};

