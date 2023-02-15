#include <iostream>
#include "FileWithAddresses.h"

using namespace std;

FileWithAddresses::FileWithAddresses(string FILENAMEWITHADDRESSES) : fileNameWithAddresses(FILENAMEWITHADDRESSES)
{

}

FileWithAddresses::~FileWithAddresses()
{

}

int FileWithAddresses::loadAddressesLoggedUserFromFile(vector <Addressee> &addresses, int loggedUserId)
{
    Addressee addressee;
    int lastAddresseId = 0;

    string singleAddresseeDataSeparatedByLines = "";
    string lastAddresseeDataInFile = "";
    fstream textFile;
    textFile.open(fileNameWithAddresses, ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, singleAddresseeDataSeparatedByLines))
        {
            if(loggedUserId == retrieveUserIdFromDataSeparatedByLines(singleAddresseeDataSeparatedByLines))
            {
                addressee = getSingleAddresseData(singleAddresseeDataSeparatedByLines);
                addresses.push_back(addressee);
            }
        }
        lastAddresseeDataInFile = singleAddresseeDataSeparatedByLines;
    }

    textFile.close();

    if (lastAddresseeDataInFile != "")
    {
        lastAddresseId = retrieveAddresseeIdFromDataSeparatedByLines(lastAddresseeDataInFile);
        return lastAddresseId;
    }
    else
        return 0;
}

int FileWithAddresses::retrieveUserIdFromDataSeparatedByLines(string singleAddresseeDataSeparatedByLines)
{
    int startPositionUserId = singleAddresseeDataSeparatedByLines.find_first_of('|') + 1;
    int userId = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::retrieveIntFromString(singleAddresseeDataSeparatedByLines, startPositionUserId));

    return userId;
}

Addressee FileWithAddresses::getSingleAddresseData(string singleAddresseeDataSeparatedByLines)
{
    Addressee addressee;
    string singleAddresseeData = "";
    int numberOfSingleAddresseeData = 1;

    for (int signPosition = 0; signPosition < (int) singleAddresseeDataSeparatedByLines.length(); signPosition++)
    {
        if (singleAddresseeDataSeparatedByLines[signPosition] != '|')
        {
            singleAddresseeData += singleAddresseeDataSeparatedByLines[signPosition];
        }
        else
        {
            switch(numberOfSingleAddresseeData)
            {
            case 1:
                addressee.setId(atoi(singleAddresseeData.c_str()));
                break;
            case 2:
                addressee.setUserId(atoi(singleAddresseeData.c_str()));
                break;
            case 3:
                addressee.setFirstName(singleAddresseeData);
                break;
            case 4:
                addressee.setLastName(singleAddresseeData);
                break;
            case 5:
                addressee.setPhoneNumber(singleAddresseeData);
                break;
            case 6:
                addressee.setEmail(singleAddresseeData);
                break;
            case 7:
                addressee.setAddress(singleAddresseeData);
                break;
            }
            singleAddresseeData = "";
            numberOfSingleAddresseeData++;
        }
    }
    return addressee;
}

int FileWithAddresses::retrieveAddresseeIdFromDataSeparatedByLines(string lastAddresseeDataInFile)
{
    int startPositionUserId = 0;
    int AddresseeId = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::retrieveIntFromString(lastAddresseeDataInFile, startPositionUserId));
    return AddresseeId;
}

void FileWithAddresses::addAddresseeToFile(Addressee addressee)
{
    string lineWithAddresseeData = "";
    fstream textFile;
    textFile.open(fileNameWithAddresses, ios::out | ios::app);

    if (textFile.good() == true)
    {
        lineWithAddresseeData = convertAddresseeDataToProperFormatInFile(addressee);

        if (AuxiliaryMethods::checkFileEmpty(textFile) == true)
        {
            textFile << lineWithAddresseeData;
        }
        else
        {
            textFile << endl << lineWithAddresseeData ;
        }
    }
    else
    {
        cout << "Opening file failed." << endl;
    }
    textFile.close();
    system("pause");
}

string FileWithAddresses::convertAddresseeDataToProperFormatInFile(Addressee addressee)
{
    string lineWithAddresseeData = "";

    lineWithAddresseeData += AuxiliaryMethods::convertIntToString(addressee.getId()) + '|';
    lineWithAddresseeData += AuxiliaryMethods::convertIntToString(addressee.getUserId()) + '|';
    lineWithAddresseeData += addressee.getFirstName() + '|';
    lineWithAddresseeData += addressee.getLastName() + '|';
    lineWithAddresseeData += addressee.getPhoneNumber() + '|';
    lineWithAddresseeData += addressee.getEmail() + '|';
    lineWithAddresseeData += addressee.getAddress() + '|';

    return lineWithAddresseeData;
}