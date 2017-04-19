#include "stdafx.h"
#include "SzynaPamieci.h"



#ifdef _DEBUG
#define DEBUG(x)
#else
#define DEBUG(x) cout<<x<<endl;
#endif // _DEBUG



//konstruktory
SzynaPamieci::SzynaPamieci()
{
	DEBUG("Tworze szyne pamieci")

	taktowanie = losujTaktowanie();
	producent = "RASUS";
	pojemnosc = losujPojemnosc();
}

SzynaPamieci::SzynaPamieci(bool mobilna) :
	taktowanie(Niskie), pojemnosc(Mobilna), producent("MobileMem")
{
	DEBUG("Tworze szyne pamieci")
}
//operatory
ostream& operator<<(ostream &o, SzynaPamieci &s) {
	o << "Kosc pamieci RAM" << endl;
	o << "Producent : " << s.producent << endl;
	o << "Taktowanie pamieci : " << s.taktowanie << endl;
	o << "Pojemnosc : " << s.pojemnosc << " GB" << endl;
	return o;
}
istream& operator >> (istream &o, SzynaPamieci &p) {

	cout << "Podaj producenta ramu :" << endl;
	cin >> p.producent;
	cout << "Wybierz taktowanie ramu :" << endl; 
	cout << "1. Niskie" << endl;
	cout << "2. Srednie" << endl;
	cout << "3. Wyskokie" << endl;
	switch (p.Wybor_opcji(3))
	{
	case 1:
		p.taktowanie = Niskie;
		break;
	case 2:
		p.taktowanie = Srednie;
		break;
	case 3:
		p.taktowanie = Wysokie;
		break;
	default:
		p.taktowanie = Srednie;
	}
	cout << "Wybierz pojemnosc pamieci ram :" << endl;
	cout << "1. Mala(4)" << endl;
	cout << "2. Srednia(8)" << endl;
	cout << "3. Duza(16)" << endl;
	switch (p.Wybor_opcji(3))
	{
	case 1:
		p.pojemnosc = Mala;
		break;
	case 2:
		p.pojemnosc = Srednia;
		break;
	case 3:
		p.pojemnosc = Duza;
		break;
	default:
		p.pojemnosc = Srednia;
	}
	return o;
}
/*
SzynaPamieci& SzynaPamieci::operator=(SzynaPamieci &s) {
	producent = s.producent;
	taktowanie = s.taktowanie;
	pojemnosc = s.pojemnosc;
	return *this;
}*/
//metody
int SzynaPamieci::Wybor_opcji(int liczba_opcji)
{
	bool blad = true;
	int wybor;
	while (blad)
	{
		cin >> wybor;
		if (wybor > 0 && wybor <= liczba_opcji)
			blad = false;
	}
	return wybor;
}
void SzynaPamieci::PrzetaktujGora(SzynaPamieci &ram) {
	if (ram.taktowanie == Niskie)
		ram.taktowanie = Srednie;
	else if (ram.taktowanie == Srednie)
		ram.taktowanie = Wysokie;
	else
		cout << "Jest to najwyzsze mozliwe taktowanie" << endl;
}
void SzynaPamieci::PrzetaktujDol(SzynaPamieci &ram) {
	if (ram.taktowanie == Wysokie)
		ram.taktowanie = Srednie;
	else if (ram.taktowanie == Srednie)
		ram.taktowanie = Niskie;
	else
		cout << "Jest to najnizsze mozliwe taktowanie" << endl;
}
Pojemnosc SzynaPamieci::losujPojemnosc() {
	int a = (rand() % 3 + 1);
	switch (a) {
	case 1:
		return Mala;
		break;
	case 2:
		return Srednia;
		break;
	case 3:
		return Duza;
		break;
	default:
		return Srednia;
	}
}
Taktowanie SzynaPamieci::losujTaktowanie() {
	int a = (rand() % 3 + 1);
	switch (a) {
	case 1:
		return Niskie;
		break;
	case 2:
		return Srednie;
		break;
	case 3:
		return Wysokie;
		break;
	default:
		return Srednie;
	}
}
SzynaPamieci::~SzynaPamieci()
{
	DEBUG("Niszcze szyne pamieci")

}
