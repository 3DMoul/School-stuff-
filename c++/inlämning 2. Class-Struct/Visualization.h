#pragma once
#ifndef Visualization_h
#define Visualization_h
#include <iostream>
#include <string>
#include <list>
#include <thread>
#include <chrono>
#include "Measurement.h"
using namespace std;


class VisualFunction
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
    void TempretureVisulisation(const std::vector<Measurement>& MeasurmentList)
    {
        // går genom alla vectorer
        for (int i = 0; i < size(MeasurmentList); i++)
        {
            int temp = round(MeasurmentList[i].TepretureInput);
            for (int i = 0; i < round(temp / 2); i++) // for loopen printar "*" så att man kan se visualiserat hur tempraturen går ne och up
            {
                std::cout << "*";
                //andvänder den här för att den inte bara pruntar ut alla "*" på en gång
                this_thread::sleep_for(chrono::seconds(1));
            }
            std::cout << "   " << MeasurmentList[i].TepretureInput << " C" << endl;
            std::cout << "\n";
        }
    }
    void PrintMeasurementList(const std::vector<Measurement>& MeasurmentList)
    {
        for (int i = 0; i < size(MeasurmentList); i++)
        {
            std::cout << "--------------------\n" << std::endl;
            std::cout << MeasurmentList[i].TimeStamp << "\n" << std::endl;
            std::cout << MeasurmentList[i].TempretureNumber << std::endl;
            std::cout << MeasurmentList[i].TepretureInput << " C" << std::endl;
            std::cout << "\n--------------------" << std::endl;
        }
    }static std::tuple<std::string, std::string, double> PrintListMin(const std::vector<Measurement>& MeasurmentList)
    {
        //denna variabel tar fram max value för att comparea cilken som är minst
        double MinVal = std::numeric_limits<double>::max();
        // detta får fram minsta value
        std::string TimeMin;
        std::string IdMin;
        for (int i = 0; i < size(MeasurmentList); i++)
        {
            double temp = MeasurmentList[i].TepretureInput;
            if (temp < MinVal)
            {
                TimeMin = MeasurmentList[i].TimeStamp;
                IdMin = MeasurmentList[i].TempretureNumber;
                MinVal = temp;
            }
        }
        return std::make_tuple(TimeMin, IdMin, MinVal);
    }
    
    static std::tuple<std::string, std::string, double>  PrintListMax(const std::vector<Measurement>& MeasurmentList)
    {
        //minimum valuen så att koden har en refrence att comparea mot
        double MaxVal = std::numeric_limits<double>::min();
        //detta frå fram max value
        std::string TimeMax;
        std::string IdMax;
        for (int i = 0; i < size(MeasurmentList); i++)//checkar genom listan alla vectorer
        {
            double Temp = MeasurmentList[i].TepretureInput;
            //gör [1] för att det är på den indexen som data valuen är på
            if (Temp > MaxVal)
            {
                TimeMax = MeasurmentList[i].TimeStamp;
                IdMax = MeasurmentList[i].TempretureNumber;
                MaxVal = Temp;
            }
        }
        return std::make_tuple(TimeMax, IdMax, MaxVal);
    }
};
#endif
