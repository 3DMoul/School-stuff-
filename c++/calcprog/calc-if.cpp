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

			std::cout << " \n[1] för addition (+)";
			std::cout << " \n[2] för subtraktion(-)";
			std::cout << " \n[3] för multiplikation (*)";
			std::cout << " \n[4] för division (/)";
			std::cout << "\n[5] för potens (^)";
			std::cout << " \n[6] för rest (%)";
			std::cout << "\n[7] för att avsluta";
			std::cout << " \n\nchoice:\n ";
			
			int choice = 0;

			
			while (!(std::cin >> choice)) 
			{
				
				std::cout << "Fel du måste inputa ett nummer:  ";
				std::cin.clear(); 
				std:: cin.ignore(10000, '\n');
			
			}

			if (choice == 1)
			{
				
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
				
				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();
				
				std::cout << "Resultatet av addition är: " << numb1 + numb2 << "\n" << std::endl;
				std::cout << "klicka enter för att fortsätta\n";
				
				std::string str;
				std::getline(std::cin, str);
			
			}
			else if (choice == 2)
			{
				
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
			
				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();
				
				std::cout << "Resultatet av subtraktion är: " << numb1 - numb2 << "\n" << std::endl;
				std::cout << "klicka enter för att fortsätta\n";
				
				std::string str;
				std::getline(std::cin, str);
			
			}
			else if (choice == 3)
			{

				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();

				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();

				std::cout << "Resultatet av multiplikation är: " << numb1 * numb2 << "\n" << std::endl;
				std::cout << "klicka enter för att fortsätta\n";
				
				std::string str;
				std::getline(std::cin, str);

			}
			else if (choice == 4)
			{
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
				
				std::cout << "skriv number 2:\n ";
				numb2 = ValidInDiv();
				
				std::cout << "Resultatet av division är: " << numb1 / numb2 << "\n" << std::endl;
				std::cout << "klicka enter för att fortsätta\n";
				
				std::string str;
				std::getline(std::cin, str);
			}
			else if (choice == 5)
			{
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
				
				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();
				
				std::cout << "Resultatet av potens är: " << pow(numb1, numb2) << "\n" << std::endl;
				std::cout << "klicka enter för att fortsätta\n";
				
				std::string str;
				std::getline(std::cin, str);
			}
			else if (choice == 6)
			{
				std::cout << "skriv number 1:\n ";
				numb1 = ValidIn();
				
				std::cout << "skriv number 2:\n ";
				numb2 = ValidIn();
				
				std::cout << "\nResultatet av rest är: " << numb1 % numb2 << "\n" << std::endl;
				if (numb1 % 2 == 0)
				{
					std::cout << "\njämt\n";
				}
				else
				{
					std::cout << "\nudda\n";

				}
				std::cout << "\nklicka enter för att fortsätta\n";
				
				std::string str;
				std::getline(std::cin, str);
			}
			else if (choice == 7)
			{

				std::cout << "\nAvslutar programmet...\n";
				std::cout << "klicka enter för att fortsätta";
				std::string str;
				std::getline(std::cin, str);

				run = false;
			
            }

			std::string str;
			std::getline(std::cin, str);

	}

		return 0;

}
