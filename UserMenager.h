#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>
#include "FileWithUsers.h"

using namespace std;

class UserMenager
{
    int idLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User giveNewUserData();
    int retrieveNewUserData();
    bool checkLoginExists(string);
    void saveAllUsersInFile();

public:
    // CONSTRUCTOR
    UserMenager(string);
    // DESCRUCTOR
    ~UserMenager();

    void userSignUp();
    void userLogin();
    void loadUsersFromFile();
    void changeLoggedUserPassword();
    void userLogout();
    void showAllUsers();
    int getLoggedUserId();
};

#endif
