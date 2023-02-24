#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile
{
    // ATTRIBUTES
    const string FILE_NAME;

    // METHODS

public:
    //CONSTRUCTOR
    TextFile(string fileName) : FILE_NAME(fileName)
    {

    }

    // GETTERS
    const string getFileName();


    bool checkFileEmpty();
};

#endif
