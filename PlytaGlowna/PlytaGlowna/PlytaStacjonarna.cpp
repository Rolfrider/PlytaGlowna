#include "stdafx.h"
#include "PlytaStacjonarna.h"
#include<iostream>
#ifdef _DEBUG
#define DEBUG(x)
#else
#define DEBUG(x) cout<<x<<endl;
#endif // _DEBUG

int PlytaStacjonarna::iloscPlyt = 0;
// KONSKRUKTORY
PlytaStacjonarna::PlytaStacjonarna()
{
	DEBUG("Tworze plyte glowna")

		marka = losuj();
	iloscPlyt++;
	iloscSzyn = (rand() % 6 + 1);
	wejsciaPCI = (rand() % 4 + 1);
	szynyZajete = (rand() % iloscSzyn + 1);
	PCIzajete = (rand() % wejsciaPCI + 1);

	if (iloscSzyn >= szynyZajete)
		RAM = new SzynaPamieci[szynyZajete];
	else {
		RAM = nullptr;
		szynyZajete = 0;
	}
	if (wejsciaPCI >= PCIzajete)
		karty = new PCI[PCIzajete];
	else {
		karty = nullptr;
		PCIzajete = 0;
	}
}

PlytaStacjonarna::PlytaStacjonarna(int iloscSzyn, int szynyZajete, int wejsciaPCI, int PCIzajete) :
	iloscSzyn(iloscSzyn), szynyZajete(szynyZajete), wejsciaPCI(wejsciaPCI), PCIzajete(PCIzajete) {
	marka = losuj();
	iloscPlyt++;
	DEBUG("Tworze plyte glowna")
		if (iloscSzyn >= szynyZajete)
			RAM = new SzynaPamieci[szynyZajete];
		else {
			RAM = NULL;
			szynyZajete = 0;
		}
		if (wejsciaPCI >= PCIzajete)
			karty = new PCI[PCIzajete];
		else {
			karty = NULL;
			PCIzajete = 0;
		}


}

PlytaStacjonarna::PlytaStacjonarna(PlytaStacjonarna &p) { // konstruktor kopiuj¹cy 
	DEBUG("Tworze plyte glowna")
		iloscPlyt++;
	marka = p.marka;
	iloscSzyn = p.iloscSzyn;
	wejsciaPCI = p.wejsciaPCI;
	szynyZajete = p.szynyZajete;
	PCIzajete = p.PCIzajete;
	if (p.RAM != NULL) {
		RAM = new SzynaPamieci[szynyZajete];
		for (int i = 0; i < szynyZajete; i++) {
			RAM[i] = p.RAM[i];
		}
	}
	else
		RAM = nullptr;

	if (p.karty != NULL) {
		karty = new PCI[PCIzajete];
		for (int i = 0; i < PCIzajete; i++) {
			karty[i] = p.karty[i];
		}
	}
	else
		karty = nullptr;

}
// OPERATORY
bool PlytaStacjonarna::operator==(PlytaStacjonarna &p) {
	return (iloscSzyn == p.iloscSzyn && wejsciaPCI == p.wejsciaPCI);
}

PlytaStacjonarna& PlytaStacjonarna::operator^(const int a) {
	if (a > 0) {
		if (RAM != NULL) {
			cout << "Przetaktowuje pamiec RAM" << endl;
			RAM[0].PrzetaktujGora(RAM[0]);
		}
		else
			cout << " Nie ma RAMU" << endl;
	}
	else if (a < 0) {
		if (RAM != NULL) {
			cout << "Przetaktowuje pamiec RAM" << endl;
			RAM[0].PrzetaktujDol(RAM[0]);
		}
		else
			cout << " Nie ma RAMU" << endl;
	}
	else
		cout << "Nie wprowadzam zmiann" << endl;

	cout << "Aktualny stan RAMU: " << endl;
	cout << RAM[0] << endl;
	return *this;
}

PlytaStacjonarna::operator int() {
	return szynyZajete;// operator konwersji  int a = PlytaGLowna => a = szynyZajete
}

PCI& PlytaStacjonarna::operator[](const int i) {
	if (i >= 0 && i < PCIzajete) {
		return	karty[i];
	}
	else
	{
		cout << "Zlacze PCI nie istnieje lub nic nie jest do niego podloczone" << endl;
	}
}

PlytaStacjonarna& PlytaStacjonarna::operator=(const PlytaStacjonarna &p) {
	iloscSzyn = p.iloscSzyn;
	wejsciaPCI = p.wejsciaPCI;
	szynyZajete = p.szynyZajete;
	PCIzajete = p.PCIzajete;

	delete[]RAM;
	delete[]karty;

	RAM = new SzynaPamieci[szynyZajete];
	for (int i = 0; i < szynyZajete; i++) {
		RAM[i] = p.RAM[i];
	}

	karty = new PCI[PCIzajete];
	for (int i = 0; i < PCIzajete; i++) {
		karty[i] = p.karty[i];
	}


	return *this;

}

PlytaStacjonarna& PlytaStacjonarna::operator++() { //Dodaje RAM jesli to mozliwe
	cout << "Procedura dodania nowej kosci RAM" << endl;
	if (RAM != NULL) {
		SzynaPamieci *RAM1 = new SzynaPamieci[szynyZajete];
		for (int i = 0; i < szynyZajete; i++) {
			RAM1[i] = RAM[i];
		}
		szynyZajete++;
		if (iloscSzyn >= szynyZajete) {
			RAM = new SzynaPamieci[szynyZajete];
			for (int i = 0; i < szynyZajete - 1; i++) {
				RAM[i] = RAM1[i];
			}
		}
		else {
			szynyZajete--;
			for (int i = 0; i < szynyZajete; i++) {
				RAM[i] = RAM1[i];
			}
			cout << "Nie mozna dodac, wsszystkie szyny pamieci zajete" << endl;

		}
		delete[]RAM1;
	}
	else {
		szynyZajete++;
		if (iloscSzyn >= szynyZajete)
			RAM = new SzynaPamieci[szynyZajete];
		else {
			szynyZajete--;
			RAM = new SzynaPamieci[szynyZajete];
		}
	}
	return *this;
}

PlytaStacjonarna& PlytaStacjonarna::operator--() { //Odejmowanie RAM jesli to mozliwe
	cout << "Procedura  odejmowania kosci RAM" << endl;
	if (RAM != NULL) {
		SzynaPamieci *RAM1 = new SzynaPamieci[szynyZajete];
		for (int i = 0; i < szynyZajete; i++) {
			RAM1[i] = RAM[i];
		}
		szynyZajete--;
		if (szynyZajete > 0) {
			RAM = new SzynaPamieci[szynyZajete];
			for (int i = 0; i < szynyZajete; i++) {
				RAM[i] = RAM1[i];
			}
		}
		else {
			szynyZajete++;
			for (int i = 0; i < szynyZajete; i++) {
				RAM[i] = RAM1[i];
			}
			cout << "Nie mozna odjac RAMU" << endl;

		}
		delete[]RAM1;
	}
	else {
		szynyZajete--;
		if (szynyZajete > 0)
			RAM = new SzynaPamieci[szynyZajete];
		else {
			szynyZajete++;
			RAM = new SzynaPamieci[szynyZajete];
		}
	}

	return *this;
}

PlytaStacjonarna PlytaStacjonarna::operator++(int) {//Dodaje karte rozszerzen
	cout << "Procedura dodania nowej karty rozszerzeñ" << endl;
	PlytaStacjonarna kopia = *this;
	if (karty != NULL) {
		PCI *kart1 = new PCI[PCIzajete];
		for (int i = 0; i < PCIzajete; i++) {
			kart1[i] = karty[i];
		}
		PCIzajete++;
		if (wejsciaPCI >= PCIzajete) {
			karty = new PCI[PCIzajete];
			for (int i = 0; i < PCIzajete - 1; i++) {
				karty[i] = kart1[i];
			}
		}

		else {
			PCIzajete--;
			for (int i = 0; i < PCIzajete; i++) {
				karty[i] = kart1[i];
			}
			cout << "Nie mozna dodac, wsszystkie zlacza  PCI zajete" << endl;

		}
		delete[]kart1;
	}
	else {
		PCIzajete++;
		if (wejsciaPCI >= PCIzajete)
			karty = new PCI[PCIzajete];
		else {
			PCIzajete--;
			karty = new PCI[PCIzajete];
		}
	}
	return kopia;

}

PlytaStacjonarna PlytaStacjonarna::operator--(int) {//Odejmuje karte rozszerzen
	cout << "Procedura odejmowania karty rozszerzeñ" << endl;
	PlytaStacjonarna kopia = *this;
	if (karty != NULL) {
		PCI *kart1 = new PCI[PCIzajete];
		for (int i = 0; i < PCIzajete; i++) {
			kart1[i] = karty[i];
		}
		PCIzajete--;
		if (PCIzajete > 0) {
			karty = new PCI[PCIzajete];
			for (int i = 0; i < PCIzajete; i++) {
				karty[i] = kart1[i];
			}
		}
		else {
			PCIzajete++;
			for (int i = 0; i < PCIzajete; i++) {
				karty[i] = kart1[i];
			}
			cout << "Nie mozna odjac karty rozszerzen" << endl;
		}
		delete[]kart1;
	}
	else {
		PCIzajete--;
		if (PCIzajete > 0)
			karty = new PCI[PCIzajete];
		else if (PCIzajete == 0)
			cout << "Nie ma zadnych kart rozszerzen" << endl;
		else {
			PCIzajete++;
			karty = new PCI[PCIzajete];
		}
	}
	return kopia;

}

ostream& operator << (ostream &s, PlytaStacjonarna &p) {
	s << "Producent : " << p.marka << endl;
	s << "Dostepne szyny pamieci: " << p.iloscSzyn;
	s << " Zajete szyny pamieci : " << p.szynyZajete << endl;
	s << "Dostepne zlacza PCI: " << p.wejsciaPCI;
	s << " Zajete zlacza PCI: " << p.PCIzajete << endl;
	p.dzialka();
	s << p.soket;
	for (int i = 0; i < p.PCIzajete; i++) {
		p.dzialka();
		s << p.karty[i];
	}
	for (int i = 0; i < p.szynyZajete; i++) {
		p.dzialka();
		s << p.RAM[i];
	}
	p.dzialka();
	return s;
}

//METODY

Producent PlytaStacjonarna::losuj() {
	int a = (rand() % 3 + 1);
	switch (a) {
	case 1:
		return " RASUS ";
		break;
	case 2:
		return " MidBajt ";
		break;
	case 3:
		return " MSC ";
		break;
	default:
		return " NOname ";
	}
}

void PlytaStacjonarna::WymienProcka() {
	cout << "Rozpoczynam wymiane procesora" << endl;
	dzialka();
	cout << "Aktualny procesor" << endl;
	SoketSpec();
	Soket soket1(2012, 2, 2.7, 3);
	cout << "Nowy procesor nr.1 :" << endl;
	soket1.Spec();
	dzialka();
	Soket soket2(2011, 6, 3.4, 6);
	cout << "Nowy procesor nr.2 :" << endl;
	soket2.Spec();
	dzialka();
	cout << "Probuje wstawic procesor nr.1" << endl;
	if (soket == soket1)
		soket = soket1;
	dzialka();
	cout << "Probuje wstawic procesor nr.2" << endl;
	if (soket == soket2)
		soket = soket2;
	dzialka();
	cout << "Aktualny procesor" << endl;
	SoketSpec();
}

void PlytaStacjonarna::SoketSpec() {
	soket.Spec();
	dzialka();
}

void PlytaStacjonarna::dzialka() {
	for (int i = 0; i < 50; i++) {
		cout << "=";
	}
	cout << endl;

}

int PlytaStacjonarna::ZwrocLiczbePlyt() {
	return iloscPlyt;
}



PlytaStacjonarna::~PlytaStacjonarna()
{
	if (RAM != NULL)
		delete[]RAM;
	if (karty != NULL)
		delete[]karty;
	DEBUG("Niszcze plyte glowna")
}
