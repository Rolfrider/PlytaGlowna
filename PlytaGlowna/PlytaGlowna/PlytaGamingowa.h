#pragma once
#include "PlytaStacjonarna.h"

typedef string kolor;
class PlytaGamingowa :
	public PlytaStacjonarna
{
	kolor podswietlenieRGB;
	string cechySzczegolne;
	bool wsparcieVR;
	bool nvidiaSLI;
	string material;
public:
	PlytaGamingowa();
	~PlytaGamingowa();
};

