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
		if (checknumb <= 1)// to see if its 1 or les so not prime number
		{
			fail = true;
			run = false;
		}

		for (int i = 2; i < checknumb; i++)
		{
			if (checknumb % i == 0)//to see if the number can cleanly divide with every number under it if it can its not a prime 
			{
				fail = true;
				run = false;
			}
		}
		run = false;//this so its not infinit loop
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
