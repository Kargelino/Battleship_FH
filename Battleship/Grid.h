#pragma once
#include <vector>
#include "Feld.h"
#include <string>
#include <iostream>
#define FeldGroesse 10

using namespace std;

class Grid
{
public:
	Grid();
	~Grid();
	void update(int state, int x, int y);
	void check_Schiff();
	void print_grid();

private:


	vector<vector<Feld*>> feld;
	
};

