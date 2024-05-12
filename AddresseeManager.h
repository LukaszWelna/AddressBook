#ifndef ADDRESSEEMANAGER_H
#define ADDRESSEEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include "FileWithAddresses.h"

using namespace std;

class AddresseeManager
{
    // ATTRIBUTES
    FileWithAddresses fileWithAddresses;
    const int LOGGED_USER_ID;
    vector <Addressee> addresses;

    // METHODS
    Addressee enterAddresseData(int);
    void showAddresseeData(Addressee);
    bool checkAddresseeRepeated(Addressee);
    void showEditMenu(vector <Addressee>::iterator);

public:
    // CONSTRUCTOR
    AddresseeManager(string fileNameWithAddresses, int loggedUserId, string tempFileNameWithAddresses)
        : fileWithAddresses(fileNameWithAddresses, tempFileNameWithAddresses), LOGGED_USER_ID(loggedUserId)
    {
        addresses = fileWithAddresses.loadAddressesLoggedUserFromFile(LOGGED_USER_ID);
    }

    void addAddressee();
    bool checkIfAddressesVectorEmpty();
    void showLoggedUserAddresses();
    void searchByFirstname();
    void searchByLastname();
    void deleteAddressee();
    void editAddressee();
};

#endif
