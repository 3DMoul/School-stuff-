#pragma once
#include <string>
using namespace std;


struct TemperetureSensor
{
public:
	string SensorName;
	double Tempereture = 0.0;
	string UnitOfMeasurment;
	string TimeStamp;
};