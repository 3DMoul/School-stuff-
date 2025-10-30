#include <iostream>
#include <vector>
#include "car.h"
#include "parkeringshus.h"
#include "extrafunc.h"
using namespace std;

int main()
{
	int RegNumberLength = 10;
	ExtraFunctions ExFunc;
	ParkingHouse ParkingHouse;
	for (int i = 0; i < 5; i++)
	{
		Car NewCar;
		NewCar.RegNumber = ExFunc.generateRandomString(RegNumberLength);
		
		NewCar.ArrivalTime = ExFunc.TimeStamp();

		NewCar.print();
		ParkingHouse.addCar(NewCar);
	}
	std::string Reg;
	getline(cin, Reg);
	ParkingHouse.removeCar(Reg);
	ParkingHouse.printStatus();

}

