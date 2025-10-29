#pragma once
#ifndef device_h
#define device_h
#include <string>

struct Device
{
	double x;
	double y;
	void move(double dx, double dy);
	void print();
};
#endif
