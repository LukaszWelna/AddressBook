#include "AddressBook.h"

void AddressBook::userSignUp()
{
    userManager.userSignUp();
}

void AddressBook::userLogin()
{
    userManager.userLogin();
    if (userLogged())
    {
        addresseeManager = new AddresseeManager(FILE_NAME_WITH_ADDRESSES, userManager.getLoggedUserId(), TEMP_FILE_NAME_WITH_ADDRESSES);
    }
}

int AddressBook::getLoggedUserId()
{
    return userManager.getLoggedUserId();
}

void AddressBook::changeLoggedUserPassword()
{
    if (userLogged())
    {
        userManager.changeLoggedUserPassword();
    }
    else
    {
        cout << "You are not logged in. Login and try again." << endl;
        system("pause");
    }
}

void AddressBook::userLogout()
{
    userManager.userLogout();
    delete addresseeManager;
    addresseeManager = NULL;
}

void AddressBook::addAddressee()
{
    if (userLogged())
    {
        addresseeManager -> addAddressee();
    }
    else
    {
        cout << "You are not logged in. Login and try again." << endl;
        system("pause");
    }
}

void AddressBook::showLoggedUserAddresses()
{
    if (userLogged())
    {
        addresseeManager -> showLoggedUserAddresses();
    }
    else
    {
        cout << "You are not logged in. Login and try again." << endl;
    }
}

bool AddressBook::userLogged()
{
    if (userManager.getLoggedUserId() > 0)
        return true;
    else
        return false;
}

void AddressBook::searchByFirstname()
{
    addresseeManager -> searchByFirstname();
}

void AddressBook::searchByLastname()
{
    addresseeManager -> searchByLastname();
}

void AddressBook::deleteAddressee()
{
    addresseeManager -> deleteAddressee();
}

void AddressBook::editAddressee()
{
    addresseeManager -> editAddressee();
}
