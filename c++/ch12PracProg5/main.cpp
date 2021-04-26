//Chapter 12 Practice Program 5


#include <iostream>
#include <string>

using namespace std;

namespace
{
    string username;

    bool isValid()
    {
        if (username.length() == 8)
        {
            return true;
        }

        else
        {
            cout << "\nYour username can only be 8 letters! Try again!";
            return false;
        }
    }
}


namespace authenticate
{
    void inputUserName()
    {
        do
        {
            cout << "\nEnter your username: ";
            cin >> username;

        } while (!isValid());
    }

    string getUserName()
    {
        return username;
    }
}


namespace
{
    string passwordInput;

    bool isValidPassword()
    {
        if (passwordInput.length() == 8)
        {
            for (int i = 0; i < passwordInput.length(); i++)
            {
                if ( !(('a' <= passwordInput.at(i) && 'z' >= passwordInput.at(i))) )
                {
                    return true;
                }

                else if ( !(('A' <= passwordInput.at(i) && 'Z' >= passwordInput.at(i))) )
                {
                    return true;
                }
            }
        }
        return false;
    }
}


namespace authenticate
{
    void inputPassword()
    {
        do
        {
            cout << "\nEnter your password: ";
            cin >> passwordInput;
        } while(!isValidPassword());
    }

    string getPassword()
    {
        return passwordInput;
    }
}


int main()
{
    using namespace authenticate;

    authenticate::inputPassword();
    authenticate::inputUserName();

    cout << "\nYour username is " << getUserName() << " and your password is: " << getPassword() << endl;

    return 0;
}
