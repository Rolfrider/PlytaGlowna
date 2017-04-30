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

float PlytaGlowna::Wprowadzenie_float(string zapytanie)
{
	float wartosc;
	bool blad = true;
	string znaki;
	while (blad)
	{
		cout << zapytanie << endl;
		getline(cin, znaki);
		blad = false;
		for (int i = 0; i < znaki.length(); i++)
		{
			if ((znaki[i] < '0' || znaki[i]>'9') && (znaki[i] != '.'))
				blad = true;
			else
				continue;
		}
	}
	//istringstream iss(znaki);
	//iss >> wartosc;
	wartosc = stof(znaki);
	return wartosc;
}

ostream& operator << (ostream &s, PlytaGlowna &p) {
	s << "Wymiar w mm : " << p.szerokosc << " x " << p.dlugosc << endl;
	s << "Waga : " << p.waga << " gram" << endl;
	return s;
}

istream& operator >> (istream &o, PlytaGlowna &p) {
	p.dlugosc = p.Wprowadzenie_float("Podaj dlugosc plyty");
	p.szerokosc = p.Wprowadzenie_float("Podaj szerokosc plyty");
	p.waga = p.Wprowadzenie_float("Podaj wage plyty");
	return o;
}