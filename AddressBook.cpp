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
    if (userLogged())
    {
        addresseeMenager = new AddresseeMenager(FILE_NAME_WITH_ADDRESSES, userMenager.getLoggedUserId(), TEMP_FILE_NAME_WITH_ADDRESSES);
    }
}

int AddressBook::getLoggedUserId()
{
    return userMenager.getLoggedUserId();
}

void AddressBook::changeLoggedUserPassword()
{
    if (userLogged())
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
    if (userLogged())
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
    if (userLogged())
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

bool AddressBook::userLogged()
{
    if (userMenager.getLoggedUserId() > 0)
        return true;
    else
        return false;
}

void AddressBook::searchByFirstname()
{
    addresseeMenager -> searchByFirstname();
}

void AddressBook::searchByLastname()
{
    addresseeMenager -> searchByLastname();
}

void AddressBook::deleteAddressee()
{
    addresseeMenager -> deleteAddressee();
}

void AddressBook::editAddressee()
{
    addresseeMenager -> editAddressee();
}
