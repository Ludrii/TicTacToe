#ifndef POLE_H
#define POLE_H

#include <vector>
#include <iostream>

struct Pole
{
	std::vector<std::vector<char>> pole;
	Pole(int SIZE);
	Pole(const Pole& fPole);
};

std::ostream& operator<<(std::ostream& os, const Pole& obj);

#endif // !POLE_H
