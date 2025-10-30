#include "car.h"
#include <iostream>
#include <string>
void Car::print() const
{
	std::cout << "\nReg sheet = " << RegNumber << " arrived at = " << ArrivalTime << std::endl;
}