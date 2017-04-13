#pragma once
#include<string>
#include<ctime>
#include <cstdlib>
using namespace std;
class PCI
{
public:
	PCI();
	~PCI();
	friend ostream& operator<<(ostream &o, PCI &p);
	string losujRodzaj();
	string losujProducenta();
private:
	string rodzaj;
	string producent;
	int pamienc;

};

