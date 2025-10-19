#include "DataInput.h" 
#include "Visualization.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <ctime>

using namespace std;

int main()
{
    VisialFunction main;

    DataInput DataIn;

    bool run = true;

    //här deklarerar jag tiden
    time_t timestamp;
    time(&timestamp);

    std::list<std::vector<std::string>> DataEntries = {};

    //menyn loop

    while (run == true)
    {

        //tar bort det som är skrivet innan
        system("CLS");

        //meny
        main.PrintMenu();

        std::string MenyChoice = "Choice 1-6: ";
        //menyval NumberChoice(); funktionen är en fail safe ifal man skiver en bokstav istället för ett nummer
        int Choice = main.NumberChoice(MenyChoice);

        switch (Choice)
        {
        case 1:
        {

            system("CLS");

            std::string TimesChoice = "How many values do you want to add";

            int Times = main.NumberChoice(TimesChoice);

            
            for (int i = 0; i < Times; i++)
            {

                double InputVal = 0;
                std::cin >> InputVal;
                DataEntries.push_back(DataIn.DataListInput(i, DataEntries, InputVal));

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
                    main.PrintVectorList(DataEntries);

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

        main.ENTER();

        break;


        case 3:
        {

            system("CLS");
            char Des;
            double LimitValue = 0;

            std::cout << "Do you want add advanced functions like Limit Values and Moving Avarage: [Y]/[N]" << std::endl;
            std::cin >> Des;

            // detta är för att lägga till ett gränsvärde
            if ((char)toupper(Des) == 'Y')
            {

                std::string LimitValueString = "What is the Limit value: ";

                LimitValue = main.NumberChoice(LimitValueString);

            }


            //if else beroende på om du har en value eller flera values
            if (size(DataEntries) == 1)
            {


                std::cout << "You have " << size(DataEntries) << " value" << std::endl;


                double SumVal = DataIn.SummOfList(DataEntries);


                std::cout << "The only value is " << SumVal << std::endl;


            }

            else if (size(DataEntries) > 1)
            {


                std::cout << "You have " << size(DataEntries) << " values" << std::endl;


                //function för att summrera all data
                double SumVal = DataIn.SummOfList(DataEntries);
                std::cout << "The sum of all the values is " << SumVal << std::endl;


                // medelvärdet är summan av alla delat på hur många values du har
                std::cout << "Avarage of all values " << SumVal / size(DataEntries) << std::endl;


                std::string TimeMin, TimeMax, IdMin, IdMax;
                float MinVal, MaxVal;
                tie(TimeMin, IdMin, MinVal) = DataIn.PrintListMin(DataEntries);
                std::cout << "Min: \n" << TimeMin << IdMin << "\n" << MinVal << "\n" << std::endl;

                tie(TimeMax, IdMax, MaxVal) = DataIn.PrintListMax(DataEntries);
                std::cout << "Max: \n" << TimeMax << IdMax << "\n" << MaxVal << "\n" << std::endl;
                
                
                double Varians = DataIn.Variance(DataEntries);
                std::cout << "The sample varians is " << Varians / (size(DataEntries) - 1) << std::endl;
                std::cout << "The population varians is " << Varians / size(DataEntries) << std::endl;


                int TimesOver = 0;
                int TimesUnder = 0;

                if ((char)toupper(Des) == 'Y')
                {

                    tie(TimesOver, TimesUnder) = DataIn.ValueLimit(DataEntries, LimitValue);

                    std::cout << "this is how many times you were over the limit value [" << TimesOver << "]" << std::endl;
                    std::cout << "this is how many times you were under the limit value [" << TimesUnder << "]" << std::endl;


                    //moving avarage
                    std::string BBound = "\nBeginBoundry: ";
                    int BeginBoundry = 0;
                    BeginBoundry = main.NumberChoice(BBound);
                    
                    std::string EBound = "\nEndBoundry: ";
                    int EndBoundry = 0;
                    EndBoundry = main.NumberChoice(EBound);


                    //har detta ifall man sätter EndBoundryn innnan BeginBoundryn för då kommer det inte funka
                    double MovingAvarageSum = DataIn.MovingAvarage(EndBoundry, BeginBoundry , DataEntries);
                    std::cout << "Moving avarage is : " << MovingAvarageSum << std::endl;

                }



            }

            //detta kommer upp om du inte har några values fast försöker printa ut en lista endå
            else
            {

                std::cout << "You currently dont have any data values to look at" << std::endl;

            }

        }

        main.ENTER();

        break;


        case 4:
        {

            system("CLS");

            std::string TimesSimulate = "How many values do you want to simulate";

            int Times = main.NumberChoice(TimesSimulate);

            for (int i = 0; i < Times; i++)
            {

                double f = (double)rand() / RAND_MAX;
                double RandValue = 20 + f * (30 - 20);
                DataEntries.push_back(DataIn.DataListInput(i, DataEntries, RandValue));

            }

        }

        main.ENTER();

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

                main.DataVisulisation(DataEntries);

            }

        }

        main.ENTER();

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

    main.ENTER();
    return 0;

}
