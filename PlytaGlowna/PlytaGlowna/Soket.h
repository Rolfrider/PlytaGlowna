#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include "PCI.h"
//#include"Poprawnosc.h"

using namespace std;
/// Klasa odpowiedzialna za informacje o procesorze 
class Soket
{
public:
	///Konstruktor
	Soket();
	///Konstruktor z prametrami 
	Soket(int rodzaj, int liczbaRdzeni, float taktowanie, int pamiecCache, bool mobilna = false);
	///Konstruktor kopiujacy
	Soket(Soket &s);
	///Destruktor
	~Soket();
	///Funkcja wyswietlajace dane o procesorze
	void Spec();
	///Funkcja zwracajaca rodzaj soketu procesora
	int pokazRodzaj();
	/// Funkcja zwracajaca liczbe rdzeni
	int pokazLiczbeRdzenie();
	/// Funkcja zwracajaca taktowanie rdzeni
	float pokazTaktowanie();
	/// Funkcja zwracajaca pamiec chache 
	int pokazPamiec();
	/// Funkcja zwiekszajaca taktowanie rdzeni
	void podkrecProcka();
	/// Operator porownania
	bool operator==(Soket &procesor);
	///Operator przypisania
	Soket& operator= (const Soket &s);
	/// operator strumieniowy << wypisujacy informacje o obiekcie do strumienia wyjsciowego
	friend ostream& operator<<(ostream &o, Soket &s);
	/// operator strumieniowy >> wypisujacy informacje o obiekcie do strumienia wejsciowego
	friend istream& operator >> (istream &o, Soket &p);
private:
	int rodzaj;///< zmienna informujaca o gniezdzie procesora
	int liczbaRdzeni;///< liczba rdzeni procesora
	float taktowanie;///< wysokosc taktowania rdzeni
	int pamiecCache;///< ilosc pamieci cache 
	PCI* zintegrowanaKartaGraficzna = nullptr; ///< mozliwosc dodania zintegrowanej karty graficznej np. w procesorach mobilnych


};

