#include "AddresseeMenager.h"

void AddresseeMenager::addAddressee()
{
    Addressee addressee;

    system("cls");
    cout << " >>> ADDING NEW ADDRESSEE <<<" << endl << endl;
    addressee = enterAddresseData(LOGGED_USER_ID);
    if (checkAddresseeRepeated(addressee))
    {
        fileWithAddresses.setLastAddresseeId(fileWithAddresses.getLastAddresseeId() - 1);
        return;
    }

    addresses.push_back(addressee);

    if (fileWithAddresses.addAddresseeToFile(addressee))
    {
        cout << "New addressee added." << endl;
    }
    else
    {
        cout << "Error. Adding new addressee failed." << endl;
    }
    system("pause");
}

Addressee AddresseeMenager::enterAddresseData(int loggedUserId)
{
    Addressee addressee;
    addressee.setId(fileWithAddresses.getLastAddresseeId() + 1);
    addressee.setUserId(loggedUserId);

    cout << "Enter first name: ";
    addressee.setFirstName(AuxiliaryMethods::readLine());
    addressee.setFirstName(AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(addressee.getFirstName()));

    cout << "Enter last name: ";
    addressee.setLastName(AuxiliaryMethods::readLine());
    addressee.setLastName(AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(addressee.getLastName()));

    cout << "Enter phone number: ";
    addressee.setPhoneNumber(AuxiliaryMethods::readLine());

    cout << "Enter email: ";
    addressee.setEmail(AuxiliaryMethods::readLine());

    cout << "Enter address: ";
    addressee.setAddress(AuxiliaryMethods::readLine());

    return addressee;
}

bool AddresseeMenager::checkAddresseeRepeated(Addressee addressee)
{
    int i = 0;
    while(i < (int) addresses.size())
    {
        if ((addressee.getFirstName() == addresses[i].getFirstName()) && (addressee.getLastName() == addresses[i].getLastName()) && (addressee.getAddress() == addresses[i].getAddress()) &&
            (addressee.getUserId() == addresses[i].getUserId()))
        {
            cout << "Addressee is present in base." << endl;
            system("pause");
            return true;
        }
        else
        {
            i++;
        }
    }
    return false;
}

bool AddresseeMenager::checkIfAddressesVectorEmpty()
{
    return addresses.empty();
}

void AddresseeMenager::showLoggedUserAddresses()
{
    system("cls");
    if (!addresses.empty())
    {
        cout << "             >>> ADDRESSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Addressee> :: iterator it = addresses.begin(); it != addresses.end(); ++it)
        {
            showAddresseeData(*it);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Address book is empty." << endl << endl;
    }
    system("pause");
}

void AddresseeMenager::showAddresseeData(Addressee addressee)
{
    cout << endl << "Id:               " << addressee.getId() << endl;
    cout << "Firstname:        " << addressee.getFirstName() << endl;
    cout << "Lastname:         " << addressee.getLastName() << endl;
    cout << "Phone number:     " << addressee.getPhoneNumber() << endl;
    cout << "Email:            " << addressee.getEmail() << endl;
    cout << "Address:          " << addressee.getAddress() << endl;
}

int AddresseeMenager::getLastAddresseId()
{
    return fileWithAddresses.getLastAddresseeId();
}

void AddresseeMenager::searchByFirstname()
{
    string addresseeFirstName = "";
    bool addresseeDataShowed = false;

    system("cls");
    if (!addresses.empty())
    {
        cout << ">>> SEARCHING ADDRESSES BY FIRSTNAME <<<" << endl << endl;

        cout << "Enter firstname: ";
        addresseeFirstName = AuxiliaryMethods::readLine();
        addresseeFirstName = AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(addresseeFirstName);

        for (vector <Addressee>::iterator  it = addresses.begin(); it != addresses.end(); it++)
        {
            if (it -> getFirstName() == addresseeFirstName)
            {
                showAddresseeData(*it);
                addresseeDataShowed = true;
            }
        }

        if (!addresseeDataShowed)
        {
            cout << "No present addresses with this firstname." << endl;
        }
    }
    else
    {
        cout << endl << "Address book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AddresseeMenager::searchByLastname()
{
    string addresseeLastName = "";
    bool addresseeDataShowed = false;

    system("cls");
    if (!addresses.empty())
    {
        cout << ">>> SEARCHING ADDRESSES BY LASTNAME <<<" << endl << endl;

        cout << "Enter lastname: ";
        addresseeLastName = AuxiliaryMethods::readLine();
        addresseeLastName = AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(addresseeLastName);

        for (vector <Addressee>::iterator  it = addresses.begin(); it != addresses.end(); it++)
        {
            if (it -> getLastName() == addresseeLastName)
            {
                showAddresseeData(*it);
                addresseeDataShowed = true;
            }
        }

        if (!addresseeDataShowed)
        {
            cout << "No present addresses with this lastname." << endl;
        }
    }
    else
    {
        cout << endl << "Address book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}
