#pragma once
#include <string>
#include "Grid.h"
#include <vector>
#include "Ship.h"
#include "Frigatte.h"
#include "Kreuzer.h"
#include <iostream>
using namespace std;

class Spieler
{
public:
	Spieler();
	~Spieler();
	Grid own;
	Grid enemy;
	string getName();
	void setName(string Name);
	void SchiffePlatzieren();

private:
	string Name;
	vector<Ship*> frei_Schiffe;
	void platziereSchiffe(int Type,int x,int y);
	int umwandlungXAchse(char X);
};

