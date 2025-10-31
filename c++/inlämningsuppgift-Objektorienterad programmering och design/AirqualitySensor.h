#pragma once
#include <string>
using namespace std;

struct AirqualitySensor
{
	string SensorName;
	int Airquality = 0;
	string UnitOfMeasurment;
	string TimeStamp;
};