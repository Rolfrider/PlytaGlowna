// PlytaGlowna.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "PlytaGlowna.h"
#include"PlytaStacjonarna.h"
#include<iostream>

int main()
{

	srand(time(NULL));
	PlytaStacjonarna p;
	cin >> p;
	cout << p;
    return 0;
}

