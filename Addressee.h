#ifndef ADDRESSEE_H
#define ADDRESSEE_H

#include <iostream>

using namespace std;

class Addressee
{
    // ATTRIBUTES
    int id;
    int userId;
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
    string address;

    // METHODS
public:
    // CONSTRUCTOR
    Addressee(int id = 0, int userId = 0, string firstName = "", string lastName = "", string phoneNumber = "", string email = "", string address = "")
    {
        this -> id = id;
        this -> userId = userId;
        this -> firstName = firstName;
        this -> lastName = lastName;
        this -> phoneNumber = phoneNumber;
        this -> email = email;
        this -> address = address;
    }

    // SETTERS
    void setId(int);
    void setUserId(int);
    void setFirstName(string);
    void setLastName(string);
    void setPhoneNumber(string);
    void setEmail(string);
    void setAddress(string);

    // GETTERS
    int getId();
    int getUserId();
    string getFirstName();
    string getLastName();
    string getPhoneNumber();
    string getEmail();
    string getAddress();
};

#endif
