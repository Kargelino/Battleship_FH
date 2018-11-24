#pragma once
#include <string>
using namespace std;

class Ship
{
public:
	Ship();
	~Ship();
	int size;
	int moeglicheAnzahl;
	string getName();

protected:
	int kammer;
	string Type;
};

