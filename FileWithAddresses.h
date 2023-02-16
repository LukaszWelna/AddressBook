#ifndef FILEWITHADDRESSES_H
#define FILEWITHADDRESSES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Addressee.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithAddresses
{
    // ATTRIBUTES
    const string fileNameWithAddresses;
    int lastAddresseeId;

    // METHODS
    int retrieveUserIdFromDataSeparatedByLines(string);
    int retrieveAddresseeIdFromDataSeparatedByLines(string);
    Addressee getSingleAddresseData(string);
    string convertAddresseeDataToProperFormatInFile(Addressee);

public:
    //CONSTRUCTOR
    FileWithAddresses(string FILENAMEWITHADDRESSES) : fileNameWithAddresses(FILENAMEWITHADDRESSES)
    {

    }

    // SETTERS
    void setLastAddresseeId(int);

    // GETTERS
    int getLastAddresseeId();

    vector <Addressee> loadAddressesLoggedUserFromFile(int);
    void addAddresseeToFile(Addressee);

};

#endif
