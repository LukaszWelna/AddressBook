#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include <vector>
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
    AddressBook(string = "Users.txt", string = "Addresses.txt");
    ~AddressBook();

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
