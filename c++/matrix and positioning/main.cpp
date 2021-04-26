#include <iostream>

using namespace std;

//This function will print all the contents of a 2D Array. It will only work on 2D Arrays with 8 columns.
void print2DArray (int theMatrix[][8], int xNumberUsed)
{
    for (int i = 0; i < xNumberUsed; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << theMatrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{

    int theMatrix[5][8] = { {1, 2, 3, 4, 5, 6, 7, 8},
                            {5, 7, 8, 2, 9, 0, 4, 6},
                            {0},
                            {2, 3, 1, 6, 1, 5, 9, 9},
                            {7, 2, 8, 5, 0, 4, 6, 3}
                            };

    print2DArray (theMatrix, 5);

    char direction;
    int xPos(1), yPos(2);

    do
    {
        cout << "We are at " << xPos << ", " << yPos << " with a value of " << theMatrix[xPos][yPos] << endl;
        cout << "Which direction? ";
        cin >> direction;

        switch (direction)
        {
            case 'u':
            case 'U': xPos--; break;
            case 'd':
            case 'D': xPos++; break;
            case 'l':
            case 'L': yPos--; break;
            case 'r':
            case 'R': yPos++; break;
        }

    } while (true);

    int theCountList[14] = {0}; //0, 1...13
    //each index represents the number of times that the user entered that specific value

    for (int i = 0; i < 5; i++)
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        if (theCountList[num] > 0)
        {
            cout << "You entered that number already!\n";
        }

        theCountList[num]++;
    }

    cout << endl;

    for (int i = 1; i < 14; i++)
    {
        cout << i << " was entered " << theCountList[i] << " times!\n";
    }


return 0;
}
