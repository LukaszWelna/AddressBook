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
    const string fileNameWithAddresses;

    int retrieveUserIdFromDataSeparatedByLines(string);
    int retrieveAddresseeIdFromDataSeparatedByLines(string);
    Addressee getSingleAddresseData(string);
    string convertAddresseeDataToProperFormatInFile(Addressee);

public:
    //CONSTRUCTOR
    FileWithAddresses(string);
    //DESCRUCTOR
    ~FileWithAddresses();

    int loadAddressesLoggedUserFromFile(vector <Addressee> &, int);
    void addAddresseeToFile(Addressee);

};

#endif
