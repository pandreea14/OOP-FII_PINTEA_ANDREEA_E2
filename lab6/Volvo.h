#pragma once
#include "Car.h"

class Volvo : public Car
{
	char* name;

public:
	char* getName() override;
	double getFuelCapacity() const override;
	double getFuelConsumption() const override;
	double getAverageSpeed(Weather weather) const override;
};