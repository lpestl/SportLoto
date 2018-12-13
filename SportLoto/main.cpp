#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <thread>
#include "tiket.h"
#include "rusloto.h"

void threadFunction()
{
	int countT1 = 0;
	int countT2 = 0;
	int countT3_50 = 0;
	int countT3 = 0;
	int JP = 0;

	for (int i = 0; i < 100000; i++) {
		system("cls");
		// do smth
		tiket *t = new tiket();

		if (t->initTiket()) {
			t->printTiket();

			rusloto *game = new rusloto();

			std::vector<int> b = game->game();
			game->printBoches();
			t->checkTiket(b);

			if (t->toure1) countT1++;
			if (t->toure2) countT2++;
			if (t->toure3) countT3++;
			if (t->toure3_50) countT3_50++;
			if (t->jackPot) JP++;

			printf("\n\nWins:\nToure 1 = %d (%.5f)\n", countT1, (float)countT1 / (i+1));
			printf("Toure 2 = %d (%.5f)\n", countT2, (float)countT2 / (i+1));
			printf("Toure 3 = %d (%.5f)\n", countT3, (float)countT3 / (i + 1));
			printf("Toure 3 (1/2) = %d (%.5f)\n", countT3_50, (float)countT3_50 / (i + 1));
			printf("JACKPOT = %d (%.5f)\n", JP, (float)JP / (i + 1));
			delete game;
		}

		delete t;
	}
}

int main()
{
	std::thread thr(threadFunction);
	thr.join();

	char ch;
	bool ex = false;
	while ((ch = getch()) && !ex) {
		switch (ch) {
		case 'e':
			printf("Exit\n");
			ex = true;
			break;
		default:
			printf("%c - pressed.\n", ch);
			break;
		}
	}
	system("pause");
	return 0;
}