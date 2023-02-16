#include "FileWithUsers.h"

FileWithUsers::FileWithUsers(string FILENAMEWITHUSERS) : fileNameWithUsers(FILENAMEWITHUSERS)
{

}

FileWithUsers::~FileWithUsers()
{

}

void FileWithUsers::addUserToFile(User user)
{
    fstream textFile;
    string lineWithUserData = "";
    textFile.open(fileNameWithUsers, ios::out | ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = convertUserDataToProperFormatInFile(user);

        if (AuxiliaryMethods::checkFileEmpty(textFile) == true)
        {
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData ;
        }
    }
    else
    {
        cout << "Opening file and save data failed in file: " << fileNameWithUsers << endl;
        system("pause");
    }
    textFile.close();
}

string FileWithUsers::convertUserDataToProperFormatInFile(User user)
{
    string lineWithUserData = "";
    lineWithUserData += AuxiliaryMethods::convertIntToString(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    fstream textFile;
    User user;
    vector <User> users;

    textFile.open(fileNameWithUsers, ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, singleUserDataSeparatedByLines))
        {
            user = getSingleUserData();
            users.push_back(user);
        }
    }
    textFile.close();
    return users;
}

User FileWithUsers::getSingleUserData()
{
    User user;
    string singleUserData = "";
    int numberOfSingleUserData = 1;

    for (int signPosition = 0; signPosition < (int) singleUserDataSeparatedByLines.length(); signPosition++)
    {
        if (singleUserDataSeparatedByLines[signPosition] != '|')
        {
            singleUserData += singleUserDataSeparatedByLines[signPosition];
        }
        else
        {
            switch(numberOfSingleUserData)
            {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            numberOfSingleUserData++;
        }
    }
    return user;
}

void FileWithUsers::saveAllUsersInFile(vector <User> users)
{
    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itEnd = --users.end();

    textFile.open(fileNameWithUsers, ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator it = users.begin(); it != users.end(); it++)
        {
            lineWithUserData = convertUserDataToProperFormatInFile(*it);

            if (it == itEnd)
            {
               textFile << lineWithUserData;
            }
            else
            {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    }
    else
    {
        cout << "Cannot open a file" << fileNameWithUsers << endl;
    }
    textFile.close();
}
