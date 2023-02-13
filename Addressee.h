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
    Addressee();
    // DESCRUCTOR
    ~Addressee();

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
