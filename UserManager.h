#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    // ATTRIBUTES
    int idLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;

    // METHODS
    User giveNewUserData();
    int retrieveNewUserData();
    bool checkLoginExists(string);
    void saveAllUsersInFile();

public:
    // CONSTRUCTOR
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers)
    {
        idLoggedUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    }

    void userSignUp();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
    int getLoggedUserId();
};

#endif
