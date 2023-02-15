#include <iostream>
#include <windows.h>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt", "Addresses.txt");

    addressBook.userSignUp();
    addressBook.userSignUp();

    addressBook.userLogin();
    addressBook.showLoggedUserAddresses();

    addressBook.getLastAddresseId();
    addressBook.addAddressee();
    addressBook.getLastAddresseId();
    addressBook.addAddressee();
    addressBook.getLastAddresseId();
    addressBook.showLoggedUserAddresses();
    addressBook.userLogout();
    addressBook.getLastAddresseId();

    addressBook.addAddressee();

    addressBook.userLogin();
    addressBook.showLoggedUserAddresses();

    addressBook.addAddressee();
    addressBook.addAddressee();
    addressBook.showLoggedUserAddresses();
    addressBook.userLogout();
    system("pause");


    return 0;
    /*
    if (addressBook.getLoggedUserId() != 0)
    {
        addressBook.changeLoggedUserPassword();
    }


    */
}

