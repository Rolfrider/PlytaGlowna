#pragma once
#include "PlytaGlowna.h"
#include "Soket.h"
#include "PCI.h"
#include<iostream>
//#include"Poprawnosc.h"
#include "SzynaPamieci.h"
#include <vector>
#include <deque>
typedef string Producent;

class PlytaStacjonarna :
	public PlytaGlowna
{
public:
	PlytaStacjonarna();
	~PlytaStacjonarna();
	PlytaStacjonarna(PlytaStacjonarna &p);
	PlytaStacjonarna(int iloscSzyn, int szynyZajete, int wejsciaPCI, int PCIzajete);
	void SoketSpec();
	void WymienProcka();
	void dzialka();
	static int ZwrocLiczbePlyt();
	void wypiszDane();
	void stan();
	void wpiszDoPliku();
	void wczytajZPliku();

	friend ostream& operator<< (ostream &s, PlytaStacjonarna &p);
	friend istream& operator >> (istream &o, PlytaStacjonarna &p);
	bool operator==(PlytaStacjonarna &p);
	PlytaStacjonarna& operator++();
	PlytaStacjonarna& operator--();
	PlytaStacjonarna operator++(int);
	PlytaStacjonarna operator--(int);
	PlytaStacjonarna& operator=(const PlytaStacjonarna &p);
	PCI& operator[](const int i);
	operator int();
	PlytaStacjonarna& operator^(const int a);

protected:
	static int iloscPlyt;
	Producent marka;
	Soket soket;
	vector <SzynaPamieci> RAM;
	deque <PCI> karty;
	Producent losuj();
	int iloscSzyn;
	int szynyZajete;
	int wejsciaPCI;
	int PCIzajete;
};

