#pragma once
#include<string>
#include<ctime>
#include <cstdlib>
#include<iostream>
#include<sstream>
using namespace std;

/// Klasa odpowiedzialna za rozszerzenia do plyty glownej 
class PCI
{
public:
	/// Konstruktor domyslny
	PCI();
	///Konstruktor dla pltyt mobilnej
	PCI(bool mobilna);
	///Konstruktor z parametrami
	PCI(string rodzaj, string producent, int pamienc, bool mobilna= false);
	///Destruktor
	~PCI();
	/// operator strumieniowy << wypisujacy informacje o obiekcie do strumienia wyjsciowego
	friend ostream& operator<<(ostream &o, PCI &p);
	/// operator strumieniowy >> wypisujacy informacje o obiekcie do strumienia wejsciowego
	friend istream& operator>>(istream &o, PCI &p);
private:
	
	string rodzaj;///< Rodzaj rozszerzenia np. karta graficzna
	string producent;///< nazwa producenta rozszerzenia
	///Funkcja losujaca rodzaj rozszerzenia
	string losujRodzaj();
	///Funkcja losujaca producenta rozszerzenia
	string losujProducenta();
	int pamienc;///< zmienna informujaca o ilosci pamieci w rozszerzeniu
	bool mobilna = false;///< flaga decydujaca czy dotyczy sie to mobilnych rozszerzen

};

