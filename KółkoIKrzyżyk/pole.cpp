#include "pole.h"

using namespace std;

Pole::Pole(int SIZE)
{
	vector<char> tmp;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			tmp.push_back(' ');
		}
		pole.push_back(tmp);
		tmp.clear();
	}
}

ostream& operator<<(ostream& os, const Pole& obj)
{
	char znak = 'A';
	int liczba = 1;

	os << endl << endl
		<<" Gracz 'X'" << "\tvs.\t" << "SI 'O'" << endl << endl;

	for (int j = 0; j < obj.pole.size(); j++)
	{
		os << "\t" << (char)(znak + j);
	}

	for (int i = 0; i < obj.pole.size(); i++)
	{
		os << endl << endl
			<< liczba + i;

		for (int j = 0; j < obj.pole.at(i).size(); j++)
		{
			os << "\t" << obj.pole.at(i).at(j);
		}
	}

	os << endl << endl;

	return os;
}

Pole::Pole(const Pole& fPole)
{
	vector<char> tmp;

	for (int i = 0; i < fPole.pole.size(); i++)
	{
		for (int j = 0; j < fPole.pole.at(i).size(); j++)
		{
			tmp.push_back(fPole.pole.at(i).at(j));
		}
		pole.push_back(tmp);
		tmp.clear();
	}
}