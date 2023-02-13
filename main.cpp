#include <iostream>
#include <windows.h>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt", "Addresses.txt");
    addressBook.showAllUsers();
    addressBook.userSignUp();
    addressBook.userLogin();
    addressBook.showLoggedUserAddresses();
    addressBook.addAddressee();
    if (addressBook.getLoggedUserId() != 0)
    {
        addressBook.changeLoggedUserPassword();
    }
    addressBook.userLogout();
    cout << addressBook.getLoggedUserId() << endl;
    system("pause");


    return 0;
}
