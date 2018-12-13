#pragma once
#include <vector>
#include "stdio.h"
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <time.h>

class rusloto
{
public:
	rusloto();
	~rusloto();

	std::vector<int> game();
	void printBoches();

private:
	std::vector<int> boch;
	std::vector<int> bochInGame;
	int count;
};

