#include <iostream>
#include "menu.h"
#include "play.h"

// Game states:
// 0 == quit, 1 == easy, 2 == medium, 3 == hard

int main()
{
	while (true)
	{
		int mode = menu();

		// quit application if 0, else run game
		if (mode == 0)
		{
			return 0;
		}
		else if (mode == 4)
		{
			displayRules();
		}
		else
		{
			playGame(mode);
			return 0;
		}
	}
}