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

void playGame(int difficulty)
{
	std::string fileName = getFileName(difficulty);
	// Count number of lines in txt and get random number
	int number_of_lines = lineCount(fileName);
	
	// Get one line from txt file 
	std::string correctWord = getWord(number_of_lines, fileName);

	// Store each letter as a class 
	std::vector<Letter> correctLetter(correctWord.length());
	for (int i = 0; i < correctWord.length(); i++)
	{
		correctLetter[i].setLetter(correctWord[i]);
	}

	// Store number of wrong guesses
	int wrongGuess{ 0 };

	// Play game until user fails
	while (wrongGuess != 6)
	{
		// Output hangman
		displayHangman(wrongGuess);

		// Output letter or underscore depending on class attribute


		// Let user guess

		// If matches, change attributes

		// Else, output new hangman
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
}