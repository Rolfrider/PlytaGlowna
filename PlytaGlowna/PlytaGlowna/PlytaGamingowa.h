#pragma once
#include "PlytaStacjonarna.h"

typedef string kolor;

/// Klasa dziedziczaca po Plycie Stacjonarnej
class PlytaGamingowa :
	public PlytaStacjonarna
{
	kolor podswietlenieRGB; ///< zmienna informujaca o kolorze podswietlenia
	string cechySzczegolne; ///< zmienna mowiaca o jakiœ szczegolnych cechach obiektu np. niepowtarzalny wyglad itp.
	bool wsparcieVR;///< zmienna mowiaca czy plyta wspiera technologie VR
	bool nvidiaSLI;///< zmienna informujaca czy plyta wspiera laczaenie dwoch kart graficznych
	string material; ///< zmiena infomujaca o materiale z ktorego plyta zostala wykonana
public:
	/// Konstruktor domyslny - przypisuje domyslne wartosci
	PlytaGamingowa();
	/// Destruktor domyslny 
	~PlytaGamingowa();
	/// operator strumieniowy << wypisujacy informacje o obiekcie do strumienia wyjsciowego
	friend ostream& operator<< (ostream &s, PlytaGamingowa &p);
	/// operator strumieniowy >> wypisujacy informacje o obiekcie do strumienia wejsciowego
	friend istream& operator >> (istream &o, PlytaGamingowa &p);

	/// Funkcja odziedziczona wpisujaca dane o obikecie
	void wypiszDane();
	/// Funkcja odziedziczona wpisujaca stan obiektu
	void stan();
	/// Funkcja odziedziczona zapisujaca dane o obikecie w pliku
	void wpiszDoPliku();
	/// Funkcja odziedziczona wczytujaca  dane o obikecie z pliku
	void wczytajZPliku();
};

