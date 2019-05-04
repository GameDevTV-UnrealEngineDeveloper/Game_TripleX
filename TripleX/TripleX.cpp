#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
	std::cout << " secure server room...\nEnter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	// declare 3 number code
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	// print CodeSum and CodeProduct to terminal
	std::cout << "+ There are 3 numbers in the code";
	std::cout << "\n+ The codes add-up to: " << CodeSum;
	std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

	// store player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// check if the player's guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\n*** Well done agent!  You have extracted a file!  Keep going! ***";

		return true;
	}
	else
	{
		std::cout << "\n*** You entered the wrong code!  Careful agent!  Try again! ***";

		return false;
	}
}

int main()
{
	srand(time(NULL));

	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;

	// loop game until all levels are completed
	while (LevelDifficulty <= MaxDifficulty)
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);

		std::cin.clear();
		std::cin.ignore();

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}

	std::cout << "\n*** Great work agent!  You got all the files!  Now get out of there! ***\n";

	return 0;
}