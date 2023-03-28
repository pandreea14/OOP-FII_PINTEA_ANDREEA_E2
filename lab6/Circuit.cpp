#include "Car.h"
#include "Circuit.h"
#include "Weather.h"
#include <stdio.h>
#include <algorithm>

Circuit::Circuit()
{
	this->length = 0;
	this->contor = 0;
	this->array = new Car* [50];
	this->time = new double[100];
	this->done = new bool[10];
	this->weather = Weather::Sunny;
}

Circuit::~Circuit()
{
	if (this->array != nullptr) delete[] this->array;
	if (this->time != nullptr) delete[] this->time;
	if (this->done != nullptr) delete[] this->done;
}

int Circuit::SetLength(int input_value)
{
	this->length = input_value;
	return this->length;
}
Weather Circuit::SetWeather(Weather input)
{
	this->weather = input;
	return this->weather;
}

void Circuit::AddCar(Car* car)
{
	if (this->contor < 50)
	{
		this->array[this->contor++] = car;
	}
	else
	{
		//realocare
	}
}

void Circuit::Race()
{
	for (int index = 0; index < this->contor; index++)
	{
		this->time[index] = this->length / this->array[index]->getAverageSpeed(SetWeather(this->weather));

		if (this->array[index]->getFuelCapacity() / this->array[index]->getFuelConsumption() < this->time[index])
		{
			this->done[index] = 0;//nu termina cursa
		}
		else
		{
			this->done[index] = 1;
		}
	}
}

void sort(double vect[], bool done[], int order[], int index)
{
	for (int i = 0; i < index; i++)
	{
			if (done[i]==1 && vect[i] >= vect[order[index]])
			{
				std::swap(order[i], order[index]);
			}
	}
}

void Circuit::ShowFinalRanks()
{
	int l = 0, order[10];
	for (int index = 0; index < this->contor; index++)
	{
		if (this->done[index] == 1)
		{
			order[l++] = index;//retine a cata masina a terminat
			//printf("The %s finished the race in %f hours.\n", this->array[index]->getName(), this->time[index]);
		}
	}

	for (int index = 1; index < l; index++)
	{
		sort(this->time, this->done, order, index);
	}

	for (int index = 0; index < l; index++)
	{
		printf("The %s finished the race in %f hours.\n", this->array[order[index]]->getName(), this->time[order[index]]);
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int index = 0; index < this->contor; index++)
	{
		if (this->done[index] == 0)
		{
			printf("The %s did not finish the race.\n", this->array[index]->getName());
		}
	}
}
