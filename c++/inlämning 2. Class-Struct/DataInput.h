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
#include "Measurement.h"
using namespace std;

class DataInput
{
public:
    void WriteFile(std::string TimeStamp, std::string TemperatureNumber, double Temperature)
    {
        ofstream TempretureData;
        //här öppnar jag upp en ny txt.fil som jag lägger in värden i
        TempretureData.open("DataVals.txt", ios::app);
        if (TempretureData.is_open())
        {
            //här läggs det in i txt.filen
            TempretureData << TimeStamp << ",";
            TempretureData << TemperatureNumber << ",";
            TempretureData << Temperature << endl;
            TempretureData.close();
        }
    }
    void ReadFile(std::vector<Measurement>& MeasurmentList)
    {
        ifstream TempretureFile;
        //går igenom värdena som var innan och skickar in dem i listan
        TempretureFile.open("DataVals.txt", ios::in);
        if (TempretureFile.is_open())
        {
            int times = 0;
            std::vector<Measurement> Values(3);
            string line;
            //här går den igenom alla lines av txt filen samt lägger dem in i vector som sätts in i listan
            while (getline(TempretureFile, line))
            {
                char str[256];
                strcpy_s(str, line.c_str());
                const char* del = ",";
                Measurement new_measurement;
                char* next_token = nullptr;
                char* FileSegment = strtok_s(str, del, &next_token);
                int FileIteration = 0;
                while (FileSegment != nullptr)
                {
                    if (FileIteration == 0)
                    {
                        new_measurement.TimeStamp = FileSegment;
                    }
                    else if (FileIteration == 1)
                    {
                        new_measurement.TempretureNumber = FileSegment;
                    }
                    else if (FileIteration == 2)
                    {
                        new_measurement.TepretureInput = stod(FileSegment);
                    }

                    FileSegment = strtok_s(nullptr, del, &next_token);
                    FileIteration++;
                }

                
                MeasurmentList.push_back(new_measurement);
            }
        }
        TempretureFile.close();
    }
    void TempretureListInput(int i, std::vector<Measurement>& MeasurmentList, double InputTempreture)
    {
        

        std::cout << "[" << i + 1 << "]" << "Value: ";
        //här är för att lägga till tiden
        time_t TimeStamp;
        time(&TimeStamp);
        struct tm timeInfo;
        localtime_s(&timeInfo, &TimeStamp);
        char temp[26];
        asctime_s(temp, sizeof(temp), &timeInfo);
        temp[strlen(temp) - 1] = '\0'; // tar bort newline

        //new_measurement.TimeStamp = temp;
        //detta är för att ge nummeret på vilken värde det är
        std::string convert = std::to_string((size(MeasurmentList) + 1));
        std::string dataLabel = convert + "#";
        std::cout << dataLabel << std::endl;

        Measurement new_measurement{ dataLabel, temp, InputTempreture };
        //här öppnar jag upp en ny txt.fil som jag lägger in värden i
        WriteFile(new_measurement.TimeStamp, new_measurement.TempretureNumber, new_measurement.TepretureInput);
        MeasurmentList.push_back(new_measurement);
    }
    static std::tuple<int, int> ValueLimit(const std::vector<Measurement>& MeasurmentList, double LV)
    {
        int TimesOver = 0;
        int TimesUnder = 0;
        // denna for loop checkar alla gånger datan är under eller över gränsvärdet man la till
        for (int i = 0; i < size(MeasurmentList); i++)
        {
            double temp = MeasurmentList[i].TepretureInput;
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
    static double SummOfVector(const std::vector<Measurement>& MeasurmentList)
    {
        double SumVal = 0;
        for (int i = 0; i < size(MeasurmentList); i++)
        {
            SumVal = SumVal + MeasurmentList[i].TepretureInput;
        }
        return SumVal;
    }
    static double Variance(const std::vector<Measurement>& MeasurmentList)
    {
        //vector för att hålla värderna för varians
        std::vector<double> StandardDeviation = {};
        double StandAvg = SummOfVector(MeasurmentList);
        StandAvg = StandAvg / size(MeasurmentList);
        //detta subtraherar alla värderna med medelvärdet
        for (int i = 0; i < size(MeasurmentList); i++)
        {
            double Temp = MeasurmentList[i].TepretureInput;
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
    static double MovingAvarage(double EndBoundry, double BeginBoundry, std::vector<Measurement>& MeasurmentList)
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
        for (int i = 0; i < size(MeasurmentList); i++)
        {
            int temp = MeasurmentList[i].TempretureNumber[0];
            if (temp >= BeginBoundry)
            {
                MovingAvarageTemporary += MeasurmentList[i].TepretureInput;
                MovingAvgSizeTemporary++;
            }
            else if (temp == EndBoundry)
            {
                break;
            }
        }
        return MovingAvarageTemporary / MovingAvgSizeTemporary;
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
#endif
