#include <iostream>
#include "Contact.h"
#include "Prieten.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Agenda.h"
using namespace std;

int main()
{
	Agenda agenda;

	Contact* contact1 = new Prieten("Alexia", "Bul Timisoarei", "1234567890", "16.02.2003");
	Contact* contact4 = new Prieten("Elena", "Bul Groazei",  "1234567230", "26.12.2000");
	Contact* contact2 = new Coleg("Mihai", "Compania X", "Bul Timisoarei", "9087654321");
	Contact* contact3 = new Cunoscut("Liliana", "1029384756");

	agenda.Adauga(contact1);
	agenda.Adauga(contact2);
	agenda.Adauga(contact3);
	agenda.Adauga(contact4);

	vector<Contact*> vectprieteni = agenda.GetPrieteni();
	for (auto it = vectprieteni.begin(); it!=vectprieteni.end(); it++)
	{
		cout << (*it)->GetNume() << " ";
	}

	string numeCautat = "Alexia";
	Contact* contactCautat = agenda.Cauta(numeCautat);
	if (contactCautat == nullptr)
	{
		cout << "Contactul pe nume " << numeCautat << " nu a fost gasit\n";
	}
	else
	{
		cout << "Contactul pe nume " << numeCautat << " a fost gasit\n";
	}

	string numeSters = "Mihai";
	agenda.Sterge(numeSters);
	cout << "Contactul pe nume " << numeSters << " a fost sters\n";



	return 0;
}