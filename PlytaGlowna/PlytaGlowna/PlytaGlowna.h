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
};

