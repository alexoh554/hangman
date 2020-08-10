#include <iostream>
#include "menu.h"

// 0 == quit, 1 == easy, 2 == medium, 3 == hard

int main()
{
	int mode = menu();

	// quit application if 0
	if (mode == 0)
	{
		return 0;
	}
}