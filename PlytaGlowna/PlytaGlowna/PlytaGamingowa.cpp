#include "stdafx.h"
#include "PlytaGamingowa.h"


PlytaGamingowa::PlytaGamingowa()
{
	podswietlenieRGB = "Krwisto czerwony";
	cechySzczegolne = "Drapiezny wyglad";
	material = "Czysty stop aluminium";
	wsparcieVR = true;
	nvidiaSLI = true;
	szerokosc = 305;
	dlugosc = 244;
	waga = 222.1;
	iloscPlyt++;
	iloscSzyn = 4;
	wejsciaPCI = 3;
	szynyZajete = 2;
	PCIzajete = 2;
	karty.clear();
	RAM.clear();
	RAM.reserve(iloscSzyn);// Rezerwuje nam miejsce na max tyle elementów ile jest szyn
	if (iloscSzyn != 0)
	{
		for (int i = 0; i < szynyZajete; i++)
		{
			RAM.push_back(SzynaPamieci(16, 2400));
		}
	}
	if (wejsciaPCI != 0)
	{
		for (int i = 0; i < PCIzajete-1; i++)
		{
			karty.push_back(PCI());
		}

		karty.push_back(PCI("Karta graficzna", "Zotac", 8));
	}
}


ostream& operator << (ostream &s, PlytaGamingowa &p) {
	cout << "Plyta Gamingowa :" << endl;
	cout << "Producent : "; s << p.marka << endl;
	cout << "Szerokosc w mm : "; s << p.szerokosc << endl;
	cout << "Dlugosc w mm "; s << p.dlugosc << endl;
	cout << "Waga : "; s << p.waga; cout << " gram"; s << endl;
	cout << "Dostepne szyny pamieci: "; s << p.iloscSzyn << endl;;
	cout << " Zajete szyny pamieci : "; s << p.szynyZajete << endl;
	cout << "Dostepne zlacza PCI: "; s << p.wejsciaPCI << endl;
	cout << " Zajete zlacza PCI: "; s << p.PCIzajete << endl;
	cout << "Kolor podswietlenia RGB : "; s << p.podswietlenieRGB << endl;
	cout << "Cechy szczegolne : "; s << p.cechySzczegolne << endl;
	cout << "Material z ktorego zostala wykonana plyta : "; s << p.material << endl;
	p.dzialka();
	s << p.soket;
	for (int i = 0; i < p.karty.size(); i++) {
		p.dzialka();
		s << p.karty[i];
	}
	for (int i = 0; i < p.RAM.size(); i++) {
		p.dzialka();
		s << p.RAM[i];
	}
	p.dzialka();
	return s;
}

istream& operator >> (istream &o, PlytaGamingowa &p) {
	cout << "Podaj nazwe producenta plyty :" << endl;
	getline(o, p.marka);
	cout << "Podaj szerokosc w mm plyty :" << endl;
	o >> p.szerokosc;
	cout << "Podaj dlugosc w mm plyty :" << endl;
	o >> p.dlugosc;
	cout << "Podaj wage w gramch plyty :" << endl;
	o >> p.waga;
	cout << "Podaj liczbe dostepnych szyn pamieci" << endl;
	o >> p.iloscSzyn;
	cout << "Podaj liczbe zajetych szyn pamieci " << endl;
	o >> p.szynyZajete;	
	cout << "Podaj liczbe zlaczy PCI" << endl;
	o >> p.wejsciaPCI;
	cout << "Podaj liczbe zajetych zlacz PCI " << endl;
	o >> p.PCIzajete;	
	o.ignore();
	cout << "Podaj kolor podœwietlenia RGB :" << endl;
	getline(o, p.podswietlenieRGB);
	cout << "Podaj cechy szcegolne :" << endl;
	getline(o, p.cechySzczegolne);
	cout << "Podaj material z ktorego zostala wykonana plyta : " << endl;
	getline(o, p.material);
	o >> p.soket;
	
	for (int i = 0; i < p.PCIzajete; i++) {
		p.dzialka();
		o >> p.karty[i];
	}
	for (int i = 0; i < p.szynyZajete; i++) {
		p.dzialka();
		o >> p.RAM[i];
	}
	return o;
}

void PlytaGamingowa::wypiszDane() {
	cout << *this << endl;;
}

void PlytaGamingowa::stan() {
	cout << "Gamingowa plyta gotowa do uzytku" << endl;;
}
void PlytaGamingowa::wpiszDoPliku() {
	fstream plik;
	plik.open("PlytaGamingowa.txt", ios::out | ios::trunc);
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

void PlytaGamingowa::wczytajZPliku() {
	fstream plik;
	plik.open("PlytaGamingowa.txt", ios::in);
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
PlytaGamingowa::~PlytaGamingowa()
{
}
