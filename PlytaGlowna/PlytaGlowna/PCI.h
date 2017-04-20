#pragma once
#include<string>
#include<ctime>
#include <cstdlib>
#include<iostream>
#include<sstream>
//#include"Poprawnosc.h"
using namespace std;
class PCI
{
public:
	PCI();
	PCI(bool mobilna);
	PCI(string rodzaj, string producent, int pamienc, bool mobilna= false);
	~PCI();
	friend ostream& operator<<(ostream &o, PCI &p);
	friend istream& operator>>(istream &o, PCI &p);
	string losujRodzaj();
	string losujProducenta();
private:
	int Wprowadzanie_inta(string zapytanie);
	string rodzaj;
	string producent;
	int pamienc;
	bool mobilna = false;

};

