#include "Agenda.h"
#include "Prieten.h"

Agenda::~Agenda()
{
    for (auto contact : contacte)
    {
        delete contact;
    }
}

Contact* Agenda::Cauta(string nume)
{
    for (auto contact : contacte)
    {
        if (contact->GetNume() == nume)
        {
            return contact;
        }
    }
    return nullptr;
}

vector<Contact*> Agenda::GetPrieteni()
{
    vector<Contact*> CPrieteni;
    for (auto contact : contacte)
    {
        Prieten* prieten = dynamic_cast<Prieten*>(contact);
        if (prieten != nullptr)
        {
            CPrieteni.push_back(prieten);
        }
       /* if (contact->GetTip() == prieten)
        {
            CPrieteni.push_back(contact);
        }*/
    }
    return CPrieteni;
}

void Agenda::Sterge(string nume)
{
    for (auto it = contacte.begin(); it != contacte.end(); it++)
    {
        if ((*it)->GetNume() == nume)
        {
            delete* it; //deallocating the memory 
            contacte.erase(it);     //erases the element form the vector
            break;
        }
    }
}

void Agenda::Adauga(Contact* c)
{
    contacte.push_back(c);
}
