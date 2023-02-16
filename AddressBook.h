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
    AddresseeMenager addresseeMenager;

    //METHODS
public:
    // CONSTRUCTOR
    AddressBook(string fileNameWithUsers, string fileNameWithAddresses) : userMenager(fileNameWithUsers), addresseeMenager(fileNameWithAddresses)
    {
        userMenager.loadUsersFromFile();
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
};

#endif
