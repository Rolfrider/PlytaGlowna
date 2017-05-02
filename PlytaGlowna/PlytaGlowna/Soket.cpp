#include "stdafx.h"
#include "Soket.h"

#ifdef _DEBUG
#define DEBUG(x)
#else
#define DEBUG(x) cout<<x<<endl;
#endif // _DEBUG

// KONSTRUKTORY
Soket::Soket()
{
	DEBUG("Tworze soket")
	rodzaj = 2011;
	liczbaRdzeni = 4;
	taktowanie = 3.5;
	pamiecCache = 6;

}
Soket::Soket(int rodzaj, int liczbaRdzeni, float taktowanie, int pamiecCache, bool mobilna) {
	this->rodzaj=rodzaj;
	this->liczbaRdzeni=liczbaRdzeni;
	this->taktowanie=taktowanie;
	this->pamiecCache=pamiecCache;
	if (mobilna == true)
	{
		zintegrowanaKartaGraficzna = new PCI(mobilna);
	}
}
Soket::Soket(Soket &s) {
	rodzaj = s.rodzaj;
	liczbaRdzeni = s.liczbaRdzeni;
	taktowanie = s.taktowanie;
	pamiecCache = s.pamiecCache;
	if (s.zintegrowanaKartaGraficzna != nullptr)
	{
		delete zintegrowanaKartaGraficzna;
		zintegrowanaKartaGraficzna = new PCI(s.zintegrowanaKartaGraficzna);
	}
	else
		zintegrowanaKartaGraficzna = nullptr;
}
// OPERATORY
ostream& operator<<(ostream &o, Soket &s) {
	cout << "Dane procesora:" << endl;
	cout << "Liczba Rdzeni : "; o << s.liczbaRdzeni << endl;
	cout << "Taktowanie Kazdego Rdzeniea : "; o << s.taktowanie; cout << " GHz"; o << endl;
	cout << "Gniazdo Procesora : "; o << s.rodzaj << endl;
	cout << "Pamiec Cache : "; o << s.pamiecCache; cout << " MB"; o << endl;
	if (s.zintegrowanaKartaGraficzna != nullptr)
	{
		cout << "Zintegrowana karta graficzna" << endl;
		o << *s.zintegrowanaKartaGraficzna << endl;
	}
	return o;
}
istream& operator >> (istream &o,Soket &p) {
	
	cout << "Podaj liczbe rdzeni procesora" << endl;
	o >> p.liczbaRdzeni;
	cout << "Podaj taktowanie w GHz procesora" << endl;
	o >> p.taktowanie;
	cout << "Podaj nr. id gniazda procesora" << endl;
	o >> p.rodzaj;
	cout << "Podaj liczbe MB pamieci Cache procesora" << endl;
	o >> p.pamiecCache;
	if (p.zintegrowanaKartaGraficzna != nullptr)
	{
		o >> *p.zintegrowanaKartaGraficzna;
	}
	return o;
}
bool Soket::operator==(Soket &soket) {
	if (rodzaj == soket.rodzaj) {
		cout << "Mozna wymienic" << endl;
		return true;
	}
	else {
		cout << "Nie mozna wymienic, zle gniazdo procesora" << endl;
		return false;
	}
}
Soket& Soket::operator= (const Soket &s) 
{
	rodzaj = s.rodzaj;
	liczbaRdzeni = s.liczbaRdzeni;
	taktowanie = s.taktowanie;
	pamiecCache = s.pamiecCache;
	if (s.zintegrowanaKartaGraficzna != nullptr)
	{
		delete zintegrowanaKartaGraficzna;
		zintegrowanaKartaGraficzna = new PCI(s.zintegrowanaKartaGraficzna);
	}
	else
		zintegrowanaKartaGraficzna = nullptr;

	return *this;
}
// METODY
void Soket::Spec() {
	cout << "Dane procesora:" << endl;
	cout << "Liczba Rdzeni : " << pokazLiczbeRdzenie() << endl;
	cout << "Taktowanie Kazdego Rdzeniea : " << pokazTaktowanie() << " GHz" << endl;
	cout << "Gniazdo Procesora : " << pokazRodzaj() << endl;
	cout << "Pamiec Cache : " << pokazPamiec() << " MB" << endl;
}
int Soket::pokazRodzaj() {
	return rodzaj;
}
int Soket::pokazLiczbeRdzenie() {
	return liczbaRdzeni;
}
int Soket::pokazPamiec() {
	return pamiecCache;
}
float Soket::pokazTaktowanie() {
	return taktowanie;
}
void Soket::podkrecProcka() {
	taktowanie = taktowanie*1.2;
}
Soket::~Soket()
{
	DEBUG("Niszcze soket")
	if (zintegrowanaKartaGraficzna != nullptr)
		delete zintegrowanaKartaGraficzna;

	
}
