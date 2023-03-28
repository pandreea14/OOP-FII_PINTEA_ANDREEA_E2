#include "Fiat.h"
#include <string>

char* Fiat::getName()
{
	name = new char[5];
	memcpy(this->name, "Fiat", 5);
	return this->name;
}

double Fiat::getFuelCapacity() const
{
	return 50;
}

double Fiat::getFuelConsumption() const
{
	return 30;
}

double Fiat::getAverageSpeed(Weather weather) const
{
	switch (weather) {
	case Weather::Rain:
		return 50;
	case Weather::Sunny:
		return 100;
	case Weather::Snow:
		return 40;
	default:
		return 100;
	}
}