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
	}
}


ostream& operator << (ostream &s, PlytaGamingowa &p) {
	cout << "Producent : "; s << p.marka << endl;
	cout << "Wymiar w mm : "; s << p.szerokosc; cout << " x "; s << p.dlugosc << endl;
	cout << "Waga : "; s << p.waga; cout << " gram" << endl;
	cout << "Dostepne szyny pamieci: "; s << p.iloscSzyn;
	cout << " Zajete szyny pamieci : "; s << p.szynyZajete << endl;
	cout << "Dostepne zlacza PCI: "; s << p.wejsciaPCI;
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
	p.iloscSzyn = p.Wprowadzanie_inta("Podaj liczbe szyn pamieci ");
	p.szynyZajete = p.Wprowadzanie_inta("Podaj liczbe zajetych szyn pamieci ");
	p.wejsciaPCI = p.Wprowadzanie_inta("Podaj liczbe zlaczy PCI ");
	p.PCIzajete = p.Wprowadzanie_inta("Podaj liczbe zajetych zlacz PCI ");
	cout << "Podaj cechy szcegolne :" << endl;
	getline(o, p.cechySzczegolne);
	cout << "Podaj kolor podœwietlenia RGB :" << endl;
	getline(o, p.podswietlenieRGB);
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
void PlytaGamingowa::wpiszDane() {
	cin >> *this;
}
void PlytaGamingowa::stan() {
	cout << "Gamingowa plyta gotowa do uzytku" << endl;;
}
PlytaGamingowa::~PlytaGamingowa()
{
}
