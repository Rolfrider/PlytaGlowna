// PlytaGlowna.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "PlytaGlowna.h"
#include"PlytaStacjonarna.h"
#include"PlytaMobilna.h"
#include "PlytaGamingowa.h"
#include<iostream>

int main()
{

	srand(time(NULL));
	PlytaGlowna *p[3];
	PlytaGamingowa g;
	PlytaStacjonarna s;
	PlytaMobilna m;
	
	m.wpiszDoPliku();
	cout << m;
	m.wczytajZPliku();
	cout << m;
    return 0;
}

