#include "Seat.h"
#include <string>

char* Seat::getName()
{
	name = new char[5];
	memcpy(this->name, "Seat", 5);
	return this->name;
}

double Seat::getFuelCapacity() const
{
	return 100;
}

double Seat::getFuelConsumption() const
{
	return 5;
}

double Seat::getAverageSpeed(Weather weather) const
{
	switch (weather) {
	case Weather::Rain:
		return 100;
	case Weather::Sunny:
		return 120;
	case Weather::Snow:
		return 60;
	default:
		return 100;
	}
}
