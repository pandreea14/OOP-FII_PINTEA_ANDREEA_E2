#pragma once
#include "Contact.h"
#include <string>
using namespace std;

class Prieten : public Contact
{
	string data_nasterii;
	string adresa;
	string nr_telefon;
public:
	Prieten(const string& Nume, const string& Adresa, const string& nrTelefon, const string& dataNasterii) 
		: Contact(Nume), adresa(Adresa), nr_telefon(nrTelefon), data_nasterii(dataNasterii) {};
	string GetAdresa();
	string GetDataNasterii();
	string GetNrTelefon();
	//virtual Tip GetTip() override;
};

