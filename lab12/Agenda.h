#pragma once
#include "Contact.h"
#include <vector>
using namespace std;

class Agenda
{
	vector<Contact*> contacte;
public:
	~Agenda();
	Contact* Cauta(string nume);
	vector<Contact*> GetPrieteni();
	void Sterge(string nume);
	void Adauga(Contact* c);
};

