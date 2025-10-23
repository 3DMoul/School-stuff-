#include "Measurement.h"
#include "DataInput.h" 
#include "Visualization.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    std::vector<Measurement> DataEntries = {};
    VisualFunction main;
    DataInput DataInput;
    DataInput.ReadFile(DataEntries);
    bool run = true;
    //menyn loop
    while (run == true)
    {
        //tar bort det som är skrivet innan
        system("CLS");

        //meny
        main.PrintMenu();
        std::string MenuChoice = "Choice 1-6: ";
        //menyval NumberChoice(); funktionen är en fail safe ifal man skiver en bokstav istället för ett nummer
        int Choice = DataInput.NumberChoice(MenuChoice);
        switch (Choice)
        {
        case 1:
        {
            system("CLS");

            std::string TepretureInputs = "How many values do you want to add";
            //här inisierar jag hur många värden jag vill ha
            int NumberOfInputs = DataInput.NumberChoice(TepretureInputs);
            for (int i = 0; i < NumberOfInputs; i++)
            {
                // Vill ta in en termperatur: InputVal
                // Vill ta fram timestamp för NU
                double TempretureInput = 0;
                std::cin >> TempretureInput;//här kan man manuelt skriva vilket värde man vill ha
                // Skapa ny t.ex. Meaurement-instans
                // och lägg till i vector
                //DataEntries.push_back(Measurement(inputVal, timestamp));
                DataInput.TempretureListInput(i, DataEntries, TempretureInput);
            }
        }
        break;
        case 2:
        {
            system("CLS");

            bool Print = true;
            while (Print == true)
            {
                std::cout << "You have [" << size(DataEntries) << "]" << std::endl;
                std::cout << "Do you want to list them [Y/N] : " << std::endl;
                char Des;
                std::cin >> Des;
                //använder toupper så man kan skriva bådde stor eller liten bokstav
                if ((char)toupper(Des) == 'Y')
                {
                    //detta går igenom alla vectorer och skriver ut dem
                    main.PrintMeasurementList(DataEntries);
                    Print = false;
                }

                else if ((char)toupper(Des) == 'N')
                {
                    Print = false;
                }
                else
                {
                    std::cout << "Wrong input" << std::endl;
                }
                break;
            }
        }
        DataInput.ENTER();
        break;
        case 3:
        {
            system("CLS");
            char Des;
            double TempretureLimit = 0;
            std::cout << "Do you want add advanced functions like Limit Values and Moving Avarage: [Y]/[N]" << std::endl;
            std::cin >> Des;

            // detta är för att lägga till ett gränsvärde
            if ((char)toupper(Des) == 'Y')
            {
                std::string TempretureLimitString = "What is the Limit value: ";
                TempretureLimit = DataInput.NumberChoice(TempretureLimitString);
            }
            //if else beroende på om du har en value eller flera values
            if (size(DataEntries) == 1)
            {
                std::cout << "You have " << size(DataEntries) << " value" << std::endl;
                double TempretureSum = DataInput.SummOfVector(DataEntries);
                std::cout << "The only value is " << TempretureSum << " C" << std::endl;
            }

            else if (size(DataEntries) > 1)
            {
                std::cout << "You have " << size(DataEntries) << " values" << std::endl;
                //function för att summrera all data
                double TempretureSum = DataInput.SummOfVector(DataEntries);
                std::cout << "The sum of all the values is " << TempretureSum << " C" << std::endl;

                // medelvärdet är summan av alla delat på hur många values du har
                std::cout << "Avarage of all values " << TempretureSum / size(DataEntries) << " C" << std::endl;

                // här deklarerar jag både string float variablen för min och max värdet
                std::string TimeMin, TimeMax, IdMin, IdMax;
                float MinTempreture, MaxTempreture;

                //här får jag ut värdet för både string och float värdet för minsta tal i listan
                tie(TimeMin, IdMin, MinTempreture) = main.PrintListMin(DataEntries);
                std::cout << "Min: \n" << TimeMin << IdMin << "\n" << MinTempreture << " C" << "\n" << std::endl;

                //-||- för högsta tal i listan
                tie(TimeMax, IdMax, MaxTempreture) = main.PrintListMax(DataEntries);
                std::cout << "Max: \n" << TimeMax << IdMax << "\n" << MaxTempreture << " C" << "\n" << std::endl;

                //detta får jag värdet för variancen
                double Varians = DataInput.Variance(DataEntries);
                std::cout << "The sample varians is " << Varians / (size(DataEntries) - 1) << " C" << std::endl;//både normal
                std::cout << "The population varians is " << Varians / size(DataEntries) << " C" << std::endl;//och population
                if ((char)toupper(Des) == 'Y')//kollar om jag har eneblat denna funktion
                {
                    //deklarering för valuelimit
                    int TimesOver = 0;
                    int TimesUnder = 0;
                    // får båda values både för över samt under
                    tie(TimesOver, TimesUnder) = DataInput.ValueLimit(DataEntries, TempretureLimit);
                    std::cout << "this is how many times you were over the limit value [" << TimesOver << "]" << std::endl;
                    std::cout << "this is how many times you were under the limit value [" << TimesUnder << "]" << std::endl;
                    
                    //moving avarage
                    std::string BBound = "\nBeginBoundry: ";
                    int BeginBoundry = 0;
                    BeginBoundry = DataInput.NumberChoice(BBound);
                    std::string EBound = "\nEndBoundry: ";
                    int EndBoundry = 0;
                    EndBoundry = DataInput.NumberChoice(EBound);
                    //har detta ifall man sätter EndBoundryn innnan BeginBoundryn för då kommer det inte funka
                    double MovingAvarageSum = DataInput.MovingAvarage(EndBoundry, BeginBoundry, DataEntries);
                    std::cout << "Moving avarage is : " << MovingAvarageSum << " C" << std::endl;
                }
            }
            //detta kommer upp om du inte har några values fast försöker printa ut en lista endå
            else
            {
                std::cout << "You currently dont have any data values to look at" << std::endl;
            }
        }
        DataInput.ENTER();
        break;
        case 4:
        {
            //simulering av random mätvärden
            system("CLS");

            std::string TempretureSimulations = "How many values do you want to simulate";
            //här inisierar jag hur många värden jag vill ha
            int TimesSimulated = DataInput.NumberChoice(TempretureSimulations);
            for (int i = 0; i < TimesSimulated; i++)
            {
                //detta tar fram ett random decimaltal mellan 20-30
                double f = (double)rand() / RAND_MAX;
                double RandTempreture = 20 + f * (30 - 20);
                DataInput.TempretureListInput(i, DataEntries, RandTempreture);
            }
        }
        DataInput.ENTER();
        break;
        case 5:
        {
            //här kollas det om du har några värden i listan om du inte har det så kommer den bara gå tillbacka till menyn
            if (size(DataEntries) == 0)
            {
                std::cout << "you have no values" << std::endl;
            }
            else
            {
                main.TempretureVisulisation(DataEntries);
            }
        }
        DataInput.ENTER();
        break;
        case 6: //stänger av loopen
            run = false;
            break;
        default: //om du skriver ett nummer som inte är en av alternativen   
        {
            std::cout << "Wrong input choices are between [1]-[6]" << std::endl;
        }
        break;
        }
    }
    DataInput.ENTER();
    return 0;
}
