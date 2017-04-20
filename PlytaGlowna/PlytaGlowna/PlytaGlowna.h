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
public:
	PlytaGlowna();
	virtual ~PlytaGlowna();
};

