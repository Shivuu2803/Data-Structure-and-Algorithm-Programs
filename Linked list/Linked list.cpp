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

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node*& head, int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) 
    {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) 
    {
        current = current->next;
    }

    current->next = newNode;
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

int main() 
{
    Node* head = nullptr; // Initially, the list is empty

    // Insert nodes at the beginning
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    // Display the list
    cout << "Linked List (After inserting at the beginning): ";
    displayList(head);

    // Insert nodes at the end
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    // Display the list
    cout << "Linked List (After inserting at the end): ";
    displayList(head);

    return 0;
}
