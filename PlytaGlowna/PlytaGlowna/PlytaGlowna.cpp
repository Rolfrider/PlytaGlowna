#include "stdafx.h"
#include "PlytaGlowna.h"




PlytaGlowna::PlytaGlowna()
{
}


PlytaGlowna::~PlytaGlowna()
{
}

ostream& operator << (ostream &s, PlytaGlowna &p) {
	s << "Wymiar w mm : " << p.szerokosc << " x " << p.dlugosc << endl;
	s << "Waga : " << p.waga << " gram" << endl;
	return s;
}

istream& operator >> (istream &o, PlytaGlowna &p) {
	cout << "Podaj dlugosc plyty" << endl;
	o >> p.dlugosc;
	cout << "Podaj szerokosc plyty" << endl;
	o >> p.szerokosc;
	cout << "Podaj wage plyty" << endl;
	o >> p.waga;
	return o;
}