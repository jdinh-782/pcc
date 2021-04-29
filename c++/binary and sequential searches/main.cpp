#include <iostream>

using namespace std;


int sequentialSearch (int theArray[], int numberUsed, int numberToLookFor)
{
    for (int i = 0; i < numberUsed; i++)
    {
        if (numberToLookFor == theArray[i] )
        {
            return i;
        }
    }
    return -1;
}


int binarySearch (int theArray[], int numberUsed, int numberToLookFor)
{
    int leftIndex = 0;
    int rightIndex = numberUsed - 1;

    do
    {
        int middleIndex = (leftIndex + rightIndex) / 2;

        if ( numberToLookFor == theArray[middleIndex] )
        {
            return middleIndex;
        }

        else if ( numberToLookFor < theArray[middleIndex] )
        {
            rightIndex = middleIndex - 1;
        }

        else //this is the case for when the value is greater than the middle index
        {
            leftIndex = middleIndex + 1;
        }

    } while ( leftIndex < rightIndex );
}


int main()
{

    int theArray[8] = {6, 9, 11, 12, 18, 20, 25, 26};

    int number;

    cout << "What number you looking for? ";
    cin >> number;

    int index = sequentialSearch(theArray, 8, number);

    if ( index == -1 )
    {
        cout << "Number was not found.\n";
    }

    else
    {
        cout << "It was found at index " << index << endl;
    }

    index = binarySearch(theArray, 8, number);

    if ( index == -1 )
    {
        cout << "Number was not found.\n";
    }

    else
    {
        cout << "It was found at index " << index << endl;
    }

return 0;
}
