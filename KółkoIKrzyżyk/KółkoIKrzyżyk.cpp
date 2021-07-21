#include "rozgrywka.h"

using namespace std;

int main()
{
    int SIZE = 0;
    int ile = 0;

    cout << "Witaj w grze \"Kółko i krzyżyk\"" << endl
        << "Jak duże ma być pole?" << endl;
    cin >> SIZE;

    cout << "Ile znaków w rzędzie oznacza wygraną?" << endl;
    cin >> ile;
    while (ile > SIZE)
    {
        cout << "Ilość znaków w rzędzie nie może być większa niż rozmiar pola" << endl
            << "Wpisz ilość znaków jeszcze raz" << endl;
        cin >> ile;
    }

    rozgrywka(SIZE, ile);

    return 0;
}
