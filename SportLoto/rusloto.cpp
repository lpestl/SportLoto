#include "rusloto.h"

rusloto::rusloto()
{
	count = 87;

	for (int i = 1; i <= 90; i++) {
		boch.push_back(i);
	}

	srand(time(0));
	std::random_shuffle(boch.begin(), boch.end());
	std::random_shuffle(boch.begin(), boch.end());
	std::random_shuffle(boch.begin(), boch.end());
	std::random_shuffle(boch.begin(), boch.end());
	std::random_shuffle(boch.begin(), boch.end());
}


rusloto::~rusloto()
{
}

std::vector<int> rusloto::game() {
	for (int i = 0; i < count; i++) {
		std::random_shuffle(boch.begin(), boch.end());
		bochInGame.push_back(boch.back());
		boch.pop_back();
	}

	return bochInGame;
}

void rusloto::printBoches() {
	printf("\n");
	for (int i = 0; i < bochInGame.size(); i++) {
		printf("%d ", bochInGame.at(i));
	}

	printf("\n");
	printf("\n");
}