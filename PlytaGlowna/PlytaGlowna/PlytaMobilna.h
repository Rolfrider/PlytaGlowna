#pragma once
#include "PlytaGlowna.h"
#include "Soket.h"
#include "SzynaPamieci.h"
#include "PCI.h"
#include<iostream>
#include<vector>
using namespace std;
typedef string Producent;

class PlytaMobilna :
	public PlytaGlowna
{
	Producent marka;
	Soket procesor;
	bool mobilnaPlyta = true;
	SzynaPamieci ram;
	vector<PCI> dodatki;
	
public:
	PlytaMobilna();
	~PlytaMobilna();

	friend ostream& operator<< (ostream &s, PlytaMobilna &p);
	friend istream& operator >> (istream &o, PlytaMobilna &p);

	void wypiszDane();
	void wpiszDane();
	void stan();
	void wpiszDoPliku();
	void wczytajZPliku();
};

