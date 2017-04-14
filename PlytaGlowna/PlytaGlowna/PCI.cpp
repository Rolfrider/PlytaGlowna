#include "stdafx.h"
#include "PCI.h"

#ifdef _DEBUG
#define DEBUG(x)
#else
#define DEBUG(x) cout<<x<<endl;
#endif // _DEBUG

// konstruktory 
PCI::PCI()
{
	DEBUG("Tworze nowe zlocze PCI")

	rodzaj = losujRodzaj();
	producent = losujProducenta();
	pamienc = rand()%6+1;
}
//operatory
ostream& operator<<(ostream &o, PCI &p) {
	o << p.rodzaj << endl;
	o << "Producent : " << p.producent << endl;
	o << "Pamiec urzadzenia " << p.pamienc << " GB" << endl;
	return o;
}

istream& operator>>(istream &o, PCI &p) {
	
	cout << "Podaj rodzaj karty rozszerzen :" << endl;
	cin >> p.rodzaj;
	p.rodzaj = " Karta " + p.rodzaj;
	cout << "Podaj producenta karty rozszerzen :" << endl;
	o >> p.producent;
	p.pamienc = p.Wprowadzanie_inta("Podaj liczbe GB pamieci karty rozszerzen :") ;
	return o;
}
//metody
int PCI::Wprowadzanie_inta(string zapytanie)
{
	int wartosc;
	bool blad = true;
	string znaki;
	while (blad)
	{
		cout << zapytanie << endl;
		cin >> znaki;
		blad = false;
		for (int i = 0; i < znaki.length(); i++)
		{
			if (znaki[i] < '0' || znaki[i]>'9')
				blad = true;
			else
				continue;
		}
	}
	istringstream iss(znaki);
	iss >> wartosc;
	return wartosc;
}
string PCI::losujRodzaj() {
	
	int a = (rand() % 3 + 1);
	switch (a) {
	case 1:
		return " Karta graficzna ";
		break;
	case 2:
		return " Karta sieciowa ";
		break;
	case 3:
		return " Karta dzwiekowa ";
		break;
	default:
		return " Karta niczego ";
	}
}

string PCI::losujProducenta() {
	int a = (rand() % 3 + 1);
	switch (a) {
	case 1:
		return "Masus";
		break;
	case 2:
		return "Minibajt";
		break;
	case 3:
		return "Turbo";
		break;
	default:
		return "NOname";
	}
}

PCI::~PCI()
{
	DEBUG("Niszcze zlocze PCI")
}
