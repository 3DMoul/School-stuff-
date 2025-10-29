#include "device.h"
#include <iostream>
#include <string>


Device::Device(int id, std::string name)//ger konstruktorn saker den ska göra
	: id(id), name(name) {};
void Device::Rename(std::string newname)//ger function saker den ska göra
{
	name = newname;
}
void Device::Print()//ger function saker den ska göra
{
	std::cout << id << " " << name << std::endl;
}
