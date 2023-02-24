#include "MenuMenager.h"

char MenuMenager::chooseOptionMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Login" << endl;
    cout << "9. End" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readSign();

    return choice;
}

char MenuMenager::chooseOptionUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add addressee" << endl;
    cout << "2. Search by firstname" << endl;
    cout << "3. Search by lastname" << endl;
    cout << "4. Show all addresses" << endl;
    cout << "5. Delete addressee" << endl;
    cout << "6. Edit addressee" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readSign();

    return choice;
}
