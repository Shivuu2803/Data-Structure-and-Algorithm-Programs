#include <iostream>
using namespace std;

// Node structure
struct Node 
{
    int data;
    Node* prev;
    Node* next;
};

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(Node*& head, int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
    {
        head->prev = newNode;

    }
    head = newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(Node*& head, int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) 
    {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

// Function to display the doubly linked list in forward order
void displayForward(Node* head) 
{
    Node* current = head;
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to display the doubly linked list in reverse order
void displayReverse(Node* head) 
{
    Node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->prev;
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

    // Display the list in forward order
    cout << "Doubly Linked List (Forward): ";
    displayForward(head);

    // Display the list in reverse order
    cout << "Doubly Linked List (Reverse): ";
    displayReverse(head);

    // Insert nodes at the end
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    // Display the list in forward order
    cout << "Doubly Linked List (Forward): ";
    displayForward(head);

    // Display the list in reverse order
    cout << "Doubly Linked List (Reverse): ";
    displayReverse(head);

    return 0;
}
