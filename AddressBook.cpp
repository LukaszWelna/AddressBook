#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "AddressBook.h"

using namespace std;

AddressBook::AddressBook(string fileNameWithUsers, string fileNameWithAddresses) : userMenager(fileNameWithUsers), addresseeMenager(fileNameWithAddresses)
{
    userMenager.loadUsersFromFile();
}
AddressBook::~AddressBook()
{

}

void AddressBook::userSignUp()
{
    userMenager.userSignUp();
}

void AddressBook::showAllUsers()
{
    userMenager.showAllUsers();
}

void AddressBook::userLogin()
{
    userMenager.userLogin();
    if ((userMenager.getLoggedUserId() > 0) && (addresseeMenager.checkIfAddressesVectorEmpty()))
    {
        addresseeMenager.loadAddressesLoggedUserFromFile(userMenager.getLoggedUserId());
    }
}

int AddressBook::getLoggedUserId()
{
    return userMenager.getLoggedUserId();
}

void AddressBook::changeLoggedUserPassword()
{
    userMenager.changeLoggedUserPassword();
}

void AddressBook::userLogout()
{
    userMenager.userLogout();
}

void AddressBook::addAddressee()
{
    addresseeMenager.addAddressee(userMenager.getLoggedUserId());
}

void AddressBook::showLoggedUserAddresses()
{
    cout << endl;
    addresseeMenager.showLoggedUserAddresses();
}


