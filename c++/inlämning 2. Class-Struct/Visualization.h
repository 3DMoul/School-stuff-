#pragma once

#ifndef Visualization_h
#define Visualization_h
#include <iostream>
#include <string>
#include <list>
#include <thread>
#include <chrono>

using namespace std;



class VisialFunction
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
    void DataVisulisation(const std::list<std::vector<std::string>>& InputList)
    {

        // går genom alla vectorer
        for (const auto& vec : InputList)
        {

            int temp = round(stod(vec[2]));
            for (int i = 0; i < round(temp / 2); i++) // for loopen printar "*" så att man kan se visualiserat hur tempraturen går ne och up
            {


                std::cout << "*";
                //andvänder den här för att den inte bara pruntar ut alla "*" på en gång
                this_thread::sleep_for(chrono::seconds(1));

            }

            std::cout << "   " << vec[2] << endl;
            std::cout << "\n";

        }
    }

    void PrintVectorList(const std::list<std::vector<std::string>>& InputList)
    {

        for (const auto& vec : InputList)
        {


            std::cout << "--------------------" << std::endl;


            std::cout << vec[0] << std::endl;

            std::cout << vec[1] << std::endl;

            std::cout << vec[2] << std::endl;


            std::cout << "--------------------" << std::endl;


        }

    }

};

#endif
