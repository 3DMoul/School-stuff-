#pragma once
#include "car.h"
#include <vector>
class ParkingHouse {
private:
	std::vector<Car> Cars;
public:
	void addCar(const Car& Car);
	bool removeCar(const std::string& RegNumber);
	void printStatus() const;
};