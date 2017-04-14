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
Soket::Soket(int rodzaj, int liczbaRdzeni, float taktowanie, int pamiecCache) {
	this->rodzaj=rodzaj;
	this->liczbaRdzeni=liczbaRdzeni;
	this->taktowanie=taktowanie;
	this->pamiecCache=pamiecCache;
}
// OPERATORY
ostream& operator<<(ostream &o, Soket &s) {
	o << "Dane procesora:" << endl;
	o << "Liczba Rdzeni : " << s.liczbaRdzeni << endl;
	o << "Taktowanie Kazdego Rdzeniea : " << s.taktowanie << " GHz" << endl;
	o << "Gniazdo Procesora : " << s.rodzaj << endl;
	o << "Pamiec Cache : " << s.pamiecCache << " MB" << endl;
	return o;
}
istream& operator >> (istream &o,Soket &p) {
	p.rodzaj = p.Wprowadzenie_inta("Podaj nr. id gniazda procesora ");
	p.liczbaRdzeni = p.Wprowadzenie_inta("Podaj liczbe rdzeni procesora :");
	p.taktowanie = p.Wprowadzenie_float("Podaj taktowanie w GHz procesora :");
	p.pamiecCache= p.Wprowadzenie_inta("Podaj liczbe MB pamieci Cache procesora :");
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
// METODY
float Soket::Wprowadzenie_float(string zapytanie)
{
	float wartosc;
	bool blad = true;
	string znaki;
	while (blad)
	{
		cout << zapytanie << endl;
		cin >> znaki;
		blad = false;
		for (int i = 0; i < znaki.length(); i++)
		{
			if ((znaki[i] < '0' || znaki[i]>'9') && (znaki[i] != '.'))
				blad = true;
			else
				continue;
		}
	}
	//istringstream iss(znaki);
	//iss >> wartosc;
	wartosc = stof(znaki);
	return wartosc;
}
int Soket::Wprowadzenie_inta(string zapytanie)
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

	
}
