#pragma once
#include<string>
#include<iostream>
#include<sstream>
//#include"Poprawnosc.h"

using namespace std;
class Soket
{
public:
	Soket();
	Soket(int rodzaj, int liczbaRdzeni, float taktowanie, int pamiecCache);
	~Soket();
	void Spec();
	int pokazRodzaj();
	int pokazLiczbeRdzenie();
	float pokazTaktowanie();
	int pokazPamiec();
	void podkrecProcka();

	bool operator==(Soket &soket);
	friend ostream& operator<<(ostream &o, Soket &s);
	friend istream& operator >> (istream &o, Soket &p);
private:
	float Wprowadzenie_float(string zapytanie);
	int Wprowadzenie_inta(string zapytanie);
	int rodzaj;
	int liczbaRdzeni;
	float taktowanie;
	int pamiecCache;
};

