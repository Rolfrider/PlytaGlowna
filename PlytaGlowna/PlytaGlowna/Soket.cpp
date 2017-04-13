#include "stdafx.h"
#include "Soket.h"
#include<iostream>
#ifdef _DEBUG
#define DEBUG(x)
#else
#define DEBUG(x) cout<<x<<endl;
#endif // _DEBUG

Soket::Soket()
{
	DEBUG("Tworze soket")
	rodzaj = 2011;
	liczbaRdzeni = 4;
	taktowanie = 3.5;
	pamiecCache = 6;

}
Soket::Soket(int rodzaj, int liczbaRdzeni, float taktowanie, int pamiecCache) {
	this->rodzaj=rodzaj;
	this->liczbaRdzeni=liczbaRdzeni;
	this->taktowanie=taktowanie;
	this->pamiecCache=pamiecCache;
}
void Soket::Spec() {
	cout << "Dane procesora:" << endl;
	cout << "Liczba Rdzeni : " << pokazLiczbeRdzenie() << endl;
	cout << "Taktowanie Kazdego Rdzeniea : " << pokazTaktowanie() << " GHz" << endl;
	cout << "Gniazdo Procesora : " << pokazRodzaj() << endl;
	cout << "Pamiec Cache : " << pokazPamiec() << " MB" << endl;
}
ostream& operator<<(ostream &o, Soket &s) {
	o << "Dane procesora:" << endl;
	o << "Liczba Rdzeni : " << s.liczbaRdzeni << endl;
	o << "Taktowanie Kazdego Rdzeniea : " << s.taktowanie << " GHz" << endl;
	o << "Gniazdo Procesora : " << s.rodzaj << endl;
	o << "Pamiec Cache : " << s.pamiecCache << " MB" << endl;
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

	
}
