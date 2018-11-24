#pragma once
class Feld
{
public:
	Feld();
	~Feld();
	char fieldinfo();
	void setfieldshoot();
	void setfieldshiff();
	void setfielddestroy();

private:

	char water = ' ';
	char Shot = 'x';

	char Schiff_OK = 'S';
	char Schiff_Hit = 'H';

	char Destroyed = 'D';
	char state = water;
};

