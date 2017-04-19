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
	marka = losuj();
	iloscPlyt++;
	iloscSzyn = 4;
	wejsciaPCI = 3;
	szynyZajete = 2;
	PCIzajete = 2;
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
		for (int i = 0; i < PCIzajete; i++)
		{
			karty.push_back(PCI());
		}

	}
}


PlytaGamingowa::~PlytaGamingowa()
{
}
