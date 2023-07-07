#include <iostream>
using namespace std;

// Node structure
struct Node 
{
    int data;
    Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node*& head, int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to display the linked list
void displayList(Node* head) 
{
    Node* current = head;
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to reverse the linked list
Node* reverseList(Node* head) 
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() 
{
    Node* head = nullptr; // Initially, the list is empty

    // Insert nodes at the beginning
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    // Display the list
    cout << "Linked List (Before reversal): ";
    displayList(head);

    // Reverse the list
    head = reverseList(head);

    // Display the reversed list
    cout << "Linked List (After reversal): ";
    displayList(head);

    return 0;
}
