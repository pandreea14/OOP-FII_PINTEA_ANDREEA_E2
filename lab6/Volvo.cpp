#include "Volvo.h"
#include <string>

char* Volvo::getName()
{
	name = new char[6];
	memcpy(this->name, "Volvo", 6);
	return this->name;
}

double Volvo::getFuelCapacity() const
{
	return 120;
}

double Volvo::getFuelConsumption() const
{
	return 6;
}

double Volvo::getAverageSpeed(Weather weather) const
{
	switch (weather) {
		case Weather::Rain:
			return 100;
		case Weather::Sunny:
			return 130;
		case Weather::Snow:
			return 70;
		default:
			return 90;
	}
}