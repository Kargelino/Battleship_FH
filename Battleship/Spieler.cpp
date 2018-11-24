#include "pch.h"
#include "Spieler.h"




Spieler::Spieler()
{
}

Spieler::~Spieler()
{
}

string Spieler::getName()
{
	return this->Name;
}

void Spieler::setName(string Name)
{
	this->Name = Name;
	Ship *Shif1 = new Frigatte;
	Ship *Shif2 = new Kreuzer;
	frei_Schiffe.push_back(Shif1);
	frei_Schiffe.push_back(Shif2);
}

void Spieler::SchiffePlatzieren()
{
	while (true) 
	{
		for (auto schiffi : frei_Schiffe) 
		{
			while (schiffi->moeglicheAnzahl > 0) 
			{
					system("cls");
					cout << "\n   Spieler: " << this->Name << endl;
					own.print_grid();
					char X;
					int Y;
					cout << "\n Bitte Plazieren sie ihren " << schiffi->getName() << endl;
					cout << "X-Achse:";
					cin >> X;
					cout << "Y-Achse:";
					cin >> Y;
					try {
						int x = umwandlungXAchse(X);
						platziereSchiffe(schiffi->size, x, Y);
						schiffi->moeglicheAnzahl--;
					}
					catch (const char* Fehler) {
						cerr << Fehler << endl;
						system("Pause");
					}
			}
		}
	}
}

void Spieler::platziereSchiffe(int Type, int x, int y)
{
	int i = (Type / 2) + 1;
	if (0 > (x-i) || 9 < (x+i)) 
	{
			throw "Falsche position";
	}
	for (int j = 0; j < Type; j++) {
		own.update(1, y, (x - i) + j);
	}

}

int Spieler::umwandlungXAchse(char X)
{
	int i = 0;
	switch (X)
	{
	case 'A':i = 0; break;
	case 'B':i = 1; break;
	case 'C':i = 2; break;
	case 'D':i = 3; break;
	case 'E':i = 4; break;
	case 'F':i = 5; break;
	case 'G':i = 6; break;
	case 'H':i = 7; break;
	case 'I':i = 8; break;
	case 'J':i = 9; break;
	default:throw "Kein Grossbuchstaben erkannt";
	}
	return i;

}
