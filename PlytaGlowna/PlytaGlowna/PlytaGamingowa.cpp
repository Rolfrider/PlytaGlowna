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
			RAM.push_back(SzynaPamieci(Duza, Wysokie));
		}
	}
	if (wejsciaPCI != 0)
	{
		for (int i = 0; i < PCIzajete-1; i++)
		{
			karty.push_back(PCI());
		}

		karty.push_back(PCI("Karta graficzna", "Zotac", 8));
		karty.pop_front();
	}
}


ostream& operator << (ostream &s, PlytaGamingowa &p) {
	s << "Producent : " << p.marka << endl;
	s << "Wymiar w mm : " << p.szerokosc << " x " << p.dlugosc << endl;
	s << "Waga : " << p.waga << " gram" << endl;
	s << "Dostepne szyny pamieci: " << p.iloscSzyn;
	s << " Zajete szyny pamieci : " << p.szynyZajete << endl;
	s << "Dostepne zlacza PCI: " << p.wejsciaPCI;
	s << " Zajete zlacza PCI: " << p.PCIzajete << endl;
	s << "Kolor podswietlenia RGB : " << p.podswietlenieRGB << endl;
	s << "Cechy szczegolne : " << p.cechySzczegolne << endl;
	s << "Material z ktorego zostala wykonana plyta : " << p.material << endl;
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
	o >> p.marka;
	p.iloscSzyn = p.Wprowadzanie_inta("Podaj liczbe szyn pamieci ");
	p.szynyZajete = p.Wprowadzanie_inta("Podaj liczbe zajetych szyn pamieci ");
	p.wejsciaPCI = p.Wprowadzanie_inta("Podaj liczbe zlaczy PCI ");
	p.PCIzajete = p.Wprowadzanie_inta("Podaj liczbe zajetych zlacz PCI ");
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
PlytaGamingowa::~PlytaGamingowa()
{
}
