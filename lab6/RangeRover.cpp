#include "RangeRover.h"
#include <string>

char* RangeRover::getName()
{
	name = new char[11];
	memcpy(this->name, "RangeRover", 11);
	return this->name;
}

double RangeRover::getFuelCapacity() const
{
	return 100;
}

double RangeRover::getFuelConsumption() const
{
	return 5;
}

double RangeRover::getAverageSpeed(Weather weather) const
{
	switch (weather) {
	case Weather::Rain:
		return 120;
	case Weather::Sunny:
		return 120;
	case Weather::Snow:
		return 60;
	default:
		return 110;
	}
}
