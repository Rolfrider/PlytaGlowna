#pragma once
#include<string>
#include<ctime>
#include <cstdlib>

#include<iostream>
using namespace std;


/// Klasa przechowujaca dane o pamieci RAM plyty
class SzynaPamieci
{
public:
	///Konstruktor domyslny
	SzynaPamieci();
	///Konstruktor z parametrami
	SzynaPamieci(int poj, int tak);
	///Konstruktor dla pamieci mobilnej
	SzynaPamieci(bool mobilna);
	///Destruktor
	~SzynaPamieci();
	///Funkcja przetaktowyjaca pamiec na wysze taktowanie
	void PrzetaktujGora(SzynaPamieci &ram);
	///Funkcja przetaktowyjaca pamiec na nizsze taktowanie
	void PrzetaktujDol(SzynaPamieci &ram);
	/// operator strumieniowy << wypisujacy informacje o obiekcie do strumienia wyjsciowego
	friend ostream& operator<<(ostream &o, SzynaPamieci &s);
	/// operator strumieniowy >> wypisujacy informacje o obiekcie do strumienia wejsciowego
	friend istream& operator >> (istream &o, SzynaPamieci &p);
	
	
private:
	string producent;///< nazwa producenta pamieci
	int pojemnosc;///< pojemnosc pamieci 
	int taktowanie;///< wysokosc taktowania pamieci
	///Funkcja losujaca wysokosc taktowania
	int losujTaktowanie();
	///Funkcja losujaca pojemnosc pamieci
	int losujPojemnosc();
	
};

