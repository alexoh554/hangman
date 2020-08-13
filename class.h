#ifndef CLASS_H
#define CLASS_H
class Letter
{
	public:
		bool guessed{ false };
		char letter{};
		void setLetter(char x);
		void printLetter();
};

#endif