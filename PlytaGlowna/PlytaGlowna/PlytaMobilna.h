#pragma once
#include "PlytaGlowna.h"
#include "Soket.h"
#include "SzynaPamieci.h"
#include "PCI.h"
#include<iostream>
#include<vector>

using namespace std;
typedef string Producent;

/// Klasa dzidziczaca po plycieGlownej
class PlytaMobilna :
	public PlytaGlowna
{
	Producent marka;///< nazwa producenta plyty
	Soket procesor; ///< Obiekt przechowujacy dane o procesorze
	bool mobilnaPlyta = true; ///< Flaga informujaca ze mamy doczynienia z mobilna plyta
	SzynaPamieci ram; ///< Obiekt informujacy o pamieci RAM plyty
	vector<PCI> dodatki;///< wektor skladajacy sie z obiektow przechowujacych dane o roznych rozszerzeniach plyty
	
public:
	/// Konstrunktor domyslny - przypisuje domyslne wartosci
	PlytaMobilna();
	/// Destruktor domyslny 
	~PlytaMobilna();
	/// operator strumieniowy << wypisujacy informacje o obiekcie do strumienia wyjsciowego
	friend ostream& operator<< (ostream &s, PlytaMobilna &p);
	/// operator strumieniowy >> wypisujacy informacje o obiekcie do strumienia wejsciowego
	friend istream& operator >> (istream &o, PlytaMobilna &p);

	/// Funkcja odziedziczona wpisujaca dane o obikecie
	void wypiszDane();
	/// Funkcja odziedziczona wpisujaca stan obiektu
	void stan();
	/// Funkcja odziedziczona zapisujaca dane o obikecie w pliku
	void wpiszDoPliku();
	/// Funkcja odziedziczona wczytujaca  dane o obikecie z pliku
	void wczytajZPliku();
};

