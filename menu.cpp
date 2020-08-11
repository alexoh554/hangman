#include <iostream>
#include <fstream>

int menu()
{
	// Store user input in mode choice
	std::string modeChoice;
	std::cout << "Welcome to Hangman. Please select one of the following to begin:\n";
	std::cout << "-Easy\n-Medium\n-Hard\n-Rules\n-Quit\n";

	// Check for correct input
	while (true)
	{
		std::cout << "Enter a difficulty here:";
		std::cin >> modeChoice;
		for (int i = 0; i < modeChoice.length(); i++)
		{
			if (modeChoice[i] >= 'A' && modeChoice[i] <= 'Z')
			{
				modeChoice[i] += 32;
			}
		}
		if (modeChoice == "easy")
		{
			return 1;
		}
		if (modeChoice == "medium")
		{
			return 2;
		}
		if (modeChoice == "hard")
		{
			return 3;
		}
		if (modeChoice == "rules")
		{
			return 4;
		}
		if (modeChoice == "quit")
		{
			return 0;
		}
	}
}

void displayRules()
{
	std::ifstream rules("rules.txt");

	if (rules.is_open())
	{
		std::cout << rules.rdbuf();
	}
}