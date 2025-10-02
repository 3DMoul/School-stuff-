#include <iostream>
#include <windows.h>
#include <locale>
#include <list>
#include <string>
#include <vector>


int BuzzFizz()
{
	int stand = 0;
	
	setlocale(LC_ALL, "sv-SE");
	SetConsoleOutputCP(65001);

	
	
	
	for (int i = 0; i < 99; i++)
	{
		    stand++;

			if (stand % 3 == 0)
			{
				std::cout << "Fizz" << std::endl;
			}
			else if (stand % 5 == 0)
			{
				std::cout << "Buzz" << std::endl;;
			}
			else
			{
				std::cout << stand << std::endl;;
			}
	}
	int rand;
	std::cin >> rand;
	return 0;
}