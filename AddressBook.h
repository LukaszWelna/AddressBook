#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <vector>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "UserManager.h"
#include "AddresseeManager.h"

using namespace std;

class AddressBook
{
    // ATTRIBUTES
    UserManager userManager;
    AddresseeManager *addresseeManager;
    const string FILE_NAME_WITH_ADDRESSES;
    const string TEMP_FILE_NAME_WITH_ADDRESSES;

    //METHODS
public:
    // CONSTRUCTOR
    AddressBook(string fileNameWithUsers, string fileNameWithAddresses, string tempFileNameWithAddresses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_ADDRESSES(fileNameWithAddresses), TEMP_FILE_NAME_WITH_ADDRESSES(tempFileNameWithAddresses)
    {
        addresseeManager = NULL;
    }

    // DESTRUCTOR
    ~AddressBook()
    {
        delete addresseeManager;
        addresseeManager = NULL;
    }

    void userSignUp();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
    int getLoggedUserId();
    void addAddressee();
    void showLoggedUserAddresses();
    bool userLogged();
    void searchByFirstname();
    void searchByLastname();
    void deleteAddressee();
    void editAddressee();
};

#endif
