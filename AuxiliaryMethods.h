#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class AuxiliaryMethods
{
    // ATTRIBUTES

    // METHODS
public:
    static string readLine();
    static string convertIntToString(int);
    static int convertStringToInt(string);
    static string retrieveIntFromString(string, int);
    static bool checkFileEmpty(fstream &);
};

#endif
