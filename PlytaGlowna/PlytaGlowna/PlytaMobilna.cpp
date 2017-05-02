#include "stdafx.h"
#include "PlytaMobilna.h"


PlytaMobilna::PlytaMobilna()
{
	szerokosc = 10.3;
	dlugosc = 4.8;
	waga = 20;
	marka = "Samszong";
	procesor = Soket(2134, 4, 1.6, 1, mobilnaPlyta);
	ram = SzynaPamieci(mobilnaPlyta);
	dodatki.push_back(PCI("Zyroskop", "ZyroInc", 1, mobilnaPlyta));
	dodatki.push_back(PCI("Czujnik swiatla", "CzujInc", 1, mobilnaPlyta));
	dodatki.push_back(PCI("WiFi", "WiFiInc", 500, mobilnaPlyta));
	dodatki.push_back(PCI("Komunikator GSM", "GSMInc", 1, mobilnaPlyta));
}


ostream& operator << (ostream &s, PlytaMobilna &p)
{
	cout << "Plyta Mobilna" << endl;
	cout << "Producent plyty mobilnej : "; s << p.marka << endl;
	cout << "Szerokosc w mm : "; s << p.szerokosc << endl;
	cout << "Dlugosc w mm "; s << p.dlugosc << endl;
	cout << "Waga : "; s << p.waga; cout << " gram"; s << endl;
	s << p.procesor << endl;
	s << p.ram << endl;
	cout << "Dodatkowe urzadzenia : " << endl;
	for (int i = 0; i < p.dodatki.size(); i++)
	{
		cout << "==============================================================" << endl;
		s << p.dodatki[i] << endl;
		
	}


	return s;
}

istream& operator >> (istream &o, PlytaMobilna &p)
{
	cout << "Podaj nazwe producenta plyty :" << endl;
	o >> p.marka;
	cout << "Podaj szerokosc w mm plyty :" << endl;
	o >> p.szerokosc;
	cout << "Podaj dlugosc w mm plyty :" << endl;
	o >> p.dlugosc;
	cout << "Podaj wage w gramch plyty :" << endl;
	o >> p.waga;
	o >> p.procesor;
	o >> p.ram;
	for (int i = 0; i < p.dodatki.size(); i++) {
		cout << "============================================================" << endl;
		o >> p.dodatki[i];
	}
	return o;
}

void PlytaMobilna::wypiszDane() {
	cout << *this << endl;
}

void PlytaMobilna::stan() {
	cout << "Mobilna plyta gotowa do uzytku" << endl;;
}

void PlytaMobilna::wpiszDoPliku() {
	fstream plik;
	plik.open("PlytaMobilna.txt", ios::in);
	if (plik.good() == true)
	{

		plik << *this;
		plik.close();
		system("cls");
		cout << "Udalo sie zapisac dane w pliku " << endl;
	}
	else
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
	}
}

void PlytaMobilna::wczytajZPliku() {
	fstream plik;
	plik.open("PlytaMobilna.txt", ios::out);
	if (plik.good() == true)
	{
		plik >> *this;
		plik.close();
		system("cls");
		cout << "Udalo sie wczytac dane z pliku" << endl;
	}
	else
	{
		cout << "Nie mozna otworzyc pliku" << endl;
	}
}

PlytaMobilna::~PlytaMobilna()
{
}
