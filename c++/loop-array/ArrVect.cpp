#include <iostream>
#include <windows.h>
#include <locale>
#include <list>
#include <string>
#include <vector>

int lista()
{
	setlocale(LC_ALL, "sv-SE");
	SetConsoleOutputCP(65001);
	int times = 0;

	int evennumbs = 0;
	int avarage = 0;
	int numbs[] = { 5, 9, 3, 4, 1, 6, 7, 8, 2 };
	int biggestnumb = numbs[0];
	int lowestnumb = numbs[0];


	for (int numb : numbs)
	{
		int temp;
		temp = numb;
		avarage = avarage + numb;
		times++;

		if (temp > biggestnumb)
		{
			biggestnumb = temp;
		}
		else if (temp < lowestnumb)
		{
			lowestnumb = temp;
		}
		else if (numb % 2 == 0)
		{
			evennumbs = evennumbs++;
		}
		

	}
	

	std::cout <<"avarage is " << avarage / times << "\n";
	
	std::cout << "biggest number is " << biggestnumb << "\n";
	
	std::cout << "lowest number is " << lowestnumb << "\n";
	
	std::cout << "the amount of even numbers is " << evennumbs << "\n";
	int rand = 0;
	std::cin >> rand;
	
	return 0;
}