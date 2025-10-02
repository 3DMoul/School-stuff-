#include <iostream>
#include <windows.h>
#include <locale>
#include <list>
#include <string>
#include <vector>


int PrimCk()
{
	bool fail = false;
	int checknumb;
	bool run = true;
	while (run)
	{
		
		std::cout << "skriv numb";
		std::cin >> checknumb;
		if (checknumb <= 1)
		{
			fail = true;
			run = false;
		}

		for (int i = 2; i < checknumb; i++)
		{
			if (checknumb % i == 0)
			{
				fail = true;
				run = false;
			}
		}
		run = false;
	}
	if (fail == true)
	{
		std::cout << "not prime";
	}
	else
	{
		std::cout << "prime";
	}

	int rand;
	std::cin >> rand;


		return 0;
}