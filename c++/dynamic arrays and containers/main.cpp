//
// Name: Johnson Dinh
// SSID: 
// Assignment #: 2
// Submission Date: 3/23/21
//

#include "DynArray.hpp"
#include <fstream>  //file streams
#include <iomanip>  //setprecision
#include <iterator> //istream::iterator
#include <string>   //std::string
#include <vector>   //std::vector
#include <numeric>  //std::accumulate
#include <algorithm>//std::sort


int main()
{
    //Part I
    cout << "************ Part I ************\n";
    cout << "Min, max and average of a list of numbers: \n";
    cout << "********************************\n";

    initializer_list<int> il{5, 7, 1, 3, 1024, 19, 29, -64, 0};
    DynArray<int> dyn_int_array(il.size(), il);

    //A2 Todo: Sort the DynArray<int> using std::sort
    //cout << "A2 Todo: sort the DynArray using std::sort\n";

    //A2 Todo: get max and min using DynArray member functions

    //(A2 Todo: get max)
    cout << "max     = " << dyn_int_array.at(4) << endl;

    //(A2 Todo: get min)
    cout << "min     = " << dyn_int_array.at(7) << endl;

    //(A2 Todo: compute average with std::accumulate)
    cout << "average = " << (float) accumulate(dyn_int_array.begin(), dyn_int_array.end(), 0)/dyn_int_array.size();
    cout << endl << endl;

    //Part II
    cout << "************ Part II ************\n";
    cout << "Simple Bioinformatics:\n";
    cout << "*********************************\n";

    //
    // open file: sars_cov_2.txt and count the number of DNA base nucleotides
    //
    string filename = "sars_cov_2.txt";
    ifstream ifs(filename);
    istream_iterator<char> ifs_iter(ifs);
    istream_iterator<char> ifs_end_iter;

    //count number of chars in file
    int base_count = 0;
    for (; ifs_iter != ifs_end_iter; ifs_iter++)
    {
        base_count++;
    }

    //reset ifstream and istream_iterator to beginning of file
    ifs.clear();

    ifs_iter = ifs.seekg(0, ios::beg);

    //copy file data to bases DynArray
    DynArray<char> bases;
    bases.resize(base_count);

    copy(ifs_iter, ifs_end_iter, bases.begin());

    // close the file
    ifs.close();

    //A2 Todo: count of A's, G's, T's, and C's with std::count

    //(A2 Todo: count number of A's)
    cout << "(A)denine  count = " << count(bases.begin(), bases.end(), 'A') << endl;

    //(A2 Todo: count number of G's)
    cout << "(G)uanine  count = " << count(bases.begin(), bases.end(), 'G') << endl;

    //(A2 Todo: count number of T's)
    cout << "(T)hymine  count = " << count(bases.begin(), bases.end(), 'T') << endl;

    //(A2 Todo: count number of C's)
    cout << "(C)ytosine count = " << count(bases.begin(), bases.end(), 'C') << endl;
    cout << endl;

    //A/T and G/C

    //(A2 Todo: Compute A/T)
    cout << fixed << setprecision(2) << "A/T = "
         << (float) count(bases.begin(), bases.end(), 'A') / count(bases.begin(), bases.end(), 'T') << endl;

    //(A2 Todo: Compute G/C)
    cout << fixed << setprecision(2) << "G/C = "
         << (float) count(bases.begin(), bases.end(), 'G') / count(bases.begin(), bases.end(), 'C') << endl;
    cout << endl;

    //cout << endl << bases.data();

    cout << "\n*****Tests completed, enter any key to exit*****\n";
    char s;
    cin >> s;

    return 0;
}
