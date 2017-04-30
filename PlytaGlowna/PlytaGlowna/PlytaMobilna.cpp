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
	cout << "Producent plyty mobilnej : "; s << p.marka << endl;
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
void PlytaMobilna::wpiszDane() {
	cin >> *this;
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
	}
}

void PlytaMobilna::wczytajZPliku() {
	fstream plik;
	plik.open("PlytaMobilna.txt", ios::out);
	if (plik.good() == true)
	{
		plik >> *this;
		plik.close();
	}
}

PlytaMobilna::~PlytaMobilna()
{
}
