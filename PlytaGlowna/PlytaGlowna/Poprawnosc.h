#pragma once
#include<iostream>
#include<sstream>
#include <string>
using namespace std;

int Wprowadzanie_inta(string zapytanie)
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

float Wprowadzanie_float(string zapytanie) 
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
			if ((znaki[i] < '0' || znaki[i]>'9') && (znaki[i] !='.'))
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

int Wybor_opcji(int liczba_opcji)
{
	bool blad= true;
	int wybor;
	while (blad)
	{
		cin >> wybor;
		if (wybor > 0 && wybor <= liczba_opcji)
			blad = false;
	}
	return wybor;
}