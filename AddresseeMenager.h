#ifndef ADDRESSEEMENAGER_H
#define ADDRESSEEMENAGER_H

#include <iostream>
#include <vector>
#include "FileWithAddresses.h"

using namespace std;

class AddresseeMenager
{
    int lastAddresseeId;
    int loggedUserId;
    vector <Addressee> addresses;
    FileWithAddresses fileWithAddresses;

    Addressee enterAddresseData(int);
    string changeFirstLetterToUpperAndOtherToLower(string);
    void showAddresseeData(Addressee);

public:
    // CONSTRUCTOR
    AddresseeMenager(string);
    // DESCRUCTOR
    ~AddresseeMenager();

    // SETTERS
    void setloggedUserId(int);
    void setAddressesVectorEmpty();

    void addAddressee();
    void loadAddressesLoggedUserFromFile();
    bool checkIfAddressesVectorEmpty();
    void showLoggedUserAddresses();
    int getLastAddresseId();
};

#endif
