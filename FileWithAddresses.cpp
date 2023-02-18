#include "FileWithAddresses.h"

// SETTERS
void FileWithAddresses::setLastAddresseeId(int newLastAddresseeId)
{
    lastAddresseeId = newLastAddresseeId;
}

// GETTERS
int FileWithAddresses::getLastAddresseeId()
{
    return lastAddresseeId;
}

vector <Addressee> FileWithAddresses::loadAddressesLoggedUserFromFile(int loggedUserId)
{
    Addressee addressee;
    vector <Addressee> addresses;
    lastAddresseeId = 0;

    string singleAddresseeDataSeparatedByLines = "";
    string lastAddresseeDataInFile = "";
    fstream textFile;
    textFile.open(FILE_NAME_WITH_ADDRESSES, ios::in);

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
        lastAddresseeId = retrieveAddresseeIdFromDataSeparatedByLines(lastAddresseeDataInFile);
    }
    else
        lastAddresseeId = 0;

    return addresses;
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

bool FileWithAddresses::addAddresseeToFile(Addressee addressee)
{
    string lineWithAddresseeData = "";
    fstream textFile;
    textFile.open(FILE_NAME_WITH_ADDRESSES, ios::out | ios::app);

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
        lastAddresseeId++;
        textFile.close();
        return true;
    }
    else
    {
        cout << "Opening file failed." << endl;
    }
    return false;
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
