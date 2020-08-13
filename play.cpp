#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <sstream>
#include "class.h"

std::string getFileName(int x);
int lineCount(std::string txtName);
std::string getWord(int y, std::string fileName);
void displayHangman(int wrong);
bool guessCheck(std::string guess, std::vector<Letter>& answer);

void playGame(int difficulty)
{
	std::string fileName = getFileName(difficulty);

	// Count number of lines in txt and get random number
	int number_of_lines = lineCount(fileName);
	
	// Get one line from txt file 
	std::string correctWord = getWord(number_of_lines, fileName);
	for (int i = 0; i < correctWord.length(); i++)
	{
		correctWord[i] = toupper(correctWord[i]);
	}

	// Store each letter as a class 
	std::vector<Letter> correctLetter(correctWord.length());
	for (int i = 0; i < correctWord.length(); i++)
	{
		correctLetter[i].setLetter(correctWord[i]);
	}

	// Store number of wrong guesses
	int wrongGuess{ 0 };

	// Play game until user fails
	while (true)
	{
		// Output hangman
		displayHangman(wrongGuess);

		// Output letter or underscore depending on class attribute
		for (int i = 0; i < correctLetter.size(); i++)
		{
			correctLetter[i].printLetter();
		}
		std::cout << "\n\n";

		// Let user guess
		std::cout << "Make a guess:";
		std::string userGuess;
		std::cin >> userGuess;
		for (int i = 0; i < userGuess.length(); i++)
		{
			userGuess[i] = toupper(userGuess[i]);
		}

		// Check if user guesses letter or string
		if (userGuess.length() > 1)
		{
			if (userGuess == correctWord)
			{
				std::cout << "Correct! Game will now end.\n";
				break;
			}
			else
			{
				std::cout << "Incorrect.\n";
				wrongGuess += 1;
			}
		}
		else
		{
			bool correct = guessCheck(userGuess, correctLetter);
			if (correct == false)
			{
				wrongGuess += 1;
			}
		}

		// End game if 6 wrong guesses
		if (wrongGuess == 6)
		{
			std::cout << "GAME OVER!\n";
			displayHangman(6);
			break;
		}
	}
}

std::string getFileName(int x)
{
	std::string nameFile{};
	switch (x)
	{
		case 1:
			nameFile = "static/easy.txt";
			break;
		case 2:
			nameFile = "static/medium.txt";
			break;
		case 3:
			nameFile = "static/hard.txt";
			break;
	}
	return nameFile;
}

int lineCount(std::string txtName)
{
	int count{ 0 };
	std::string line;
	std::ifstream txtFile(txtName);
	while (std::getline(txtFile, line))
	{
		count++;
	}
	return count;
}

std::string getWord(int y, std::string fileName)
{
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, y); 
	int lineNumber = distr(gen);

	std::ifstream myFile(fileName);
	std::string word;
	for (int i = 0; i < lineNumber; i++)
	{
		std::getline(myFile, word);
	}
	return word;
}

void displayHangman(int wrong)
{
	std::stringstream tmp;
	tmp << "static/" << wrong << "wrong.txt";
	std::string hangman = tmp.str();

	std::ifstream f(hangman);

	if (f.is_open())
		std::cout << f.rdbuf();

	std::cout << "\n\n" << "          ";
}

bool guessCheck(std::string guess, std::vector<Letter>& answer)
{
	bool correct{ false };
	int correctAmount{ 0 };
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i].letter == guess[0])
		{
			correct = true;
			answer[i].guessed = true;
			correctAmount += 1;
		}
	}
	if (correct == false)
	{
		std::cout << "Incorrect. There were 0 matches of " << guess[0] << " in the word.\n";
	}
	else
	{
		std::cout << "There were " << correctAmount << " matches of " << guess[0] << " in the word.\n";
	}
	return correct;
}