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
    if (userMenager.getLoggedUserId() > 0)
    {
        addresseeMenager.setloggedUserId(userMenager.getLoggedUserId());
        addresseeMenager.loadAddressesLoggedUserFromFile();
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
    addresseeMenager.setloggedUserId(userMenager.getLoggedUserId());
    addresseeMenager.setAddressesVectorEmpty();
}

void AddressBook::addAddressee()
{
    if (userMenager.getLoggedUserId() != 0)
    {
        addresseeMenager.addAddressee();
    }
    else
    {
        cout << "You are not logged in. Login and try again." << endl;
    }

}

void AddressBook::showLoggedUserAddresses()
{
    cout << endl;
    addresseeMenager.showLoggedUserAddresses();
}

void AddressBook::getLastAddresseId()
{
    cout << "Id ostatniego adresata: " << addresseeMenager.getLastAddresseId() << endl;
    system("pause");
}
