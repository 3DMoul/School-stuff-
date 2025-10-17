#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cstring>
#include <limits>
#include <ctime>
#include < cstdlib >
#include <thread>
#include <chrono>
#include <stdlib.h>  
#include <tuple>
using namespace std;

class MainFunction
{
public:
    void PrintMenu()
    {
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Datainsamlare och analysverktyg för mätvärden" << std::endl;
        std::cout << "[1] Input more more data" << std::endl;
        std::cout << "[2] Print all data" << std::endl;
        std::cout << "[3] More options for data" << std::endl;
        std::cout << "[4] Simulate Random values" << std::endl;
        std::cout << "[5] Visual representation of data" << std::endl;
        std::cout << "[6] End Program" << std::endl;
        /*std::cout << "[7]" << std::endl;
        std::cout << "[8]" << std::endl;
        std::cout << "[9]" << std::endl;
        std::cout << "[10]" << std::endl;*/
        std::cout << "---------------------------------" << std::endl;
    }

    void ENTER()
    {

        std::cout << "Klick \"ENTER\" too continue" << std::endl;

        std::string str;

        std::getline(std::cin, str);

        std::streamsize InputBufferLimit = 10000;

        std::cin.ignore(InputBufferLimit, '\n');
    }

    static int NumberChoice(std::string StringInput)
    {

        std::cout << StringInput << std::endl;

        int Choice;

        //failsafe loop för val
        while (!(std::cin >> Choice))
        {

            std::cout << "Error you have inputed a invalid value please input a number:  " << std::endl;
            std::cin.clear();
            std::streamsize InputBufferLimit = 10000;
            std::cin.ignore(InputBufferLimit, '\n');
            std::cout << StringInput << std::endl;

        }


        return Choice;
    }

};

struct VectorAttributes
{
    std::string TimeStamp;
    int NumbCreation;
    float DataValue;
};

void DataVisulisation(const std::list<std::vector<std::string>>& InputList)
{

    // går genom alla vectorer
    for (const auto& vec : InputList)
    {

        int temp = round(stod(vec[1]));
        for (int i = 0; i < round(temp / 2); i++) // for loopen printar "*" så att man kan se visualiserat hur tempraturen går ne och up
        {


            std::cout << "*";
            //andvänder den här för att den inte bara pruntar ut alla "*" på en gång
            this_thread::sleep_for(chrono::seconds(1));

        }

        std::cout << "   " << vec[1] << endl;
        std::cout << "\n";

    }
}

void PrintVectorList(const std::list<std::vector<std::string>>& InputList)
{

    for (const auto& vec : InputList)
    {


        std::cout << "--------------------" << std::endl;


        std::cout << vec[0] << std::endl;

        std::cout << vec[2] << std::endl;

        std::cout << vec[1] << std::endl;


        std::cout << "--------------------" << std::endl;


    }
    
}

static std::tuple<std::string, std::string, float>  PrintListMax(const std::list<std::vector<std::string>>& InputList)
{

    //minimum valuen så att koden har en refrence att comparea mot
    double MaxVal = std::numeric_limits<double>::min();

    //detta frå fram max value
    std::string TimeMax;
    std::string IdMax;

    for (const auto& VecVal : InputList)//checkar genom listan alla vectorer
    {

        double Temp = stod(VecVal[1]);

        //gör [1] för att det är på den indexen som data valuen är på

        if (Temp > MaxVal)
        {


            TimeMax = VecVal[0];

            IdMax = VecVal[2];

            MaxVal = Temp;


        }


    }

    return std::make_tuple(TimeMax, IdMax, MaxVal);
    
}

static std::tuple<std::string, std::string, float> PrintListMin(const std::list<std::vector<std::string>>& InputList)
{

    //denna variabel tar fram max value för att comparea cilken som är minst
    double MinVal = std::numeric_limits<double>::max(); 
   
    // detta får fram minsta value
    std::string TimeMin;
    std::string IdMin;

    for (const auto& VecVal : InputList)
    {

        double temp = stod(VecVal[1]);

        if (temp < MinVal)
        {


            TimeMin = VecVal[0];

            IdMin = VecVal[2];

            MinVal = temp;


        }

    }

    return std::make_tuple(TimeMin, IdMin, MinVal);
    
}

static std::tuple<int, int> ValueLimit(const std::list<std::vector<std::string>>& InputList, float LV)
{

    int TimesOver = 0;
    int TimesUnder = 0;


        // denna for loop checkar alla gånger datan är under eller över gränsvärdet man la till
        for (const auto& vec : InputList)
        {
            double temp = stod(vec[1]);

            if (temp < LV)
            {

                TimesUnder++;

            }
            else if (temp > LV)
            {

                TimesOver++;

            }
        }
    

    return std::make_tuple(TimesOver, TimesUnder);

}

static double SummOfList(const std::list<std::vector<std::string>>& InputList)
{
    double SumVal = 0;

    for (const auto& VecVal : InputList)
    {

        double temp = stod(VecVal[1]);

        SumVal = SumVal + temp;

    }

    return SumVal;

}

static double Varia(const std::list<std::vector<std::string>>& InputList)
{


    //vector för att hålla värderna för varians
    std::vector<double> StandardDeviation = {};

    double StandAvg = SummOfList(InputList);

    StandAvg = StandAvg / size(InputList);
    //detta subtraherar alla värderna med medelvärdet
    for (const auto& VecVal : InputList)
    {
        double Temp = stod(VecVal[1]);
        double TempVar = Temp - StandAvg;

        StandardDeviation.push_back(TempVar);

    }

    //detta kvadrerar alla dem subtraherade nummrena
    for (int i = 0; i < size(StandardDeviation); i++)
    {

        double TempVar = pow(StandardDeviation[i], 2);

        StandardDeviation[i] = TempVar;

    }

    // deklarering a kvadrerade tal
    double Squere = 0;

    //loop för att addera ihop all Kvad tal
    for (double i : StandardDeviation)
    {

        Squere = Squere + i;

    }

    return Squere;

}

static double DataListInput(int i, std::list<std::vector<std::string>>& InputList, double InputValue)
{

    //vector för värdet med storlek (3) så jag kan ha tid när den skapades nummer# vilken årdning den skapades och till sist valuen av datan
    std::vector<std::string> Values(3);

    std::cout << "[" << i + 1 << "]" << "Value: ";

    //här är för att lägga till tiden
    time_t TimeStamp;
    time(&TimeStamp);
    Values[0] = ctime(&TimeStamp);


    //detta är för att ge nummeret på vilken värde det är
    std::string convert = std::to_string((size(InputList) + 1));
    std::string dataLabel = convert + "#";
    std::cout << dataLabel << std::endl;
    Values[2] = dataLabel;


    
    std::string TempString = std::to_string(InputValue);
    Values[1] = TempString;

    InputList.push_back(Values);

}

static double MovingAvarage(double EndBoundry, double BeginBoundry, std::list<std::vector<std::string>>& InputList)
{
    
    double MovingAvarageTemporary = 0;
    double MovingAvgSizeTemporary = 0;

    while (EndBoundry < BeginBoundry)
    {
        std::cin.clear();
        std::streamsize InputBufferLimit = 10000;
        std::cin.ignore(InputBufferLimit, '\n');
        std::cout << "EndBoundry has to be after BeginBoundry. " << std::endl;
        std::cout << "Enter another value: ";
        std::cin >> EndBoundry;
    }
    // detta går igenom från där du ville starta till där du villa sluta
    for (const auto& vec : InputList)
    {
        int temp = stod(vec[2]);
        if (temp >= BeginBoundry)
        {

            MovingAvarageTemporary += stod(vec[1]);
            MovingAvgSizeTemporary++;

        }
        else if (temp == EndBoundry)
        {

            break;

        }

    }

    return MovingAvarageTemporary / MovingAvgSizeTemporary;


}


int main()
{
    MainFunction Main;

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
        Main.PrintMenu();

        std::string MenyChoice = "Choice 1-6: ";
        //menyval NumberChoice(); funktionen är en fail safe ifal man skiver en bokstav istället för ett nummer
        int Choice = Main.NumberChoice(MenyChoice);

        switch (Choice)
        {
        case 1:
        {

            system("CLS");

            std::string TimesChoice = "How many values do you want to add";

            int Times = Main.NumberChoice(TimesChoice);

            
            for (int i = 0; i < Times; i++)
            {

                double InputVal = 0;
                std::cin >> InputVal;
                DataListInput(i, DataEntries, InputVal);

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
                    PrintVectorList(DataEntries);

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

        Main.ENTER();

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

                LimitValue = Main.NumberChoice(LimitValueString);

            }


            //if else beroende på om du har en value eller flera values
            if (size(DataEntries) == 1)
            {


                std::cout << "You have " << size(DataEntries) << " value" << std::endl;


                double SumVal = SummOfList(DataEntries);


                std::cout << "The only value is " << SumVal << std::endl;


            }

            else if (size(DataEntries) > 1)
            {


                std::cout << "You have " << size(DataEntries) << " values" << std::endl;


                //function för att summrera all data
                double SumVal = SummOfList(DataEntries);
                std::cout << "The sum of all the values is " << SumVal << std::endl;


                // medelvärdet är summan av alla delat på hur många values du har
                std::cout << "Avarage of all values " << SumVal / size(DataEntries) << std::endl;


                std::string TimeMin, TimeMax, IdMin, IdMax;
                float MinVal, MaxVal;
                tie(TimeMin, IdMin, MinVal) = PrintListMin(DataEntries);
                std::cout << "Min: \n" << TimeMin << IdMin << "\n" << MinVal << "\n" << std::endl;

                tie(TimeMax, IdMax, MaxVal) = PrintListMax(DataEntries);
                std::cout << "Max: \n" << TimeMax << IdMax << "\n" << MaxVal << "\n" << std::endl;
                
                
                double Varians = Varia(DataEntries);
                std::cout << "The sample varians is " << Varians / (size(DataEntries) - 1) << std::endl;
                std::cout << "The population varians is " << Varians / size(DataEntries) << std::endl;


                int TimesOver = 0;
                int TimesUnder = 0;

                if ((char)toupper(Des) == 'Y')
                {

                    tie(TimesOver, TimesUnder) = ValueLimit(DataEntries, LimitValue);

                    std::cout << "this is how many times you were over the limit value [" << TimesOver << "]" << std::endl;
                    std::cout << "this is how many times you were under the limit value [" << TimesUnder << "]" << std::endl;


                    //moving avarage
                    std::string BBound = "\nBeginBoundry: ";
                    int BeginBoundry = 0;
                    BeginBoundry = Main.NumberChoice(BBound);
                    
                    std::string EBound = "\nEndBoundry: ";
                    int EndBoundry = 0;
                    EndBoundry = Main.NumberChoice(EBound);


                    //har detta ifall man sätter EndBoundryn innnan BeginBoundryn för då kommer det inte funka
                    double MovingAvarageSum = MovingAvarage(EndBoundry, BeginBoundry , DataEntries);
                    std::cout << "Moving avarage is : " << MovingAvarageSum << std::endl;

                }



            }

            //detta kommer upp om du inte har några values fast försöker printa ut en lista endå
            else
            {

                std::cout << "You currently dont have any data values to look at" << std::endl;

            }

        }

        Main.ENTER();

        break;


        case 4:
        {

            system("CLS");

            std::string TimesSimulate = "How many values do you want to simulate";

            int Times = Main.NumberChoice(TimesSimulate);

            for (int i = 0; i < Times; i++)
            {

                double f = (double)rand() / RAND_MAX;
                double RandValue = 20 + f * (30 - 20);
                DataListInput(i, DataEntries, RandValue);

            }

        }

        Main.ENTER();

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

                DataVisulisation(DataEntries);

            }

        }

        Main.ENTER();

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

    Main.ENTER();
    return 0;

}
