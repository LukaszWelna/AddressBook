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
    FileWithAddresses fileWithAddresses;
    const int LOGGED_USER_ID;
    vector <Addressee> addresses;

    // METHODS
    Addressee enterAddresseData(int);
    void showAddresseeData(Addressee);
    bool checkAddresseeRepeated(Addressee);

public:
    // CONSTRUCTOR
    AddresseeMenager(string fileNameWithAddresses, int loggedUserId) : fileWithAddresses(fileNameWithAddresses), LOGGED_USER_ID(loggedUserId)
    {
        addresses = fileWithAddresses.loadAddressesLoggedUserFromFile(LOGGED_USER_ID);
    }

    int getLastAddresseId();
    void addAddressee();
    bool checkIfAddressesVectorEmpty();
    void showLoggedUserAddresses();

};

#endif
