#pragma once
#include "PlytaStacjonarna.h"

typedef string kolor;
class PlytaGamingowa :
	public PlytaStacjonarna
{
	kolor podswietlenieRGB;
	string cechySzczegolne;
	bool wsparcieVR;
	bool nvidiaSLI;
	string material;
public:
	PlytaGamingowa();
	~PlytaGamingowa();
	friend ostream& operator<< (ostream &s, PlytaGamingowa &p);
	friend istream& operator >> (istream &o, PlytaGamingowa &p);
	void wypiszDane();
	void wpiszDane();
	void stan();
	void wpiszDoPliku();
	void wczytajZPliku();
};

