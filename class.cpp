#include <iostream>
#include <string>
#include "class.h"

void Letter::setLetter(char x)
{
	letter = x;
}
void Letter::printLetter()
{
	if (guessed == false)
	{
		std::cout << "_ ";
	}
	else
	{
		std::cout << letter << " ";
	}
}
