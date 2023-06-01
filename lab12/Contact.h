#pragma once
#include <string>
using namespace std;

enum Tip {
	prieten,
	coleg,
	cunoscut
};

class Contact
{
	string nume;
public:
	Contact(const string& Nume) : nume(Nume) {};
	virtual ~Contact() {};
	string GetNume();
	//virtual Tip GetTip() = 0;
};

