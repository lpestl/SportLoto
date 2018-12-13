#include "tiket.h"
#include "stdio.h"
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <time.h>


tiket::tiket()
{
	toure1 = false;
	toure2 = false;
	toure3_50 = false;
	toure3 = false;
	jackPot = false;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 6; j++) {
			tik[i][j] = -1;
		}
	}

	for (int i = 1; i <= 90; i++) {
		nums.push_back(i);
	}

	srand(time(0));
	std::random_shuffle(nums.begin(), nums.end());
	//std::random_shuffle(nums.begin(), nums.end());
	//std::random_shuffle(nums.begin(), nums.end());	
}


tiket::~tiket()
{
}

bool tiket::initTiket() {
	int num = 0;
	int col1 = 0, col2 = 0, colS1[9], colS2[9], colSt1[3], colSt2[3];
	bool blok1 = false;
	bool blok2 = false;
	for (int i = 0; i < 9; i++) {
		colS1[i] = 0;
		colS2[i] = 0;
	}

	for (int i = 0;i < 3;i++) {
		colSt1[i] = 0;
		colSt2[i] = 0;
	}

	int allcount = 0;

	do {
		if (allcount > 1000) return false;
		allcount++;

		blok1 = false;
		blok2 = false;
		std::random_shuffle(nums.begin(), nums.end());
		int current = nums.back();
		bool isit = false;
		//printf("Current num = %d\n", current);
		// Check this number
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 6; j++) {
				if (tik[i][j] == current) {
					//printf("[INFO] Is it. Next.\n");
					isit = true;
					//continue;
				}
			}
		}
		if (isit) continue;

		int i = (current - 1) / 10;
		//if (current == 90) i = 8;

		if (colS1[i] == 2) blok1 = true;
		if (colS2[i] == 2) blok2 = true;
		if ((colSt1[0] == 5) && (colSt1[1] == 5) && (colSt1[2] == 5)) blok1 = true;
		if ((colSt2[0] == 5) && (colSt2[1] == 5) && (colSt2[2] == 5)) blok2 = true;
		if (col1 == 15) blok1 = true;
		if (col2 == 15) blok2 = true;

		if (blok1 && blok2) {
			//printf("[INFO] All S is full. Next.\n");
			std::random_shuffle(nums.begin(), nums.end());
			//getch();
			continue;
		}

		if (!blok1) {
			int j;
			for (int k = 0; k < 3; k++) {
				j = k;
				if (colSt1[j] == 5) continue;
				else {
					if (tik[i][j] > 0) continue;
					else break;
				}
			}

			if (tik[i][j] > 0) continue;
			tik[i][j] = current;
			nums.pop_back();
			//printf("ADD %d\n", tik[i][j]);
			colS1[i]++;
			colSt1[j]++;
			col1++;
			num++;
		}
		else {
			int j;
			for (int k = 3; k < 6; k++) {
				j = k;
				if (colSt2[j-3] == 5) continue;
				if (tik[i][j] > 0) continue;
				else break;
			}

			if (tik[i][j] > 0) continue;
			tik[i][j] = current;
			nums.pop_back();
			//printf("ADD %d\n", tik[i][j]);
			colS2[i]++;
			colSt2[j-3]++;
			col2++;
			num++;
		}

		//printTiket();
		//getch();
	} while (num < 30);

	return true;
}

void tiket::printTiket() {
	for (int i = 0; i < 9; i++) {
		printf("--------------------------        ------------------------\n");
		for (int j = 0; j < 6; j++) {
			if (j == 3) printf("\t  |");
			if (tik[i][j] > 0) printf(" %d\t |", tik[i][j]);
			else printf(" \t |");
		}
		printf("\n");

	}
	printf("--------------------------        ------------------------\n");
}

void tiket::checkTiket(std::vector<int> boches) {
	//check toure1
	for (int l = 0; l < 10; l++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 6; j++) {
				if (tik[i][j] == boches.at(l)) tik[i][j] = 100;
			}
		}
	}

	//printf("\n\nToure 1:\n");
	//printTiket();

	int colStr = 0;
	for (int i = 0; i < 6; i++) {
		colStr = 0;
		for (int j = 0; j < 9; j++) {
			if (tik[j][i] == 0) colStr++;
		}
		if (colStr >= 5) {
			toure1 = true;
			printf("[INFO] TOURE 1 is WIN!!!\n\n");
		}
	}

	// check JackPot
	for (int l = 10; l < 15; l++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 6; j++) {
				if (tik[i][j] == boches.at(l)) tik[i][j] = 100;
			}
		}
	}


	//printf("\n\nJackPot:\n");
	//printTiket();
	int colJP = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 6; j++) {
			if (tik[i][j] == 100) colJP++;
		}
	}
	if (colJP == 15) {
		jackPot = true;
		printf("[INFO] ____JACK POT____ is WIN!!!\n\n");
	}

	// Chech Toure 2
	for (int l = 15; l < 40; l++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 6; j++) {
				if (tik[i][j] == boches.at(l)) tik[i][j] = 100;
			}
		}
	}


	//printf("\n\nToure 2:\n");
	//printTiket();
	int col = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 3; j++) {
			if (tik[i][j] == 100) col++;
		}
	}
	if (col == 15) {
		toure2 = true;
		printf("[INFO] Toure 2 is WIN!!!\n\n");
	}
	else {
		int col = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 3; j < 6; j++) {
				if (tik[i][j] == 100) col++;
			}
		}
		if (col == 15) {
			toure2 = true;
			printf("[INFO] Toure 2 is WIN!!!\n\n");
		}
	}

	// Check Toure 3 (50%)
	for (int l = 40; l < 50; l++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 6; j++) {
				if (tik[i][j] == boches.at(l)) tik[i][j] = 100;
			}
		}
	}

	//printf("\n\nToure 3:\n");
	//printTiket();
	col = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 6; j++) {
			if (tik[i][j] == 100) col++;
		}
	}
	if (col == 30) {
		toure3_50 = true;
		printf("[INFO] Toure 3 (50%) is WIN!!!\n\n");
	}

	// Check Toure 3 
	for (int l = 50; l < 87; l++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 6; j++) {
				if (tik[i][j] == boches.at(l)) tik[i][j] = 100;
			}
		}
	}

	//printf("\n\nToure 3:\n");
	//printTiket();
	col = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 6; j++) {
			if (tik[i][j] == 100) col++;
		}
	}
	if (col == 30) {
		toure3 = true;
		printf("[INFO] Toure 3 is WIN!!!\n\n");
	}
}