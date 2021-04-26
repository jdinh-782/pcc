//
// Name : Johnson Dinh
// SSID : 
// Assignment #: 1
// Submission Date : 3/9/21
//

#include "Container.hpp"


int main()
{
    cout << "\n ******************* Test 1 *******************\n";
    cout << " Testing Container<std::string,5>\n";
    Container<string, 5> container_of_strings;

    cout << " Testing Container<std::string,5>:: add_items() {Green, Red, Black}\n";
    container_of_strings.add_item("Green");
    container_of_strings.add_item("Red");
    container_of_strings.add_item("Black");

    cout << " Testing Container<std::string,5>:: range-based-for-loop()\n";
    for (auto &str : container_of_strings)
    {
        cout << " " << str;
    }

    cout << "\n Testing Container<std::string,5 >::remove_item(Red)\n";
    container_of_strings.remove_item("Red");

    cout << " Testing Container<std::string,5 >::range-based-for-loop()\n";
    for (auto &str : container_of_strings)
    {
        cout << " " << str;
    }

    cout << "\n Testing Container<std::string,5>::size()\n";
    cout << " container_of_strings.size()=" << container_of_strings.size() << "\n";

    cout << "\n ******************* Test 2 *******************\n";
    cout << " Testing Container<int,10>::add_item(){0,2,4,...,64,81}\n";
    Container <int,10> container_of_ints;

    for (int i = 0; i < 10; i++)
    {
        container_of_ints.add_item(i * i);
    }

    cout << " Testing Container<int,10>::range-based-for-loop\n";
    for (auto num : container_of_ints)
    {
        cout << " " << num;
    }
    cout << endl << endl << " Item -> " << container_of_ints.get_item(3) << endl;


    cout << "\n Testing Container<int,10>::remove_item(16)\n";
    container_of_ints.remove_item(16);

    cout << " Testing Container<int,10>::range-based-for-loop\n";
    for (auto num : container_of_ints)
    {
        cout << " "  << num;
    }

    cout << "\n Testing Container<int,10>::clear()\n";
    container_of_ints.clear();

    cout << " Testing Container<int,10>::empty()\n";
    cout << " container_of_ints.empty() is " << (container_of_ints.empty()? "True":"False") <<"\n";
    cout << "\n ***** Test completed, enter any key to exit *******\n";

    cout << "\n\n" << *container_of_strings.end();

    char s;
    cin >> s;

    return 0;
}
