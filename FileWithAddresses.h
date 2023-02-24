#ifndef FILEWITHADDRESSES_H
#define FILEWITHADDRESSES_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Addressee.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithAddresses : public TextFile
{
    // ATTRIBUTES
    const string TEMP_FILE_NAME_WITH_ADDRESSES;
    int lastAddresseeId;

    // METHODS
    int retrieveUserIdFromDataSeparatedByLines(string);
    int retrieveAddresseeIdFromDataSeparatedByLines(string);
    Addressee getSingleAddresseData(string);
    string convertAddresseeDataToProperFormatInFile(Addressee);
    Addressee pullDataFromFileToStruct(string);
    void renameTempFile();
    int retrieveLastAddresseIdFromFile();

public:
    //CONSTRUCTOR
    FileWithAddresses(string fileNameWithAddresses, string tempFileNameWithAddresses) : TextFile(fileNameWithAddresses), TEMP_FILE_NAME_WITH_ADDRESSES(tempFileNameWithAddresses)
    {
        lastAddresseeId = 0;
    }

    // SETTERS
    void setLastAddresseeId(int);

    // GETTERS
    int getLastAddresseeId();

    vector <Addressee> loadAddressesLoggedUserFromFile(int);
    bool addAddresseeToFile(Addressee);
    bool addAddressesAfterDelete(int);
    bool addAddressesAfterEdit(vector <Addressee>::iterator);

};

#endif
