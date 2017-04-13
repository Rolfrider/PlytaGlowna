#include "stdafx.h"
#include "SzynaPamieci.h"
#include<iostream>

#ifdef _DEBUG
#define DEBUG(x)
#else
#define DEBUG(x) cout<<x<<endl;
#endif // _DEBUG

Taktowanie SzynaPamieci::taktowanie = losujTaktowanie();

//konstruktory
SzynaPamieci::SzynaPamieci()
{
	DEBUG("Tworze szyne pamieci")

	producent = "RASUS";
	pojemnosc = losujPojemnosc();
}
//operatory
ostream& operator<<(ostream &o, SzynaPamieci &s) {
	o << "Kosc pamieci RAM" << endl;
	o << "Producent : " << s.producent << endl;
	o << "Taktowanie pamieci : " << s.taktowanie << endl;
	o << "Pojemnosc : " << s.pojemnosc << " GB" << endl;
	return o;
}
/*
SzynaPamieci& SzynaPamieci::operator=(SzynaPamieci &s) {
	producent = s.producent;
	taktowanie = s.taktowanie;
	pojemnosc = s.pojemnosc;
	return *this;
}*/
//metody
void SzynaPamieci::PrzetaktujGora(SzynaPamieci &ram) {
	if (ram.taktowanie == Niskie)
		ram.taktowanie = Srednie;
	else if (ram.taktowanie == Srednie)
		ram.taktowanie = Wysokie;
	else
		cout << "Jest to najwyzsze mozliwe taktowanie" << endl;
}
void SzynaPamieci::PrzetaktujDol(SzynaPamieci &ram) {
	if (ram.taktowanie == Wysokie)
		ram.taktowanie = Srednie;
	else if (ram.taktowanie == Srednie)
		ram.taktowanie = Niskie;
	else
		cout << "Jest to najnizsze mozliwe taktowanie" << endl;
}
Pojemnosc SzynaPamieci::losujPojemnosc() {
	int a = (rand() % 3 + 1);
	switch (a) {
	case 1:
		return Mala;
		break;
	case 2:
		return Srednia;
		break;
	case 3:
		return Duza;
		break;
	default:
		return Srednia;
	}
}
Taktowanie SzynaPamieci::losujTaktowanie() {
	int a = (rand() % 3 + 1);
	switch (a) {
	case 1:
		return Niskie;
		break;
	case 2:
		return Srednie;
		break;
	case 3:
		return Wysokie;
		break;
	default:
		return Srednie;
	}
}
SzynaPamieci::~SzynaPamieci()
{
	DEBUG("Niszcze szyne pamieci")

}
