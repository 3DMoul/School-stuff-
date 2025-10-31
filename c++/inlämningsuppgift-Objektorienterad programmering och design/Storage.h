#pragma once
#include "measurement.h"
#include "Sensor.h"
#include <vector>
using namespace std;
class Storage
{
private:
	vector <TemperetureSensor> TemperatureMeasurments;
	vector <AirqualitySensor> SensorReadings;
public:
	void GetTemperetureSensor(const TemperetureSensor& TempretureStruct);
	void GetAirqualitySensor(const AirqualitySensor& AirqualitySensor);
	void PrintAll() const;
};