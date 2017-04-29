#pragma once
#include<iostream>
#include<sstream>

using namespace std;

class PlytaGlowna
{
protected:
	int Wprowadzanie_inta(string zapytanie);
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
};

