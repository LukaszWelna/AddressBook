#ifndef ADDRESSEEMENAGER_H
#define ADDRESSEEMENAGER_H

#include <iostream>
#include <vector>
#include "FileWithAddresses.h"

using namespace std;

class AddresseeMenager
{
    int lastAddresseeId;
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

    void addAddressee(int);
    void loadAddressesLoggedUserFromFile(int);
    bool checkIfAddressesVectorEmpty();
    void showLoggedUserAddresses();
};

#endif
