#include "TextFile.h"

const string TextFile::getFileName()
{
    return FILE_NAME;
}

bool TextFile::checkFileEmpty()
{
    fstream textFile;
    textFile.open(FILE_NAME, ios::app);

    if (textFile.good())
    {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            return false;
    }
    else
    {
        cout << "Opening file failed." << endl;
    }

    return true;
}
