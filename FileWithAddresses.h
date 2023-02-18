#ifndef FILEWITHADDRESSES_H
#define FILEWITHADDRESSES_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Addressee.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithAddresses
{
    // ATTRIBUTES
    const string FILE_NAME_WITH_ADDRESSES;
    int lastAddresseeId;

    // METHODS
    int retrieveUserIdFromDataSeparatedByLines(string);
    int retrieveAddresseeIdFromDataSeparatedByLines(string);
    Addressee getSingleAddresseData(string);
    string convertAddresseeDataToProperFormatInFile(Addressee);

public:
    //CONSTRUCTOR
    FileWithAddresses(string fileNameWithAddresses) : FILE_NAME_WITH_ADDRESSES(fileNameWithAddresses)
    {
        lastAddresseeId = 0;
    }

    // SETTERS
    void setLastAddresseeId(int);

    // GETTERS
    int getLastAddresseeId();

    vector <Addressee> loadAddressesLoggedUserFromFile(int);
    bool addAddresseeToFile(Addressee);

};

#endif
