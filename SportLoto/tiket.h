#pragma once

#include <vector>

class tiket
{
public:
	tiket();
	~tiket();

	bool initTiket();
	void printTiket();
	void checkTiket(std::vector<int> boches);


	bool toure1;
	bool toure2;
	bool toure3_50;
	bool toure3;
	bool jackPot;

private:
	int tik[9][6];
	std::vector<int> nums;

};

