#pragma once
#include<string>
#include<ctime>
#include <cstdlib>
//#include"Poprawnosc.h"
#include<iostream>
using namespace std;

enum Taktowanie{ Niskie=1866, Srednie=2133, Wysokie=2400 };
enum Pojemnosc { Mala = 4, Srednia= 8, Duza = 16 };

class SzynaPamieci
{
public:
	SzynaPamieci();
	~SzynaPamieci();
	void PrzetaktujGora(SzynaPamieci &ram);
	void PrzetaktujDol(SzynaPamieci &ram);
	friend ostream& operator<<(ostream &o, SzynaPamieci &s);
	friend istream& operator >> (istream &o, SzynaPamieci &p);
	//SzynaPamieci& operator=(SzynaPamieci &s);
	static Taktowanie taktowanie;
	static Taktowanie losujTaktowanie();
	Pojemnosc losujPojemnosc();
private:
	int Wybor_opcji(int liczba_opcji);
	string producent;
	Pojemnosc pojemnosc;
	
};

