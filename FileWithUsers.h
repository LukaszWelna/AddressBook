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
    const string fileNameWithUsers;
    string singleUserDataSeparatedByLines;

    // METHODS
    string convertUserDataToProperFormatInFile(User);
    User getSingleUserData();

public:
    //CONSTRUCTOR
    FileWithUsers(string FILENAMEWITHUSERS) : fileNameWithUsers(FILENAMEWITHUSERS)
    {

    }

    void addUserToFile(User);
    vector <User> loadUsersFromFile();
    void saveAllUsersInFile(vector <User>);

};

#endif
