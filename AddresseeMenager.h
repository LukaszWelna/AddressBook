#ifndef ADDRESSEEMENAGER_H
#define ADDRESSEEMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include "FileWithAddresses.h"

using namespace std;

class AddresseeMenager
{
    // ATTRIBUTES
    int loggedUserId;
    vector <Addressee> addresses;
    FileWithAddresses fileWithAddresses;

    // METHODS
    Addressee enterAddresseData(int);
    string changeFirstLetterToUpperAndOtherToLower(string);
    void showAddresseeData(Addressee);
    bool checkAddresseeRepeated(Addressee);

public:
    // CONSTRUCTOR
    AddresseeMenager(string fileNameWithAddresses) : fileWithAddresses(fileNameWithAddresses)
    {

    }

    // SETTERS
    void setloggedUserId(int);
    void setAddressesVectorEmpty();

    int getLastAddresseId();
    void addAddressee();
    void loadAddressesLoggedUserFromFile();
    bool checkIfAddressesVectorEmpty();
    void showLoggedUserAddresses();

};

#endif
