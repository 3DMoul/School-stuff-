#include <iostream>
#include <windows.h>
#include <locale>
#include <string>
int lista();
int BuzzFizz();
int PrimCk();

int main()
{


	bool run = true;
	setlocale(LC_ALL, "sv-SE");
	SetConsoleOutputCP(65001);

	while (run == true)
	{
		

		system("CLS");
		int Choice = 0;
		std::cout << "\n[1] Method lista()\n";
		std::cout << "[2] Method BuzzFizz()\n";
		std::cout << "[3] method PrimeCk\n";
		std::cout << "[4] EndProgram\n";
		while (!(std::cin >> Choice))
		{
			std::cout << "Fel du måste inputa ett nummer:  ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}

		if (Choice == 1)
		{
			lista();

		}
		else if (Choice == 2)
		{
			BuzzFizz();
		}
		else if (Choice == 3)
		{
			PrimCk();
		}
		else if (Choice == 4)
		{
			run = false;
		}


	}



	return 0;
}
