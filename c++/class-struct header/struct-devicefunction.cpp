
#include <iostream>
#include <string>
#include "device.h"


void Device::move(double dx, double dy)
{
	x += dx;
	y += dy;
}
void Device::print()
{
	std::cout << y << " " << x << std::endl;
}
