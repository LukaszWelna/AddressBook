#include "AddressBook.h"

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
        addresseeMenager = new AddresseeMenager(FILE_NAME_WITH_ADDRESSES, userMenager.getLoggedUserId());
    }
}

int AddressBook::getLoggedUserId()
{
    return userMenager.getLoggedUserId();
}

void AddressBook::changeLoggedUserPassword()
{
    if (userMenager.getLoggedUserId() != 0)
    {
        userMenager.changeLoggedUserPassword();
    }
    else
    {
        cout << "You are not logged in. Login and try again." << endl;
        system("pause");
    }
}

void AddressBook::userLogout()
{
    userMenager.userLogout();
    delete addresseeMenager;
    addresseeMenager = NULL;
}

void AddressBook::addAddressee()
{
    if (userMenager.getLoggedUserId() != 0)
    {
        addresseeMenager -> addAddressee();
    }
    else
    {
        cout << "You are not logged in. Login and try again." << endl;
        system("pause");
    }
}

void AddressBook::showLoggedUserAddresses()
{
    if (userMenager.getLoggedUserId() > 0)
    {
        addresseeMenager -> showLoggedUserAddresses();
    }
    else
    {
        cout << "You are not logged in. Login and try again." << endl;
    }
}

void AddressBook::getLastAddresseId()
{
    cout << "Id ostatniego adresata: " << addresseeMenager -> getLastAddresseId() << endl;
    system("pause");
}
