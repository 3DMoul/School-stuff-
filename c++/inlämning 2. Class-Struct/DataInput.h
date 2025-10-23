#pragma once
#ifndef DataInput_h
#define DataInput_h
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits>
#include <ctime>
#include <thread>
#include <chrono>
#include <tuple>
#include <fstream>
using namespace std;
class DataInput
{
public:
    void ReadFile(std::list<std::vector<std::string>>& InputList)
    {
        ifstream TempretureFile;
        //går igenom värdena som var innan och skickar in dem i listan
        TempretureFile.open("DataVals.txt", ios::in);
        if (TempretureFile.is_open())
        {
            int times = 0;
            std::vector<std::string> Values(3);
            string line;
            //här går den igenom alla lines av txt filen samt lägger dem in i vector som sätts in i listan
            while (getline(TempretureFile, line))
            {
                if (times < 3)
                {
                    Values[times] = line;
                    times++;
                }
                if (times == 3)
                {
                    times = 0;
                    InputList.push_back(Values);
                }
            }
        }
        TempretureFile.close();
    }
    static std::vector<std::string> TempretureListInput(int i, std::list<std::vector<std::string>>& InputList, double InputValue)
    {
        ofstream TempretureData;
        //vector för värdet med storlek (3) så jag kan ha tid när den skapades nummer# vilken årdning den skapades och till sist valuen av datan
        std::vector<std::string> Values(3);
        std::cout << "[" << i + 1 << "]" << "Value: ";
        //här är för att lägga till tiden
        time_t TimeStamp;
        time(&TimeStamp);
        char *temp;
        temp = asctime(localtime(&TimeStamp));
        temp[strlen(temp) - 1] = '\0';// detta gör att man inte får den newline av time_t
        Values[0] = temp;

        //detta är för att ge nummeret på vilken värde det är
        std::string convert = std::to_string((size(InputList) + 1));
        std::string dataLabel = convert + "#";
        std::cout << dataLabel << std::endl;
        Values[1] = dataLabel;

        std::string TempString = std::to_string(InputValue);
        Values[2] = TempString;
        //här öppnar jag upp en ny txt.fil som jag lägger in värden i
        TempretureData.open("DataVals.txt", ios::app);
        if (TempretureData.is_open())
        {
            //här läggs det in i txt.filen
            TempretureData << Values[0] << endl;
            TempretureData << Values[1] << endl;
            TempretureData << Values[2] << endl;
            TempretureData.close();
        }
        return Values;
    }
    static std::tuple<std::string, std::string, double>  PrintListMax(const std::list<std::vector<std::string>>& InputList)
    {
        //minimum valuen så att koden har en refrence att comparea mot
        double MaxVal = std::numeric_limits<double>::min();
        //detta frå fram max value
        std::string TimeMax;
        std::string IdMax;
        for (const auto& VecVal : InputList)//checkar genom listan alla vectorer
        {
            double Temp = stod(VecVal[2]);
            //gör [1] för att det är på den indexen som data valuen är på
            if (Temp > MaxVal)
            {
                TimeMax = VecVal[0];
                IdMax = VecVal[1];
                MaxVal = Temp;
            }
        }
        return std::make_tuple(TimeMax, IdMax, MaxVal);
    }
    static std::tuple<std::string, std::string, double> PrintListMin(const std::list<std::vector<std::string>>& InputList)
    {
        //denna variabel tar fram max value för att comparea cilken som är minst
        double MinVal = std::numeric_limits<double>::max();
        // detta får fram minsta value
        std::string TimeMin;
        std::string IdMin;
        for (const auto& VecVal : InputList)
        {
            double temp = stod(VecVal[2]);
            if (temp < MinVal)
            {
                TimeMin = VecVal[0];
                IdMin = VecVal[1];
                MinVal = temp;
            }
        }
        return std::make_tuple(TimeMin, IdMin, MinVal);
    }
    static std::tuple<int, int> ValueLimit(const std::list<std::vector<std::string>>& InputList, double LV)
    {
        int TimesOver = 0;
        int TimesUnder = 0;
        // denna for loop checkar alla gånger datan är under eller över gränsvärdet man la till
        for (const auto& vec : InputList)
        {
            double temp = stod(vec[2]);
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
            double temp = stod(VecVal[2]);
            SumVal = SumVal + temp;
        }
        return SumVal;
    }
    static double Variance(const std::list<std::vector<std::string>>& InputList)
    {
        //vector för att hålla värderna för varians
        std::vector<double> StandardDeviation = {};
        double StandAvg = SummOfList(InputList);
        StandAvg = StandAvg / size(InputList);
        //detta subtraherar alla värderna med medelvärdet
        for (const auto& VecVal : InputList)
        {
            double Temp = stod(VecVal[2]);
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
            int temp = stod(vec[1]);
            if (temp >= BeginBoundry)
            {
                MovingAvarageTemporary += stod(vec[2]);
                MovingAvgSizeTemporary++;
            }
            else if (temp == EndBoundry)
            {
                break;
            }
        }
        return MovingAvarageTemporary / MovingAvgSizeTemporary;
    }
};
#endif
