#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <vector>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "UserMenager.h"
#include "AddresseeMenager.h"

using namespace std;

class AddressBook
{
    // ATTRIBUTES
    UserMenager userMenager;
    AddresseeMenager *addresseeMenager;
    const string FILE_NAME_WITH_ADDRESSES;
    const string TEMP_FILE_NAME_WITH_ADDRESSES;

    //METHODS
public:
    // CONSTRUCTOR
    AddressBook(string fileNameWithUsers, string fileNameWithAddresses, string tempFileNameWithAddresses)
        : userMenager(fileNameWithUsers), FILE_NAME_WITH_ADDRESSES(fileNameWithAddresses), TEMP_FILE_NAME_WITH_ADDRESSES(tempFileNameWithAddresses)
    {
        addresseeMenager = NULL;
    }

    // DESTRUCTOR
    ~AddressBook()
    {
        delete addresseeMenager;
        addresseeMenager = NULL;
    }

    void userSignUp();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
    void showAllUsers();
    int getLoggedUserId();
    void addAddressee();
    void showLoggedUserAddresses();
    void getLastAddresseId();
    bool userLogged();
    void searchByFirstname();
    void searchByLastname();
    void deleteAddressee();
    void editAddressee();
};

#endif
