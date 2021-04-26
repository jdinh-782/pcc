//Chapter 14 Practice Program 5


#include <iostream>
//#include <string>

using namespace std;

bool palindrome(string s, int count)
{
    char begin, end;

    int size = s.size() - 1;

    begin = s[count];
    //cout << begin << " ";
    end = s[size - count];

    if (begin != end)
    {
        return false;
    }

    //no/one letter words are automatically palindromes
    if (s.length() == 0 || s.length() == 1)
    {
        return true;
    }

    if (begin < end + 1)
    {
        if (count == s.length())
        {
            return true;
        }
        count++;
        return palindrome(s, count);
    }
    return true;
}


int main()
{
    cout << palindrome("racecar", 0);
    return 0;
}
