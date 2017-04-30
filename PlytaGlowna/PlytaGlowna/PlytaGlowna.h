#pragma once
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

class PlytaGlowna
{
protected:
	int Wprowadzanie_inta(string zapytanie);
	float Wprowadzenie_float(string zapytanie);
	float szerokosc;
	float dlugosc;
	float waga;
	void CzyszczenieBufora();
public:
	PlytaGlowna();
	virtual ~PlytaGlowna();
	virtual void wypiszDane() = 0;
	virtual void wpiszDane() = 0;
	virtual void stan() = 0;
	virtual void wpiszDoPliku() = 0;
	virtual void wczytajZPliku() = 0;

	friend ostream& operator<< (ostream &s, PlytaGlowna &p);
	friend istream& operator >> (istream &o, PlytaGlowna &p);
};

