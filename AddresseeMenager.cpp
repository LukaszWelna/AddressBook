#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "AddresseeMenager.h"

using namespace std;

AddresseeMenager::AddresseeMenager(string fileNameWithAddresses) : fileWithAddresses(fileNameWithAddresses)
{

}

AddresseeMenager::~AddresseeMenager()
{

}

void AddresseeMenager::setloggedUserId(int newLoggedUserId)
{
    loggedUserId = newLoggedUserId;
}

void AddresseeMenager::setAddressesVectorEmpty()
{
    addresses.clear();
}

void AddresseeMenager::addAddressee()
{
    Addressee addressee;

    system("cls");
    cout << " >>> ADDING NEW ADDRESSEE <<<" << endl << endl;
    addressee = enterAddresseData(loggedUserId);

    addresses.push_back(addressee);
    fileWithAddresses.addAddresseeToFile(addressee);

    //++lastAddresseeId;
}

Addressee AddresseeMenager::enterAddresseData(int loggedUserId)
{
    Addressee addressee;

    addressee.setId(++lastAddresseeId);
    addressee.setUserId(loggedUserId);

    cout << "Enter first name: ";
    addressee.setFirstName(AuxiliaryMethods::readLine());
    addressee.setFirstName(changeFirstLetterToUpperAndOtherToLower(addressee.getFirstName()));

    cout << "Enter last name: ";
    addressee.setLastName(AuxiliaryMethods::readLine());
    addressee.setLastName(changeFirstLetterToUpperAndOtherToLower(addressee.getLastName()));

    cout << "Enter phone number: ";
    addressee.setPhoneNumber(AuxiliaryMethods::readLine());

    cout << "Enter email: ";
    addressee.setEmail(AuxiliaryMethods::readLine());

    cout << "Enter address: ";
    addressee.setAddress(AuxiliaryMethods::readLine());

    return addressee;
}

string AddresseeMenager::changeFirstLetterToUpperAndOtherToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

void AddresseeMenager::loadAddressesLoggedUserFromFile()
{
    lastAddresseeId = fileWithAddresses.loadAddressesLoggedUserFromFile(addresses, loggedUserId);
}

bool AddresseeMenager::checkIfAddressesVectorEmpty()
{
    if (addresses.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void AddresseeMenager::showLoggedUserAddresses()
{
    system("cls");
    if (!addresses.empty())
    {
        cout << "             >>> ADDRESSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Addressee> :: iterator it = addresses.begin(); it != addresses.end(); it++)
        {
            showAddresseeData(*it);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Address book is empty." << endl << endl;
    }
    system("pause");
}

void AddresseeMenager::showAddresseeData(Addressee addressee)
{
    cout << endl << "Id:                 " << addressee.getId() << endl;
    cout << "Imie:               " << addressee.getFirstName() << endl;
    cout << "Nazwisko:           " << addressee.getLastName() << endl;
    cout << "Numer telefonu:     " << addressee.getPhoneNumber() << endl;
    cout << "Email:              " << addressee.getEmail() << endl;
    cout << "Adres:              " << addressee.getAddress() << endl;
}

int AddresseeMenager::getLastAddresseId()
{
    return lastAddresseeId;
}
