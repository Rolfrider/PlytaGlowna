// PlytaGlowna.cpp: Okre�la punkt wej�cia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "PlytaGlowna.h"
#include"PlytaStacjonarna.h"
#include"PlytaMobilna.h"
#include<iostream>

int main()
{

	srand(time(NULL));
	PlytaMobilna p;
	cin >> p;
	cout << p;
    return 0;
}

