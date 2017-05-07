// PlytaGlowna.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "PlytaGlowna.h"
#include"PlytaStacjonarna.h"
#include"PlytaMobilna.h"
#include "PlytaGamingowa.h"
#include<iostream>
/// Funkcja kontrolujaca poprawnosc dnych wprowadzanych do konsoli
/**
Funkcja pobiera stringa nastepnie patrzy czy sklada sie on jedynie z liczb
gdy wszystko sie zgadza rzutujemy stringa na inta i sprawdzamy czy int jest w przedziale ktory jest wymagany 
jesli tak to funkcja zwraca podana wartosc;
*/
int Wprowadzanie_inta(string, int, int);
///Funkcja testujaca wszystkie obiekty
void test();

PlytaGlowna *p; ///< wskaznik na klase bazowa
PlytaStacjonarna s; ///< Obiekt Plyta Stacjonarna
PlytaMobilna m;///< Obiekt Plyta Mobilna
PlytaGamingowa g;///< Obiekt Plyta Gamingowa
vector<PlytaGlowna*> plyty;///< wektor wskaznikow na klase bazowa

int main()
{
	
	srand(time(NULL));
	bool koniec = false; ///< zmienna decydujaca o zakonczeniu programu 
	p = &s;
	string obiekt = "Plyta Stacjonarna"; ///< zmienna informujaca nas na jakim obiekcie aktualnie dzialamy 
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
		switch (Wprowadzanie_inta("Wprowdz liczbe odpowiadajaca dzialaniu", 1, 6)) 
		{
			cout << "\n" << endl;
			case 1: 
			{
				switch (Wprowadzanie_inta("Wprowadz numer obiektu\n 1. Plyta Stacjonarna \n 2. Plyta Mobilna \n 3. Plyta Gamingowa", 1, 3))
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
	cout << "1. Test metod wirualnych na wektorze i tablicy " << endl;
	cout << "2. Test z pierwszego projektu" << endl;
	cout << "3. Powrot" << endl;

	switch (Wprowadzanie_inta("Jakie testy chcesz wykonac?", 1, 3)) {
		case 1:
		{
			
			cout << "Testujemy metody wirtualne na wektorze" << endl;
			cout << endl;
			plyty.push_back(&s);
			plyty.push_back(&g);
			plyty.push_back(&m);
			for (int i = 0; i < plyty.size(); i++)
			{
				plyty[i]->stan();
				cout << endl;
				plyty[i]->wypiszDane();
				cout << " Wciœnij ENTER, aby kontynuowac " << endl;
				getchar();
				system("cls");
			}
			cout << "Testujemy metody wirtualne na tablicy" << endl;
			cout << " Wciœnij ENTER, aby kontynuowac " << endl;
			getchar();
			PlytaGlowna *plyty[3];
			plyty[0] = &s;
			plyty[1] = &g;
			plyty[2] = &m;
			for (int i = 0; i < 3; i++)
			{
				plyty[i]->stan();
				cout << endl;
				plyty[i]->wypiszDane();
				cout << " Wciœnij ENTER, aby kontynuowac " << endl;
				getchar();
				system("cls");
			}

			break;

		}
		case 2:
		{
			
			cout << "Tworzymy plyte Stacjonrna dynamicznie" << endl;
			PlytaStacjonarna* p = new PlytaStacjonarna;
			cout << "Niszczymy plyte glowna" << endl;
			delete p;
			cout << "Tworzymy Plyte Stacjonarna automatycznie" << endl;
			PlytaStacjonarna plyt;
			cout << "Test konstruktora kopiujacego" << endl;
			PlytaStacjonarna kopia(plyt);
			cout << "Test operatora '==' " << endl;
			cout << "Najpierw porownojemy nasz obiekt z jego kopia" << endl;
			if (plyt == kopia) {
				cout << "Plyty sa takie same" << endl;
			}
			cout << "Teraz porownujemy nasz obiekt z innym dowolnym obiektem" << endl;
			if (plyt == s) {
				cout << "Plyty sa takie same" << endl;
			}
			else
				cout << "Plyty nie sa takie same" << endl;
			s.dzialka();

			cout << "Test operatora '<<', ktory wypisuje dane plyty " << endl;
			cout << plyt;
			s.dzialka();

			cout << "Test operatora preinkrementacji '++'zmienna  " << endl;
			++plyt;
			s.dzialka();

			cout << "Test operatora predekrementacji '--'zmienna  " << endl;
			--plyt;
			s.dzialka();

			cout << "Test operatora postinkrementacji zmienna'++' " << endl;
			plyt++;
			s.dzialka();

			cout << "Test operatora postdekrementacji zmienna'--' " << endl;
			plyt--;
			s.dzialka();


			cout << "Test operatora indeksowego zmienna'[]'," << endl;
			cout << "ktory zwraca karte podlaczona do zlacza PCI o wpisanym indeksie " << endl;
			cout << plyt[0];
			s.dzialka();

			cout << "Test operatora konwersji," << endl;
			PlytaStacjonarna test(4, 2, 3, 1);
			cout << "ktory dziala tak int a = PlytaGLowna => a = szynyZajete " << endl;
			int a;
			a = test;
			cout << " Nasze a = " << a << " Przechowuje dane o liczbie zajetych szyn w pamieci" << endl;
			s.dzialka();

			cout << "Test operatora PlytaGlowna'^'a," << endl;
			cout << "ktory dziala tak, ze w zaleznosci od a podnosi lub obniza taktowanie pamieci " << endl;
			cout << "Dla a > 0" << endl;
			plyt ^ 1;
			cout << "Dla a = 0" << endl;
			plyt ^ 0;
			cout << "Dla a < 0" << endl;
			plyt ^-1;
			s.dzialka();

			cout << "Test operatora przypisania '=' " << endl;
			plyt = s;
			s.dzialka();

			cout << " Wciœnij ENTER, aby kontynuowac " << endl;
			getchar();
			system("cls");
		}
		case 3:
		{
			break;
		}
	}

}

int Wprowadzanie_inta(string zapytanie, int min, int max)
{
	int wartosc;
	bool blad = true;
	string znaki;
	while (blad)
	{
		cout << zapytanie << endl;
		getline(cin, znaki);
		for (int i = 0; i < znaki.length(); i++)
		{
			if (znaki[i] < 0 || znaki[i]> 9)
			{
				blad = true;
				break;
			}
			else
				continue;
		}
		istringstream iss(znaki);
		iss >> wartosc;
		if(wartosc >= min && wartosc<=max)
			blad = false;
	}
	
	return wartosc;
}
