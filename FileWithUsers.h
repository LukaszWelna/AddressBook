#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithUsers : public TextFile
{
    // ATTRIBUTES
    string singleUserDataSeparatedByLines;

    // METHODS
    string convertUserDataToProperFormatInFile(User);
    User getSingleUserData();

public:
    //CONSTRUCTOR
    FileWithUsers(string fileNameWithUsers) : TextFile(fileNameWithUsers)
    {

    }

    void addUserToFile(User);
    vector <User> loadUsersFromFile();
    void saveAllUsersInFile(vector <User>);

};

#endif
