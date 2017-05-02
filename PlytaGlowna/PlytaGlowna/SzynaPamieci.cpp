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
SzynaPamieci::SzynaPamieci(int poj, int tak)
{
	producent = "RASUS";
	taktowanie = tak;
	pojemnosc = poj;
}
SzynaPamieci::SzynaPamieci(bool mobilna) :
	taktowanie(1866), pojemnosc(2), producent("MobileMem")
{
	DEBUG("Tworze szyne pamieci")
}
//operatory
ostream& operator<<(ostream &o, SzynaPamieci &s) {
	cout << "Kosc pamieci RAM" << endl;
	cout << "Producent : "; o << s.producent << endl;
	cout << "Taktowanie pamieci : "; o << s.taktowanie << endl;
	cout << "Pojemnosc : "; o << s.pojemnosc; cout << " GB"; o << endl;
	return o;
}
istream& operator >> (istream &o, SzynaPamieci &p) {

	cout << "Podaj producenta ramu :" << endl;
	o.ignore();
	getline(o, p.producent);
	cout << "Wybierz taktowanie ramu(Wpisz jedna z podanych wartosci) :" << endl;
	cout << "1. 1866" << endl;
	cout << "2. 2133" << endl;
	cout << "3. 2400" << endl;
	o >> p.taktowanie;
	cout << "Wybierz pojemnosc pamieci ram (Wpisz jedna z podanych wartosci):" << endl;
	cout << "1. 2 (GB)" << endl;
	cout << "2. 4 (GB)" << endl;
	cout << "3. 8 (GB)" << endl;
	cout << "3. 16 (GB)" << endl;
	o >> p.pojemnosc;
	return o;
}
//metody
void SzynaPamieci::PrzetaktujGora(SzynaPamieci &ram) {
	if (ram.taktowanie == 1866)
		ram.taktowanie = 2133;
	else if (ram.taktowanie == 2133)
		ram.taktowanie = 2400;
	else
		cout << "Jest to najwyzsze mozliwe taktowanie" << endl;
}
void SzynaPamieci::PrzetaktujDol(SzynaPamieci &ram) {
	if (ram.taktowanie == 2400)
		ram.taktowanie = 2133;
	else if (ram.taktowanie == 2133)
		ram.taktowanie = 1866;
	else
		cout << "Jest to najnizsze mozliwe taktowanie" << endl;
}
int SzynaPamieci::losujPojemnosc() {
	int a = (rand() % 3 + 1);
	switch (a) {
	case 1:
		return 4;
		break;
	case 2:
		return 8;
		break;
	case 3:
		return 16;
		break;
	default:
		return 8;
	}
}
int SzynaPamieci::losujTaktowanie() {
	int a = (rand() % 3 + 1);
	switch (a) {
	case 1:
		return 1866;
		break;
	case 2:
		return 2133;
		break;
	case 3:
		return 2400;
		break;
	default:
		return 2133;
	}
}
SzynaPamieci::~SzynaPamieci()
{
	DEBUG("Niszcze szyne pamieci")

}
