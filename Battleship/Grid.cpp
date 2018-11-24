#include "pch.h"
#include "Grid.h"


Grid::Grid()
{

	for (int i = 0; i < FeldGroesse; i++) {

		vector<Feld*> Test;
		for (int j = 0; j < FeldGroesse; j++)
		{
			Feld *Test1 = new Feld;
			Test.push_back(Test1);
		}
		feld.push_back(Test);
	}
}

Grid::~Grid()
{
}

void Grid::update(int state, int x, int y)
{
	if (state == 1) {
		feld[x][y]->setfieldshiff();
	}
}

void Grid::print_grid()
{
	cout << "--------------------------\n";
	cout << "   A B C D E F G H I J \n";
	int i = 0;
	for (auto Y : feld) {
		cout << "|" << i++ << "   ";
		for (auto X : Y) {
			cout << X->fieldinfo() << " ";
		}
		cout << "|" << endl;
	}
	cout << "--------------------------\n";

}
