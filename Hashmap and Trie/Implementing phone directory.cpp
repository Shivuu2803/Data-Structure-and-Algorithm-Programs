#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode 
{
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    string phoneNumber;

    TrieNode() 
    {
        isEndOfWord = false;
    }
};

class PhoneDirectory 
{
private:
    TrieNode* root;

public:
    PhoneDirectory() 
    {
        root = new TrieNode();
    }

    void insert(const string& name, const string& phoneNumber) 
    {
        TrieNode* current = root;
        for (char ch : name) 
        {
            if (current->children.find(ch) == current->children.end()) 
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
        current->phoneNumber = phoneNumber;
    }

    bool search(const string& name) 
    {
        TrieNode* current = root;
        for (char ch : name) {
            if (current->children.find(ch) == current->children.end()) 
            {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    string getPhoneNumber(const string& name) 
    {
        TrieNode* current = root;
        for (char ch : name) {
            if (current->children.find(ch) == current->children.end()) 
            {
                return "";
            }
            current = current->children[ch];
        }
        if (current->isEndOfWord) 
        {
            return current->phoneNumber;
        }
        return "";
    }
};

int main() 
{
    PhoneDirectory directory;

    directory.insert("John Doe", "1234567890");
    directory.insert("Jane Smith", "9876543210");
    directory.insert("Alice Johnson", "5678901234");

    string name;
    cout << "Enter a name to search: ";
    getline(cin, name);

    if (directory.search(name)) {
        string phoneNumber = directory.getPhoneNumber(name);
        cout << "Phone number for " << name << ": " << phoneNumber << endl;
    } 
    else 
    {
        cout << "No entry found for " << name << endl;
    }

    return 0;
}
