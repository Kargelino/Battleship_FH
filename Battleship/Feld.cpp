#include "pch.h"
#include "Feld.h"


Feld::Feld()
{
}


Feld::~Feld()
{
}

char Feld::fieldinfo()
{
	return this->state;
}

void Feld::setfieldshoot()
{
	switch (this->state)
	{
	case ' ':this->state = this->Shot; break;
	case 'S':this->state = this->Schiff_Hit; break;
	default:break;
	}
}

void Feld::setfieldshiff()
{
	if (state != ' ') {
		throw "An der Position ist schon ein Shiff\n";
	}
	this->state = this->Schiff_OK;
}

void Feld::setfielddestroy()
{
	this->state = this->Destroyed;
}
