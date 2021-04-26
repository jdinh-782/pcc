//Chapter 16 Programming Project 3


#include <iostream>
#include <exception>

using namespace std;


class ThrowInvalidAmount : public exception
{
public:
    virtual const char* message() noexcept
    {
        return "Invalid input!";
    }
};


class ThrowStringInput : public exception
{
public:
    virtual const char* message() noexcept
    {
        return "Please enter your number using digits only. Try again. ";
    }
};


class ThrowInvalidNumberInput : public exception
{
public:
    virtual const char* message() noexcept
    {
        return "The number must be between 1-10. Try Again. ";
    }
};


//check is amount is less than 1 or not numerical
void invalidAmount(int amount)
{
    try
    {
        if (cin.fail() || amount < 1)
        {
            throw ThrowInvalidAmount();
        }
    }

    catch (ThrowInvalidAmount& e)
    {
        cout << e.message();
        exit(0);
    }
}


//checks if there are non-numerical characters in number input
bool checkStringToNum(const string& s)
{
    for (char letter : s)
    {
        try
        {
            if (letter >= 48 && letter <= 57)
            {
                continue;
            }
            else
            {
                throw ThrowStringInput();
            }
        }

        catch (ThrowStringInput& e)
        {
            cout << e.message() << endl;
            return false;
        }
    }
    return true;
}


//checks if number entered is less than 1 or greater than 10
bool checkNum(int num)
{
    try
    {
        if (num < 1 || num > 10)
        {
            throw ThrowInvalidNumberInput();
        }
    }

    catch (ThrowInvalidNumberInput& e)
    {
        cout << e.message() << endl;
        return false;
    }
    return true;
}


int main()
{
    int amount;
    string s;

    cout << "Enter a numerical amount for number inputs: ";
    cin >> amount;

    invalidAmount(amount);

    int arrayList[amount];

    for (int i = 0; i < amount; i++)
    {
        cout << "\nEnter number " << i + 1 << ": ";
        cin >> s;

        if (checkStringToNum(s))
        {
            int num = atoi(s.c_str());
            if (checkNum(num))
            {
                arrayList[i] = num;
                continue;
            }
            else
            {
                i--;
            }
        }
        else
        {
            i--;
        }
    }

//    for (int j = 0; j < amount; j++)
//    {
//        cout << arrayList[j] << " ";
//    }

    cout << "\nHere is the histogram of values:\n";
    for (int i = 0; i < 10; i++)
    {
        string output = to_string(i + 1) + " : ";
        for (int j = 0; j < amount; j++)
        {
            if (arrayList[j] == i + 1)
            {
                output += " *";
            }
        }
        cout << output << endl;
    }
    return 0;
}


