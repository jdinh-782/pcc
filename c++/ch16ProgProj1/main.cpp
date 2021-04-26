//Chapter 16 Programming Project 1


#include <iostream>
#include <string>
#include <exception>

using namespace std;


class InvalidNumberException : public exception
{
public:
    virtual const char* message() noexcept
    {
        return "One or more of the characters is invalid for conversion!";
    }
};


int main()
{
    string hexadecimal; //16 symbols - {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F} - 'A'-'F' represents 10-15

    cout << "Enter a hexadecimal: ";
    cin >> hexadecimal;

    for (char i : hexadecimal)
    {
        try
        {
            if (i >= 47 && i <= 57 || i >= 65 && i <= 70 || i >= 97 && i <= 102) //checks if index is between the numbers 0-9, or between letters A-F
            {
                continue;
            }
            else
            {
                throw InvalidNumberException(); //immediately throw an exception as soon as the index does not satisfy the condition
            }
        }

        catch (InvalidNumberException e)
        {
            cout << e.message() << " " << e.what() << endl;
            exit(0);
        }
    }

    int num = stoi(hexadecimal, nullptr, 16);
    cout << "Number after converting \"" << hexadecimal << "\" to integer: " <<  num;

    return 0;
}
