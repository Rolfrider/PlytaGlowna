// PlytaGlowna.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "PlytaGlowna.h"
#include"PlytaStacjonarna.h"
#include"PlytaMobilna.h"
#include "PlytaGamingowa.h"
#include<iostream>

int Wprowadzanie_inta(string, char, char);
void test();

PlytaGlowna *p;
PlytaStacjonarna s;
PlytaMobilna m;
PlytaGamingowa g;
vector<PlytaGlowna*> plyty;

int main()
{

	srand(time(NULL));
	bool koniec = false;
	p = &s;
	string obiekt = "Plyta Stacjonarna";
	cout << "Aplikacja testowa Projektu Plyta Glowna" << endl;
	cout << "Wszystkie operacje ralizowane sa na wskaznikach klasy podstawowej" << endl;
	while (!koniec)
	{
		cout << "\n\n\n\n" << endl;
		cout << "Aktualnie wybrany obiekt - "<< obiekt << endl;
		cout << "1. Wybor obiektu" << endl;
		cout << "2. Zapis obiektu w pliku" << endl;
		cout << "3. Wyswietlenie informacji o obiekcie" << endl;
		cout << "4. Wczytanie obiektu z pliku" << endl;
		cout << "5. Testowanie obiektow(wszystkich)" << endl;
		cout << "6. Wyjscie z programu" << endl;
		switch (Wprowadzanie_inta("Wprowdz liczbe odpowiadajaca dzialaniu", '1', '6')) 
		{
			cout << "\n" << endl;
			case 1: 
			{
				switch (Wprowadzanie_inta("Wprowadz numer obiektu\n 1. Plyta Stacjonarna \n 2. Plyta Mobilna \n 3. Plyta Gamingowa", '1', '3'))
				{
					case 1:
					{
						p = &s;
						obiekt = "Plyta Stacjonarna";
						break;
					}
					case 2:
					{
						p = &m;
						obiekt = "Plyta Mobilna";
						break;
					}
					case 3:
					{
						p = &g;
						obiekt = "Plyta Gamingowa";
						break;
					}
				}
				system("cls");
				break;
			}
			case 2:
			{
				p->wpiszDoPliku();
				break;
			}
			case 3:
			{
				p->wypiszDane();
				cout << " Wciœnij ENTER, aby kontynuowac " << endl;
				getchar();
				system("cls");
				break;
			}
			case 4:
			{
				p->wczytajZPliku();
				break;
			}
			case 5:
			{
				test();
				break;
			}
			case 6:
			{
				koniec = true;
				break;
			}
		}


	}
	

    return 0;
}

void test()
{
	cout << endl;
	cout << "Test metod wirualnych na wektorze" << endl;
	cout << "Dodajemy nasze obiekty do vectora" << endl;
	cout << endl;
	plyty.push_back(&s);
	plyty.push_back(&g);
	plyty.push_back(&m);
	cout << "Plyta Stacjonarna: " << endl;
	plyty[0]->stan();
	cout << endl;
	plyty[0]->wypiszDane();
	cout << " Wciœnij ENTER, aby kontynuowac " <<endl;
	getchar();
	system("cls");
	cout << "Plyta Gamingowa: " << endl;
	plyty[1]->stan();
	cout << endl;
	plyty[1]->wypiszDane();
	cout << " Wciœnij ENTER, aby kontynuowac " << endl;
	getchar();
	system("cls");
	cout << "Plyta Mobilna: " << endl;
	plyty[2]->stan();
	cout << endl;
	plyty[2]->wypiszDane();
	cout << " Wciœnij ENTER, aby kontynuowac " << endl;
	getchar();
	system("cls");

}

int Wprowadzanie_inta(string zapytanie, char min, char max)
{
	int wartosc;
	bool blad = true;
	string znaki;
	while (blad)
	{
		cout << zapytanie << endl;
		getline(cin, znaki);
		blad = false;
		for (int i = 0; i < znaki.length(); i++)
		{
			if (znaki[i] < min || znaki[i]> max)
				blad = true;
			else
				continue;
		}
	}
	istringstream iss(znaki);
	iss >> wartosc;
	return wartosc;
}
