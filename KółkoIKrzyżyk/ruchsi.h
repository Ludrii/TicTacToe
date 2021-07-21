#ifndef RUCHSI_H_
#define RUCHSI_H

#include "pole.h"
#include <algorithm>

struct Ruch
{
    int wiersz = 0, kolumna = 0;
};

void rundaSI(Pole& Pole, int ile);

bool czyZostalRuch(Pole& Pole);

int licz(Pole Pole, int ile);

int minimax(Pole Pole, int glebokosc, bool czyMax, int ile);

Ruch znajdzNajlepszy(Pole Pole, int ile);

#endif // !RUCHSI_H_
