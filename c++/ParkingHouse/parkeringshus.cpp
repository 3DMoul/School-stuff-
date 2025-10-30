#include "parkeringshus.h"
#include "car.h"
#include <iostream>
#include <vector>
#include <string>
void ParkingHouse::addCar(const Car& Car)
{
	Cars.push_back(Car);
}
bool ParkingHouse::removeCar(const std::string& RegNumber)
{
	for (int i = 0; i < size(Cars); i++)
	{	
		if (RegNumber == Cars[i].RegNumber)
		{
			Cars.erase(Cars.begin() + i);
		}
	}
	return true;
}
void ParkingHouse::printStatus() const
{
	for (int i = 0; i < size(Cars); i++)
	{
		std::cout <<"\n" << Cars[i].RegNumber << " " << Cars[i].ArrivalTime << std::endl;
	}
}