#include <iostream>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <locale>
#include <string>
#include <limits>
#include <chrono>
#include <thread> 
#include <stdexcept>

//two method i made so i dident have to repeat my code

int ValidInDiv()
{
	
	int numb = -1;
	
	
	while (!(std::cin >> numb)) 
	{  
		std::cout << "fel input srkiv ett number: \n";
		std::cin.clear(); 
		std::cin.ignore(10000, '\n'); 
	}
	
	while (numb == 0)
	{
		std::cout << "du kan inte dividera med 0";
		std::cin >> numb;
	}

	
	return(numb);
}

//made one for both valid inputs and for dividing by 0
int ValidIn()
{
	
	int numb;

	while (!(std::cin >> numb))
	{
		std::cout << "fel input srkiv ett number: \n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	
	return(numb);
}


int CalcIf()
{
	
	bool run = true;
	
	setlocale(LC_ALL, "sv-SE");
	SetConsoleOutputCP(65001);
		
	while (run)
	{
			system("CLS");

			int numb1;
			int numb2;

			std::cout << " \n[1] f�r addition (+)";
			std::cout << " \n[2] f�r subtraktion(-)";
			std::cout << " \n[3] f�r multiplikation (*)";
			std::cout << " \n[4] f�r division (/)";
			std::cout << "\n[5] f�r potens (^)";
			std::cout << " \n[6] f�r rest (%)";
			std::cout << "\n[7] f�r att avsluta";
			std::cout << " \n\nchoice:\n ";
			
			int choice = 0;

			
			while (!(std::cin >> choice)) 
			{
				
				std::cout << "Fel du m�ste inputa ett nummer:  ";
				std::cin.clear(); 
				std:: cin.ignore(10000, '\n');
			
			}

			if (choice == 1)
			{
				
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
				
				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();
				
				std::cout << "Resultatet av addition �r: " << numb1 + numb2 << "\n" << std::endl;
				std::cout << "klicka enter f�r att forts�tta\n";
				
				std::string str;
				std::getline(std::cin, str);
			
			}
			else if (choice == 2)
			{
				
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
			
				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();
				
				std::cout << "Resultatet av subtraktion �r: " << numb1 - numb2 << "\n" << std::endl;
				std::cout << "klicka enter f�r att forts�tta\n";
				
				std::string str;
				std::getline(std::cin, str);
			
			}
			else if (choice == 3)
			{

				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();

				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();

				std::cout << "Resultatet av multiplikation �r: " << numb1 * numb2 << "\n" << std::endl;
				std::cout << "klicka enter f�r att forts�tta\n";
				
				std::string str;
				std::getline(std::cin, str);

			}
			else if (choice == 4)
			{
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
				
				std::cout << "skriv number 2:\n ";
				numb2 = ValidInDiv();
				
				std::cout << "Resultatet av division �r: " << numb1 / numb2 << "\n" << std::endl;
				std::cout << "klicka enter f�r att forts�tta\n";
				
				std::string str;
				std::getline(std::cin, str);
			}
			else if (choice == 5)
			{
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
				
				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();
				
				std::cout << "Resultatet av potens �r: " << pow(numb1, numb2) << "\n" << std::endl;
				std::cout << "klicka enter f�r att forts�tta\n";
				
				std::string str;
				std::getline(std::cin, str);
			}
			else if (choice == 6)
			{
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
				
				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();
				
				std::cout << "\nResultatet av rest �r: " << numb1 % numb2 << "\n" << std::endl;
				if (numb1 % 2 == 0)
				{
					std::cout << "\nj�mt\n";
				}
				else
				{
					std::cout << "\nudda\n";

				}
				std::cout << "\nklicka enter f�r att forts�tta\n";
				
				std::string str;
				std::getline(std::cin, str);
			}
			else if (choice == 7)
			{

				std::cout << "\nAvslutar programmet...\n";
				std::cout << "klicka enter f�r att forts�tta";
				std::string str;
				std::getline(std::cin, str);

				run = false;
			
            }

			std::string str;
			std::getline(std::cin, str);

	}

		return 0;

}