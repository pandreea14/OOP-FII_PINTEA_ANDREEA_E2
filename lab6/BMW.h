#pragma once
#include "Car.h"

class BMW : public Car
{
	char* name;
public:
	char* getName() override;
	double getFuelCapacity() const override;
	double getFuelConsumption() const override;
	double getAverageSpeed(Weather weather) const override;
};

