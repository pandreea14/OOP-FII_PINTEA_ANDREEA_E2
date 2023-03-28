#pragma once

class Circuit
{
	int length, contor;
	Weather weather;
	Car** array;
	double* time;
	bool* done;

public:
	Circuit();
	~Circuit();

	int SetLength(int input_value);
	Weather SetWeather(Weather weather);

	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};