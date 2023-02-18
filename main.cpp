#include <iostream>
#include <windows.h>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt", "Addresses.txt");

    addressBook.userSignUp();
    //addressBook.userSignUp();

    addressBook.userLogin();
    addressBook.showLoggedUserAddresses();

    addressBook.addAddressee();
    addressBook.addAddressee();
    addressBook.showLoggedUserAddresses();
    addressBook.changeLoggedUserPassword();

    addressBook.userLogout();
    addressBook.addAddressee();

    addressBook.userLogin();

    addressBook.showLoggedUserAddresses();

    addressBook.addAddressee();
    addressBook.addAddressee();
    addressBook.showLoggedUserAddresses();
    addressBook.changeLoggedUserPassword();
    addressBook.userLogout();

    return 0;
}

