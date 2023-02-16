#include "UserMenager.h"

UserMenager::UserMenager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers)
{

}

UserMenager::~UserMenager()
{

}

void UserMenager::userSignUp()
{
    User user  = giveNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Account created successfully" << endl << endl;
    system("pause");
}

User UserMenager::giveNewUserData()
{
    User user;
    user.setId(retrieveNewUserData());

    do
    {
        cout << "Enter login: ";
        user.setLogin(AuxiliaryMethods::readLine());
    }
    while (checkLoginExists(user.getLogin()) == true);

    cout << "Enter password: ";
    user.setPassword(AuxiliaryMethods::readLine());

    return user;
}

int UserMenager::retrieveNewUserData()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserMenager::checkLoginExists(string login)
{
    for (int i = 0; i < (int) users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "There is a user with this login in base" << endl;
            return true;
        }
    }
    return false;
}

void UserMenager::showAllUsers()
{
    for (int i = 0; i < (int) users.size(); i++)
    {
        cout << users[i].getId() << " " << users[i].getLogin() << " " << users[i].getPassword() << endl;
    }
}

void UserMenager::loadUsersFromFile()
{
    users = fileWithUsers.loadUsersFromFile();
}

void UserMenager::userLogin()
{
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::readLine();

    vector <User>::iterator it = users.begin();
    while (it != users.end())
    {
        if (it -> getLogin() == login)
        {
            for (int numberOfAttemps = 3; numberOfAttemps > 0; numberOfAttemps--)
            {
                cout << "Enter password. Remain attemps: " << numberOfAttemps << ": ";
                password = AuxiliaryMethods::readLine();

                if (it -> getPassword() == password)
                {
                    cout << endl << "Login successful." << endl << endl;
                    system("pause");
                    idLoggedUser = it -> getId();
                    return;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");
            idLoggedUser = 0;
            return;
        }
        it++;
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
    idLoggedUser = 0;
    return;
}

int UserMenager::getLoggedUserId()
{
    return idLoggedUser;
}

void UserMenager::changeLoggedUserPassword()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::readLine();

    for (vector <User>::iterator it = users.begin(); it != users.end(); it++)
    {
        if (it -> getId() == idLoggedUser)
        {
            it -> setPassword(newPassword);
            cout << "Password changed." << endl << endl;
            system("pause");
        }
    }
    saveAllUsersInFile();
}

void UserMenager::saveAllUsersInFile()
{
    fileWithUsers.saveAllUsersInFile(users);
}

void UserMenager::userLogout()
{
    idLoggedUser = 0;
}
