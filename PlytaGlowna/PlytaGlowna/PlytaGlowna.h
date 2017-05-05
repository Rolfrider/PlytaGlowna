#pragma once
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;
///Klasa abstrakcyjna
class PlytaGlowna
{
protected:
	float szerokosc; ///< Okresla szerokosc kazdej plyty
	float dlugosc; ///< Okresla dlugosc kazdej plyty
	float waga; ///< Okresla wage kazdej plyty
public:
	///Konstruktor domyslny
	PlytaGlowna();
	///Destruktor wirtualny
	virtual ~PlytaGlowna();
	/// Funkcja abstrakcyjna i wirtualna wpisujaca dane o obikecie
	/**
	Funkcja uzywa operatora strumieniowego aby wpisac dane o obiekcie 
	*/
	virtual void wypiszDane() = 0;
	/// Funkcja abstrakcyjna i wirtualna informujaca o stanie obiektu
	virtual void stan() = 0;
	/// Funkcja abstrakcyjna i wirtualna zapisujaca dane obiektu do pliku
	virtual void wpiszDoPliku() = 0;
	/// Funkcja abstrakcyjna i wirtualna wczytujaca dane obiektu z pliku
	virtual void wczytajZPliku() = 0;
	/// operator strumieniowy << wypisujacy informacje o obiekcie do strumienia wyjsciowego
	friend ostream& operator<< (ostream &s, PlytaGlowna &p);
	/// operator strumieniowy >> wypisujacy informacje o obiekcie do strumienia wejsciowego
	friend istream& operator >> (istream &o, PlytaGlowna &p);
};

