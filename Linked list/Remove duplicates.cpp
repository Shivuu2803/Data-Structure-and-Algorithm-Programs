#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template<typename T>

void removeDuplicates(list<T>& lst) 
{
    lst.sort(); // Sort the list (only required if the list is unsorted)

    typename list<T>::iterator it = lst.begin();
    while (it != lst.end()) 
    {
        typename std::list<T>::iterator current = it;
        ++current;

        // Remove all subsequent duplicates of the current element
        while (current != lst.end() && *current == *it) 
        {
            current = lst.erase(current);
        }

        ++it;
    }
}

template<typename T>

void printList(const std::list<T>& lst) 
{
    for (const T& element : lst) 
    {
        cout << element << " ";
    }
    cout << endl;
}

int main() 
{
    // Example usage with a sorted list
    list<int> sortedList = {1, 2, 2, 3, 4, 4, 4, 5};
    cout << "Sorted List: ";
    printList(sortedList);

    removeDuplicates(sortedList);

    cout << "List after removing duplicates: ";
    printList(sortedList);

    cout << endl;

    // Example usage with an unsorted list
    list<int> unsortedList = {5, 2, 1, 3, 4, 4, 2, 4};
    cout << "Unsorted List: ";
    printList(unsortedList);

    removeDuplicates(unsortedList);
    
    cout << "List after removing duplicates: ";
    printList(unsortedList);

    return 0;
}
