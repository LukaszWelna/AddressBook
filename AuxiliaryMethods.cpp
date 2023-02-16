#include "AuxiliaryMethods.h"

string AuxiliaryMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string stringNumber)
{
    int number;
    istringstream iss(stringNumber);
    iss >> number;

    return number;
}

string AuxiliaryMethods::retrieveIntFromString(string text, int startPosition)
{
    string number = "";
    while(isdigit(text[startPosition]) == true)
    {
        number += text[startPosition];
        startPosition ++;
    }
    return number;
}

bool AuxiliaryMethods::checkFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
