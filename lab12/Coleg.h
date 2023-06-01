#pragma once
#include "Contact.h"
#include <string>
using namespace std;

class Coleg : public Contact
{
	string serviciu;
	string adresa;
	string nr_telefon;
public:
	Coleg(const string& Nume, const string& Serviciu, const string& Adresa, const string& nrTelefon)
		: Contact(Nume), serviciu(Serviciu), adresa(Adresa), nr_telefon(nrTelefon) {};
	string GetServiciu();
	string GetNrTelefon();
	string GetAdresa();
	//virtual Tip GetTip() override;
};

