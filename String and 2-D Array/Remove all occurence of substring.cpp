#include <iostream>
#include <string>
using namespace std;

string removeAllOccurrences(string& str, string& part) 
{
    size_t pos = 0;
    while((pos = str.find(part, pos)) != string::npos)
    {
        str.erase(pos, part.length());
    }
    return str;
}

int main() 
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string part;
    cout << "Enter a string to remove: ";
    cin >> part;

    removeAllOccurrences(str, part);

    cout << "Modified string: " << str << endl;

    return 0;
}
