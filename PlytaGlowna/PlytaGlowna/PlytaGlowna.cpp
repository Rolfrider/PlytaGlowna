#include "stdafx.h"
#include "PlytaGlowna.h"




PlytaGlowna::PlytaGlowna()
{
}


PlytaGlowna::~PlytaGlowna()
{
}

void PlytaGlowna::CzyszczenieBufora() {
	cin.clear();
	cin.sync();
}
int PlytaGlowna::Wprowadzanie_inta(string zapytanie)
{
	int wartosc;
	bool blad = true;
	string znaki;
	while (blad)
	{
		cout << zapytanie << endl;
		getline(cin, znaki);
		blad = false;
		for (int i = 0; i < znaki.length(); i++)
		{
			if (znaki[i] < '0' || znaki[i]>'9')
				blad = true;
			else
				continue;
		}
	}
	istringstream iss(znaki);
	iss >> wartosc;
	return wartosc;
}