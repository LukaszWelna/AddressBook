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

    if (textFile.good())
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

    if (textFile.good())
    {
        lineWithAddresseeData = convertAddresseeDataToProperFormatInFile(addressee);

        if (AuxiliaryMethods::checkFileEmpty(textFile))
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

bool FileWithAddresses::addAddressesAfterDelete(int addresseeId)
{
    string line = "";
    bool firstLine = true;
    Addressee addressee;
    fstream textFileAddresses, textFileAddressesTemp;
    textFileAddresses.open(FILE_NAME_WITH_ADDRESSES, ios::in);
    textFileAddressesTemp.open(TEMP_FILE_NAME_WITH_ADDRESSES, ios::out | ios::app);

    if ((textFileAddresses.good()) && (textFileAddressesTemp.good()))
    {
        while(getline(textFileAddresses, line))
        {
            addressee = pullDataFromFileToStruct(line);
            if (!(addressee.getId() == addresseeId))
            {
                if (!firstLine)
                {
                    textFileAddressesTemp << endl;
                }
                textFileAddressesTemp << addressee.getId() << "|";
                textFileAddressesTemp << addressee.getUserId() << "|";
                textFileAddressesTemp << addressee.getFirstName() << "|";
                textFileAddressesTemp << addressee.getLastName() << "|";
                textFileAddressesTemp << addressee.getPhoneNumber() << "|";
                textFileAddressesTemp << addressee.getEmail() << "|";
                textFileAddressesTemp << addressee.getAddress() << "|";

                firstLine = false;
            }
        }
    }
    else
    {
        cout << "Opening file failed." << endl;
        textFileAddressesTemp.close();
        textFileAddresses.close();
        return false;
    }
    textFileAddressesTemp.close();
    textFileAddresses.close();

    // DELETE OLD FILE AND RENAME TEMP FILE
    renameTempFile();

    // CHECK IF THE LAST ADDRESSEE DELETED
    if (addresseeId == lastAddresseeId)
    {
        lastAddresseeId = retrieveLastAddresseIdFromFile();
    }

    return true;
}

Addressee FileWithAddresses::pullDataFromFileToStruct(string line)
{
    Addressee addressee;
    int numberOfLoadedData = 0, stringLength = 0;

    int i = 0;
    while (i < (int) line.length())
    {
        if (line[i] == '|')
        {
            switch(numberOfLoadedData)
            {
            case 0:
                addressee.setId(stoi(line.substr(0, stringLength)));
                break;
            case 1:
                addressee.setUserId(stoi(line.substr(i - stringLength, stringLength)));
                break;
            case 2:
                addressee.setFirstName(line.substr(i - stringLength, stringLength));
                break;
            case 3:
                addressee.setLastName(line.substr(i - stringLength, stringLength));
                break;
            case 4:
                addressee.setPhoneNumber(line.substr(i - stringLength, stringLength));
                break;
            case 5:
                addressee.setEmail(line.substr(i - stringLength, stringLength));
                break;
            case 6:
                addressee.setAddress(line.substr(i - stringLength, stringLength));
                break;

            }
            numberOfLoadedData++;
            stringLength = 0;
        }
        else
        {
            stringLength++;
        }

        i++;
    }

    return addressee;
}

void FileWithAddresses::renameTempFile()
{
    if (remove(FILE_NAME_WITH_ADDRESSES.c_str()) == 0)
    {
        // RENAME TEMPORARY FILE
        if (rename(TEMP_FILE_NAME_WITH_ADDRESSES.c_str(), FILE_NAME_WITH_ADDRESSES.c_str()) != 0)
        {
            cout << "Rename of file name failed." << endl;
        }

    }
    else
    {
        cout << "Deleting old file failed." << endl;
    }
}

int FileWithAddresses::retrieveLastAddresseIdFromFile()
{
    int lastAddresseIdFile = 0;
    string singleAddresseeDataSeparatedByLines = "";
    string lastAddresseeData = "";
    fstream textFile;
    textFile.open(FILE_NAME_WITH_ADDRESSES, ios::in);

    if (textFile.good())
    {
        while (getline(textFile, singleAddresseeDataSeparatedByLines))
        {
            lastAddresseeData = singleAddresseeDataSeparatedByLines;
        }

        if (lastAddresseeData != "")
        {
            lastAddresseIdFile = retrieveAddresseeIdFromDataSeparatedByLines(lastAddresseeData);
        }
    }
    else
    {
        cout << "Opening file failed." << endl;
        return 0;
    }

    textFile.close();
    return lastAddresseIdFile;
}


bool FileWithAddresses::addAddressesAfterEdit(vector <Addressee>::iterator it)
{
    string line = "";
    bool firstLine = true;
    Addressee addressee;
    fstream textFileAddresses, textFileAddressesTemp;
    textFileAddresses.open(FILE_NAME_WITH_ADDRESSES, ios::in);
    textFileAddressesTemp.open(TEMP_FILE_NAME_WITH_ADDRESSES, ios::out | ios::app);

    if ((textFileAddresses.good()) && (textFileAddressesTemp.good()))
    {
        while(getline(textFileAddresses, line))
        {
            addressee = pullDataFromFileToStruct(line);

            if (addressee.getId() == it -> getId())
            {
                addressee.setFirstName(AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(it -> getFirstName()));
                addressee.setLastName(AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(it -> getLastName()));
                addressee.setPhoneNumber(it -> getPhoneNumber());
                addressee.setEmail(it -> getEmail());
                addressee.setAddress(it -> getAddress());
            }

            if (!firstLine)
            {
                textFileAddressesTemp << endl;
            }
            textFileAddressesTemp << addressee.getId() << "|";
            textFileAddressesTemp << addressee.getUserId() << "|";
            textFileAddressesTemp << addressee.getFirstName() << "|";
            textFileAddressesTemp << addressee.getLastName() << "|";
            textFileAddressesTemp << addressee.getPhoneNumber() << "|";
            textFileAddressesTemp << addressee.getEmail() << "|";
            textFileAddressesTemp << addressee.getAddress() << "|";

            firstLine = false;
        }
    }
    else
    {
        cout << "Opening file failed." << endl;
        textFileAddressesTemp.close();
        textFileAddresses.close();
        return false;
    }

    textFileAddressesTemp.close();
    textFileAddresses.close();
    // DELETE OLD FILE AND RENAME TEMP FILE
    renameTempFile();

    return true;
}

