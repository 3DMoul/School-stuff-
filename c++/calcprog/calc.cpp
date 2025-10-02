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
//metod användes från andra calc
int ValidInDiv();
int ValidIn();

//bool för whileloopen

int CalcSwitch()
{
    //detta är för att kunna använda "åäö"
    setlocale(LC_ALL, "sv-SE");
    SetConsoleOutputCP(65001);
    bool running = true;
    //meny
    while (running)
    {
        int i = 0;
        
        
        system("CLS");
        std::cout << "-----------------------------------\n";
        std::cout << " \n[1] för addition (+)";
        std::cout << " \n[2] för subtraktion(-)";
        std::cout << " \n[3] för multiplikation (*)";
        std::cout << " \n[4] för division (/)";
        std::cout << "\n[5] för potens (^)";
        std::cout << " \n[6] för rest (%)";
        std::cout << "\n[7] för att avsluta";
        std::cout << "\n\n-----------------------------------\n";
        std::cout << " \n\nVälj en operation: ";
        int choice;

        //(!(std::cin >> choice) gör att om man ger en valid input som "123" så kommer loopen bli false och den slutar 
        // Och om man ger en invalid input som "abc" så kommer loopen vara true och den kommer fortsätta
        while (!(std::cin >> choice))
        {
            std::cout << "Fel du måste inputa ett nummer:  ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } 

        int number1 = 0, number2 = 0;

        // olika val beroende på vad man inputar in "choice"
       
        switch (choice)
        {

        
         case 1://addition block
         {

             std::cout << "skriv number 1:\n ";
             number1 = ValidIn();

             std::cout << "skriv number 2:\n ";
             number2 = ValidIn();

             std::cout << "Resultatet av addition är: " << number1 + number2 << "\n" << std::endl;
             std::cout << "klicka enter för att fortsätta\n";
            
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
            
             std::cout << "Resultatet av subtraktion är: " << number1 - number2 << "\n" << std::endl;
             std::cout << "klicka enter för att fortsätta\n";
            
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
            
             std::cout << "Resultatet av multiplikation är: " << number1 * number2 << "\n" << std::endl;
             std::cout << "klicka enter för att fortsätta\n";
            
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
            
            std::cout << "Resultatet av division är: " << number1 / number2 << "\n" << std::endl;
            std::cout << "klicka enter för att fortsätta\n";
            
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
            
             std::cout << "Resultatet av potens är: " << pow(number1, number2) << "\n" << std::endl;
             std::cout << "klicka enter för att fortsätta\n";
            
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
            
             std::cout << "\nResultatet av rest är: " << number1 % number2 << "\n" << std::endl;
             if (number1 % 2 == 0)
             {
                 std::cout << "jämt\n";
             }
             else
             {
                 std::cout << "udda\n";

             }
             std::cout << "\nklicka enter för att fortsätta\n";
            
             std::string str;
             std::getline(std::cin, str);
         }

         break;

         case 7://avslutning av program
         {
            
             std::cout << "\nAvslutar programmet...\n";
             std::cout << "klicka enter för att fortsätta";
            
             std::string str;
             std::getline(std::cin, str);
            
             running = false;

         }

         break;

         default://om du skriver ett nummer som inte är ett av valen
         {
           
             std::cout << "\nOgiltigt val, försök igen." << std::endl;
             std::cout << "klicka enter för att fortsätta\n";
           
             std::string str;
             std::getline(std::cin, str);
         }
            break;
        }
        
        std::string str;//såhär fick jag getline att funka
        std::getline(std::cin, str);
    
    }

    return 0;
}
