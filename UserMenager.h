#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include "FileWithUsers.h"

using namespace std;

class UserMenager
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
    UserMenager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers)
    {
        idLoggedUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    }

    void userSignUp();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
    void showAllUsers();
    int getLoggedUserId();
};

#endif
