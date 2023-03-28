#include "BMW.h"
#include <string>

char* BMW::getName()
{
	name = new char[4];
	memcpy(this->name, "BMW", 4);
	return this->name;
}

double BMW::getFuelCapacity() const
{
	return 140;
}

double BMW::getFuelConsumption() const
{
	return 2;
}

double BMW::getAverageSpeed(Weather weather) const
{
	switch (weather) {
	case Weather::Rain:
		return 90;
	case Weather::Sunny:
		return 110;
	case Weather::Snow:
		return 70;
	default:
		return 100;
	}
}
