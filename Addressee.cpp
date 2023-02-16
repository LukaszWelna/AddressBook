#include "Addressee.h"

Addressee::Addressee()
{

}

Addressee::~Addressee()
{

}

// SETTERS
void Addressee::setUserId(int newUserId)
{
    if (newUserId > 0)
    {
        userId = newUserId;
    }
}

void Addressee::setId(int newId)
{
    if (newId > 0)
    {
        id = newId;
    }
}

void Addressee::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}

void Addressee::setLastName(string newLastName)
{
    lastName = newLastName;
}

void Addressee::setPhoneNumber(string newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}

void Addressee::setEmail(string newEmail)
{
    email = newEmail;
}

void Addressee::setAddress(string newAddress)
{
    address = newAddress;
}

// GETTERS
int Addressee::getUserId()
{
    return userId;
}

int Addressee::getId()
{
    return id;
}

string Addressee::getFirstName()
{
    return firstName;
}

string Addressee::getLastName()
{
    return lastName;
}


string Addressee::getPhoneNumber()
{
    return phoneNumber;
}


string Addressee::getEmail()
{
    return email;
}


string Addressee::getAddress()
{
    return address;
}

