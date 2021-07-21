#include "ruchsi.h"

using namespace std;

const int maxGlebia = 2;

void rundaSI(Pole& Pole, int ile)
{
    Ruch Ruch = znajdzNajlepszy(Pole, ile);
    Pole.pole.at(Ruch.wiersz).at(Ruch.kolumna) = 'O';
}

bool czyZostalRuch(Pole& Pole)
{
    for (int i = 0; i < Pole.pole.size(); i++)
        for (int j = 0; j < Pole.pole.at(i).size(); j++)
            if (Pole.pole.at(i).at(j) == ' ')
                return true;
    return false;
}

int licz(Pole Pole, int ile)
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
					return -10;
				if (tmp.compare(si) == 0)
					return 10;
			}

			tmp.clear();
			w = i;

			while (k < Pole.pole.at(w).size() && k <= ile)
			{
				tmp.push_back(Pole.pole.at(w).at(k));
				k++;
				if (tmp.compare(gracz) == 0)
					return -10;
				if (tmp.compare(si) == 0)
					return 10;
			}

			tmp.clear();
			k = j;

			while ((w < Pole.pole.size() && w <= ile) && (k < Pole.pole.at(w).size() && k <= ile))
			{
				tmp.push_back(Pole.pole.at(w).at(k));
				w++;
				k++;
				if (tmp.compare(gracz) == 0)
					return -10;
				if (tmp.compare(si) == 0)
					return 10;
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
                    return -10;
                if (tmp.compare(si) == 0)
                    return 10;
            }

            tmp.clear();
        }
    }

	return 0;
}

int minimax(Pole Pole, int glebokosc, bool czyMax, int ile)
{
    int wynik = licz(Pole, ile);

    if (wynik == 10)
        return wynik;

    if (wynik == -10)
        return wynik;

    if (czyZostalRuch(Pole) == false)
        return 0;

    if (czyMax)
    {
        int best = -1000;

        for (int i = 0; i < Pole.pole.size(); i++)
        {
            for (int j = 0; j < Pole.pole.at(i).size(); j++)
            {
                if (Pole.pole.at(i).at(j) == ' ' && (glebokosc) < maxGlebia)
                {
                    Pole.pole.at(i).at(j) = 'O';

                    best = max(best, minimax(Pole, glebokosc + 1, !czyMax, ile));

                    Pole.pole.at(i).at(j) = ' ';
                }
            }
        }
        return best-glebokosc;
    }

    else
    {
        int best = 1000;

        for (int i = 0; i < Pole.pole.size(); i++)
        {
            for (int j = 0; j < Pole.pole.at(i).size(); j++)
            {
                if (Pole.pole.at(i).at(j) == ' ' && (glebokosc ) < maxGlebia)
                {
                    Pole.pole.at(i).at(j) = 'X';

                    best = min(best, minimax(Pole, glebokosc + 1, !czyMax, ile));

                    Pole.pole.at(i).at(j) = ' ';
                }
            }
        }
        return best+glebokosc;
    }
}

Ruch znajdzNajlepszy(Pole Pole, int ile)
{
    int bestWar = -1000;
    Ruch bestRuch;
    bestRuch.wiersz = -1;
    bestRuch.kolumna = -1;

    for (int i = 0; i < Pole.pole.size(); i++)
    {
        for (int j = 0; j < Pole.pole.at(i).size(); j++)
        {
            if (Pole.pole.at(i).at(j) == ' ')
            {
                Pole.pole.at(i).at(j) = 'O';

                int moveVal = minimax(Pole, 0, false, ile);

                Pole.pole.at(i).at(j) = ' ';

                if (moveVal > bestWar)
                {
                    bestRuch.wiersz = i;
                    bestRuch.kolumna = j;
                    bestWar = moveVal;
                }
            }
        }
    }
    return bestRuch;
}