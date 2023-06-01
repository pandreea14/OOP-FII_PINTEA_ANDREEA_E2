#pragma once
#include "Contact.h"
#include <string>
using namespace std;

class Cunoscut : public Contact
{
	string nr_telefon;
public:
	Cunoscut(const string& Nume, const string& nrTelefon) : Contact(Nume), nr_telefon(nrTelefon) {};
	string GetNrTelefon();
	//virtual Tip GetTip() override;
};

