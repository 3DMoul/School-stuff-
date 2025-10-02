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
//metod anv�ndes fr�n andra calc
int ValidInDiv();
int ValidIn();

//bool f�r whileloopen

int CalcSwitch()
{
    //detta �r f�r att kunna anv�nda "���"
    setlocale(LC_ALL, "sv-SE");
    SetConsoleOutputCP(65001);
    bool running = true;
    //meny
    while (running)
    {
        int i = 0;
        
        
        system("CLS");
        std::cout << "-----------------------------------\n";
        std::cout << " \n[1] f�r addition (+)";
        std::cout << " \n[2] f�r subtraktion(-)";
        std::cout << " \n[3] f�r multiplikation (*)";
        std::cout << " \n[4] f�r division (/)";
        std::cout << "\n[5] f�r potens (^)";
        std::cout << " \n[6] f�r rest (%)";
        std::cout << "\n[7] f�r att avsluta";
        std::cout << "\n\n-----------------------------------\n";
        std::cout << " \n\nV�lj en operation: ";
        int choice;

        //(!(std::cin >> choice) g�r att om man ger en valid input som "123" s� kommer loopen bli false och den slutar 
        // Och om man ger en invalid input som "abc" s� kommer loopen vara true och den kommer forts�tta
        while (!(std::cin >> choice))
        {
            std::cout << "Fel du m�ste inputa ett nummer:  ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } 

        int number1 = 0, number2 = 0;

        // olika val beroende p� vad man inputar in "choice"
       
        switch (choice)
        {

        
         case 1://addition block
         {

             std::cout << "skriv number 1:\n ";
             number1 = ValidIn();

             std::cout << "skriv number 2:\n ";
             number2 = ValidIn();

             std::cout << "Resultatet av addition �r: " << number1 + number2 << "\n" << std::endl;
             std::cout << "klicka enter f�r att forts�tta\n";
            
             std::string str;
             std::getline(std::cin, str);
         
         }

         break;
        
         case 2://subtration block
         {
             std::cout << "skriv number 1:\n ";
             number1 = ValidIn();

             std::cout << "skriv number 2:\n ";
             number2 = ValidIn();
            
             std::cout << "Resultatet av subtraktion �r: " << number1 - number2 << "\n" << std::endl;
             std::cout << "klicka enter f�r att forts�tta\n";
            
             std::string str;
             std::getline(std::cin, str);
         }
         
         break;

         case 3://multiplikation block
         {
             
             std::cout << "skriv number 1:\n ";
             number1 = ValidIn();

             std::cout << "skriv number 2:\n ";
             number2 = ValidIn();
            
             std::cout << "Resultatet av multiplikation �r: " << number1 * number2 << "\n" << std::endl;
             std::cout << "klicka enter f�r att forts�tta\n";
            
             std::string str;
             std::getline(std::cin, str);
         
         }

         break;

         case 4://divition block
         {
             
             std::cout << "skriv number 1:\n ";
             number1 = ValidIn();

             std::cout << "skriv number 2:\n ";
             number2 = ValidInDiv();
            
            std::cout << "Resultatet av division �r: " << number1 / number2 << "\n" << std::endl;
            std::cout << "klicka enter f�r att forts�tta\n";
            
            std::string str;
            std::getline(std::cin, str);
         
         }

         break;

         case 5://potens block
         {
            
            
             std::cout << "skriv number 1:\n ";
             number1 = ValidIn();

             std::cout << "skriv number 2:\n ";
             number2 = ValidIn();
            
             std::cout << "Resultatet av potens �r: " << pow(number1, number2) << "\n" << std::endl;
             std::cout << "klicka enter f�r att forts�tta\n";
            
             std::string str;
             std::getline(std::cin, str);
         }

         break;

         case 6://rest block
         {
             std::cout << "skriv number 1:\n ";
             number1 = ValidIn();

             std::cout << "skriv number 2:\n ";
             number2 = ValidIn();
            
             std::cout << "\nResultatet av rest �r: " << number1 % number2 << "\n" << std::endl;
             if (number1 % 2 == 0)
             {
                 std::cout << "j�mt\n";
             }
             else
             {
                 std::cout << "udda\n";

             }
             std::cout << "\nklicka enter f�r att forts�tta\n";
            
             std::string str;
             std::getline(std::cin, str);
         }

         break;

         case 7://avslutning av program
         {
            
             std::cout << "\nAvslutar programmet...\n";
             std::cout << "klicka enter f�r att forts�tta";
            
             std::string str;
             std::getline(std::cin, str);
            
             running = false;

         }

         break;

         default://om du skriver ett nummer som inte �r ett av valen
         {
           
             std::cout << "\nOgiltigt val, f�rs�k igen." << std::endl;
             std::cout << "klicka enter f�r att forts�tta\n";
           
             std::string str;
             std::getline(std::cin, str);
         }
            break;
        }
        
        std::string str;//s�h�r fick jag getline att funka
        std::getline(std::cin, str);
    
    }

    return 0;
}