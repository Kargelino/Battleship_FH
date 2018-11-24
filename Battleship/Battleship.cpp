#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
char cEfeld[9][10];// fEINDLICHES FELD SICHTBAR
char cMfeld[9][10];//Mein Feld
char vMirror[9][10];// Feindliches feld unsichbar
int im = 0, ki = 0;// schiffe getroffen
void showf();//zeige felder
void filfelds();//fuhle felder mit werten
void mships();//meine schiffe platzieren
int setposs(char v, char h, int con);//setze werte in felder
void battle();//Feuer auf positionen
void kiship();//KI setz schiffe auf vMirror
void kifire();// KI feuert
int main()
{
	srand((unsigned)time(NULL));
	filfelds();
	showf();
	mships();
	kiship();
	while (true)
	{
		battle();
		if (ki == 5)
		{
			cout << "KI gewonnen.exit.";
			return 0;
		}
		else if (im == 5)
		{
			cout << "Sie haben gewonnen.";
			return 0;
		}
	}
}

void kifire()
{
	int v, h, z = 0;
	while (z == 0)
	{
		v = 1 + rand() % 10;
		h = 1 + rand() % 9;
		if (cMfeld[v][h] == '.')
		{
			cMfeld[v][h] = '0';
			z = 1;
		}
		else if (cMfeld[v][h] == '0')
		{
			z = 0;
		}
		else if (cMfeld[v][h] == '%')
		{
			z = 0;
		}
		else if (cMfeld[v][h] == '#')
		{
			cMfeld[v][h] = '%';
			ki++;
			z = 1;
		}
	}
}

void battle()
{
	char v, h;
	cout << "Feuer auf Posizion :";
	cin >> h;
	cin >> v;
	if (h < 'A' || h > 'I')
	{
		cout << "Falsche Koordinaten." << endl;
	}
	else if (v < '1' || v > '8')
	{
		cout << "Falsche Koordinaten." << endl;
	}
	else
	{
		setposs(v, h, 1);
		if (im == 5)
		{
			showf();
		}
		else if (ki == 5)
		{
			showf();
		}
		else
		{
			kifire();
			showf();
		}
	}
}

void kiship()
{
	int z = 5, v, h;
	while (z != 0)
	{
		v = 1 + rand() % 10;
		h = 1 + rand() % 9;
		if (vMirror[v][h] == '.')
		{
			vMirror[v][h] = '#';
			z--;
		}
	}
}

int setposs(char v, char h, int con)
{
	int vv, hh;
	if (h == 'A')
		hh = 1;
	if (h == 'B')
		hh = 2;
	if (h == 'C')
		hh = 3;
	if (h == 'D')
		hh = 4;
	if (h == 'E')
		hh = 5;
	if (h == 'F')
		hh = 6;
	if (h == 'G')
		hh = 7;
	if (h == 'H')
		hh = 8;
	if (h == 'I')
		hh = 9;
	if (v == '1')
		vv = 1;
	if (v == '2')
		vv = 2;
	if (v == '3')
		vv = 3;
	if (v == '4')
		vv = 4;
	if (v == '5')
		vv = 5;
	if (v == '6')
		vv = 6;
	if (v == '7')
		vv = 7;
	if (v == '8')
		vv = 8;
	if (con == 0)
	{
		if (cMfeld[vv][hh] == '.')
		{
			cMfeld[vv][hh] = '#';
			return 0;
		}
		else
			return 1;
	}
	if (con == 1)
	{
		if (vMirror[vv][hh] == '.')
			cEfeld[vv][hh] = '0';
		if (vMirror[vv][hh] == '#')
		{
			cEfeld[vv][hh] = '%';
			vMirror[vv][hh] = '%';
			im++;
		}
	}
	return 0;
}

void mships()
{
	int ships = 5;
	char v, h;
	while (ships != 0)
	{
		cout << "\nSchiffe platzieren:" << endl;
		cout << "Noch " << ships << " übrig\n";
		cout << ">";
		cin >> h;
		if (h < 'A' || h > 'I')
		{
			cout << "Falsche Koordinaten." << endl;
		}
		else
		{
			cin >> v;
			if (v < '1' || v > '8')
			{
				cout << "Falsche Koordinaten.\n";
			}
			else
			{
				int p = setposs(v, h, 0);
				if (p == 0)
				{
					ships--;
					showf();
				}
				else
				{
					cout << "Falsche Koordinaten.\n";
				}
			}
		}
	}
}

void showf()
{
	cout << "Meine Karte" << endl;
	for (int z = 0; z < 9; z++)
	{
		for (int k = 0; k < 10; k++)
		{
			cout << cMfeld[z][k] << " ";
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
	cout << "Feind Karte" << endl;
	for (int z = 0; z < 9; z++)
	{
		for (int k = 0; k < 10; k++)
		{
			cout << cEfeld[z][k] << " ";
		}
		cout << endl;
	}
}

void filfelds()
{
	char v = '0';
	char h = 'A';
	for (int z = 0; z < 9; z++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (k == 0)
			{
				cEfeld[z][k] = v;
				cMfeld[z][k] = v;
				vMirror[z][k] = v;
				v++;
			}
			else if (z == 0)
			{
				cEfeld[z][k] = h;
				cMfeld[z][k] = h;
				vMirror[z][k] = h;
				h++;
			}
			else
			{
				cEfeld[z][k] = '.';
				cMfeld[z][k] = '.';
				vMirror[z][k] = '.';
			}
			cEfeld[0][0] = ' ';
			cMfeld[0][0] = ' ';
		}
	}
}