#include "AuxiliaryMethods.h"

char AuxiliaryMethods::readSign()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "It is not a sign. Try again." << endl;
    }
    return sign;
}

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
    while(isdigit(text[startPosition]))
    {
        number += text[startPosition];
        startPosition ++;
    }
    return number;
}

string AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
