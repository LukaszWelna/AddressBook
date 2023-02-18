#include <iostream>
#include "AddressBook.h"
#include "MenuMenager.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt", "Addresses.txt");

    char choice;

    while (true)
    {
        if (!addressBook.userLogged())
        {
            choice = MenuMenager::chooseOptionMainMenu();

            switch (choice)
            {
            case '1':
                addressBook.userSignUp();
                break;
            case '2':
                addressBook.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = MenuMenager::chooseOptionUserMenu();

            switch (choice)
            {
            case '1':
                addressBook.addAddressee();
                break;
            /*case '2':
                wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                wyszukajAdresatowPoNazwisku(adresaci);
                break;
            */
            case '4':
                addressBook.showLoggedUserAddresses();
                break;
            /*
            case '5':
                idUsunietegoAdresata = usunAdresata(adresaci);
                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                edytujAdresata(adresaci);
                break;
            */
            case '7':
                addressBook.changeLoggedUserPassword();
                break;
            case '8':
                addressBook.userLogout();
                break;
            default:
                cout << endl << "No option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}

