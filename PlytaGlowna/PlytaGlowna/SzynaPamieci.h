#pragma once
#include<string>
#include<ctime>
#include <cstdlib>
//#include"Poprawnosc.h"
#include<iostream>
using namespace std;

//enum Taktowanie{ Niskie=1866, Srednie=2133, Wysokie=2400 };
//enum Pojemnosc { Mobilna =2 , Mala = 4, Srednia= 8, Duza = 16 };

class SzynaPamieci
{
public:
	SzynaPamieci();
	SzynaPamieci(int poj, int tak);
	SzynaPamieci(bool mobilna);
	~SzynaPamieci();
	void PrzetaktujGora(SzynaPamieci &ram);
	void PrzetaktujDol(SzynaPamieci &ram);
	friend ostream& operator<<(ostream &o, SzynaPamieci &s);
	friend istream& operator >> (istream &o, SzynaPamieci &p);
	//SzynaPamieci& operator=(SzynaPamieci &s);
	
	
private:
	int Wybor_opcji(int liczba_opcji);
	string producent;
	int pojemnosc;
	int taktowanie;
	int losujTaktowanie();
	int losujPojemnosc();
	void CzyszczenieBufora();
	
};

