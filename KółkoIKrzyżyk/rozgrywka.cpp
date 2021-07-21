#include "rozgrywka.h"
#include "ruchsi.h"
#include <string>
#include <cctype>
#include <ctime>

using namespace std;

bool rozgrywka(int SIZE, int ile)
{
	Pole Pole(SIZE);
	int w = 0, k = 0;

	/*srand(time(NULL));

	w = rand() % SIZE;
	k = rand() % SIZE;
	
	Pole.pole.at(w).at(k) = 'O';*/
	cout << Pole;
	while (true)
	{
		rundaGracza(Pole);
		cout << Pole;
		if (sprawdzWynik(Pole, ile) == 1)
		{
			cout << "Wygrywa gracz!" << endl;
			break;
		}
		if (!czyZostalRuch(Pole))
		{
			cout << "Remis" << endl;
			return false;
		}
		rundaSI(Pole, ile);
		cout << Pole;
		if (sprawdzWynik(Pole, ile) == -1)
		{
			cout << "Wygrywa komputer!" << endl;
			break;
		}
		if (!czyZostalRuch(Pole))
		{
			cout << "Remis" << endl;
			return false;
		}
	}

	return 0;
}

void rundaGracza(Pole& Pole)
{
	string str;
	char znak;
	int liczba;
	int k, w;

	while (true)
	{
		cout << "Gdzie wpisaæ 'X'?" << endl;
		str.clear();
		cin >> str;
		while (str.length()!=2)
		{
			cout << "Podano z³y ci¹g znaków. Spróbuj jeszcze raz" << endl;
			str.clear();
			cin >> str;
		}

		znak = str.at(0);
		str.erase(str.begin());
		liczba = stoi(str);
		znak = toupper(znak);
		w = liczba - 1;
		k = znak - 'A';

		if (Pole.pole.at(w).at(k) == ' ')
		{
			Pole.pole.at(w).at(k) = 'X';
			break;
		}
		else
			cout << "To pole jest ju¿ zajête. Spróbuj jeszcze raz" << endl;
	}
}

int sprawdzWynik(Pole& Pole, int ile)
{
	int licznik = 0;
	string gracz, si;

	for (int i = 0; i < ile; i++)
	{
		gracz.push_back('X');
		si.push_back('O');
	}

	for (int i = 0; i < Pole.pole.size(); i++)
	{
		for (int j = 0; j < Pole.pole.at(i).size(); j++)
		{
			int w = i, k = j;
			string tmp;

			while (w < Pole.pole.size() && w <= ile)
			{
				tmp.push_back(Pole.pole.at(w).at(k));
				w++;
				if (tmp.compare(gracz) == 0)
					return 1;
				if (tmp.compare(si) == 0)
					return -1;
			}

			tmp.clear();
			w = i;

			while (k < Pole.pole.at(w).size() && k <= ile)
			{
				tmp.push_back(Pole.pole.at(w).at(k));
				k++;
				if (tmp.compare(gracz) == 0)
					return 1;
				if (tmp.compare(si) == 0)
					return -1;
			}

			tmp.clear();
			k = j;

			while ((w < Pole.pole.size() && w <= ile) && (k < Pole.pole.at(w).size() && k <= ile))
			{
				tmp.push_back(Pole.pole.at(w).at(k));
				w++;
				k++;
				if (tmp.compare(gracz) == 0)
					return 1;
				if (tmp.compare(si) == 0)
					return -1;
			}
		}
	}

	for (int i = Pole.pole.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < Pole.pole.at(i).size(); j++)
		{
			int w = i, k = j;
			string tmp;

			while ((w < Pole.pole.size() && w <= ile) && (k < Pole.pole.at(w).size() && k <= ile))
			{
				tmp.push_back(Pole.pole.at(w).at(k));
				w--;
				k++;
				if (tmp.compare(gracz) == 0)
					return 1;
				if (tmp.compare(si) == 0)
					return -1;
			}

			tmp.clear();
		}
	}

	return 0;
}