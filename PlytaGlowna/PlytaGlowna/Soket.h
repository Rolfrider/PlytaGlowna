#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include "PCI.h"
//#include"Poprawnosc.h"

using namespace std;
class Soket
{
public:
	Soket();
	Soket(int rodzaj, int liczbaRdzeni, float taktowanie, int pamiecCache, bool mobilna = false);
	Soket(Soket &s);
	~Soket();
	void Spec();
	int pokazRodzaj();
	int pokazLiczbeRdzenie();
	float pokazTaktowanie();
	int pokazPamiec();
	void podkrecProcka();

	bool operator==(Soket &soket);
	Soket& operator= (const Soket &s);
	friend ostream& operator<<(ostream &o, Soket &s);
	friend istream& operator >> (istream &o, Soket &p);
private:
	float Wprowadzenie_float(string zapytanie);
	int Wprowadzenie_inta(string zapytanie);
	void CzyszczenieBufora();
	int rodzaj;
	int liczbaRdzeni;
	float taktowanie;
	int pamiecCache;
	PCI* zintegrowanaKartaGraficzna = nullptr;


};

