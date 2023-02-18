#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers
{
    // ATTRIBUTES
    const string FILE_NAME_WITH_USERS;
    string singleUserDataSeparatedByLines;

    // METHODS
    string convertUserDataToProperFormatInFile(User);
    User getSingleUserData();

public:
    //CONSTRUCTOR
    FileWithUsers(string fileNameWithUsers) : FILE_NAME_WITH_USERS(fileNameWithUsers)
    {

    }

    void addUserToFile(User);
    vector <User> loadUsersFromFile();
    void saveAllUsersInFile(vector <User>);

};

#endif
