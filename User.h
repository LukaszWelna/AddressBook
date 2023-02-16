#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    // ATTRIBUTES
    int id;
    string login, password;

    // METHODS
public:
    // SETTERS
    void setId(int);
    void setLogin(string);
    void setPassword(string);

    // GETTERS
    int getId();
    string getLogin();
    string getPassword();

};

#endif
