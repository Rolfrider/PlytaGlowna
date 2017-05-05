#pragma once
#include "PlytaGlowna.h"
#include "Soket.h"
#include "PCI.h"
#include<iostream>
#include "SzynaPamieci.h"
#include <vector>
#include <deque>
typedef string Producent;
/// Klasa dziedziczaca po PlycieGlownej
class PlytaStacjonarna :
	public PlytaGlowna
{
public:
	/// Konstruktor domyslny
	/**
	Konstruktor losuje lub przypisuje domyslne wartosci wszystkich pol obiektu
	*/
	PlytaStacjonarna();
	///Destruktor
	~PlytaStacjonarna();
	///Konstruktor kopiujacy
	PlytaStacjonarna(PlytaStacjonarna &p);
	///Konstruktor z parametrami 
	/**
	Konstruktor bierze za prametry zmienne typu int:
	liczbaSzyn, szynyZajete, wejsciaPCI, PCIzajete
	i przypisuje je do pol o tych samych nazwach
	*/
	PlytaStacjonarna(int liczbaSzyn, int szynyZajete, int wejsciaPCI, int PCIzajete);
	/// Funkcja wypisujaca informacje o specyfikacji procesora
	void SoketSpec();
	/// Funkcja sluzaca do zmianny parametrow procesora
	void WymienProcka();
	/// Funkcja robiaca linijke znaku "=" w celach estetycznych 
	void dzialka();
	/// Funkcja statyczna zwracjaca liczbe utworzonych plyt Stacjonarnych
	static int ZwrocLiczbePlyt();
	/// Funkcja odziedziczona wpisujaca dane o obikecie
	void wypiszDane();
	/// Funkcja odziedziczona wpisujaca stan obiektu
	void stan(); 
	/// Funkcja odziedziczona zapisujaca dane o obikecie w pliku
	void wpiszDoPliku();
	/// Funkcja odziedziczona wczytujaca  dane o obikecie z pliku
	void wczytajZPliku();

	/// operator strumieniowy << wypisujacy informacje o obiekcie do strumienia wyjsciowego
	friend ostream& operator<< (ostream &s, PlytaStacjonarna &p);
	/// operator strumieniowy >> wypisujacy informacje o obiekcie do strumienia wejsciowego
	friend istream& operator >> (istream &o, PlytaStacjonarna &p);
	/// operator porownania - sprawdza czy plyty maja to samo wejscie soket
	bool operator==(PlytaStacjonarna &p);
	/// operator preinkrementacji - Zwieksza RAM w plycie 
	PlytaStacjonarna& operator++();
	/// operator predekrementacji - Zmniejsza RAM w plycie 
	PlytaStacjonarna& operator--();
	/// operator postinkrementacji - Dodaje karte rozszerszen
	PlytaStacjonarna operator++(int);
	/// operator postdekrementacji - Odejmuje karte rozszerszen
	PlytaStacjonarna operator--(int);
	/// operator przypisania - Przypisuje obiekt do wskazanego obiektu
	PlytaStacjonarna& operator=(const PlytaStacjonarna &p);
	/// operator indeksowy - Zwraca karte rozszerszen o podanym indeksie
	PCI& operator[](const int i);
	/// operator konwersji - Przypisuje zmiennej typu int zmienna szynyZajete
	operator int();
	/// opertor "^" - przetaktowuje pamiec RAM 
	PlytaStacjonarna& operator^(const int a);

protected:
	static int liczbaPlyt; ///< Liczba utworzonych plyt
	Producent marka; ///< nazwa producenta plyty
	Soket procesor; ///< Obiekt przechowujacy dane o procesorze
	vector <SzynaPamieci> RAM; ///< wektor skladajacy sie z obiektow przechowujacych dane o pamieci RAM
	deque <PCI> karty; ///< lista dwukierunkowa skladajacy sie z obiektow przechowujacych dane o kartach rozszerzen
	/// Funkcja losujaca nazwe producenta plyty
	Producent losuj();
	int liczbaSzyn;///< zmienna mowiaca o liczbie dostepnych szyn pamieci
	int szynyZajete;///< zmienna mowiaca o liczbie zajetych szyn pamieci
	int wejsciaPCI;///< zmienna mowiaca o liczbie dostepnych wejsc PCI
	int PCIzajete;///< zmienna mowiaca o liczbie zajetych wejsc PCI
};

