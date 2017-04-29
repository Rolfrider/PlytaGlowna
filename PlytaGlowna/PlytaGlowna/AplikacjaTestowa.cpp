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
	p[0] = &m;
	p[0]->stan();
	p[1] = &s;
	p[1]->stan();
	p[2] = &g;
	p[2]->stan();
	
    return 0;
}

