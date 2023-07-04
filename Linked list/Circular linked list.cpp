#include <iostream>
using namespace std;

// Node structure
struct Node 
{
    int data;
    Node* next;
};

// Function to insert a new node at the beginning of the circular linked list
void insertAtBeginning(Node*& head, int data) 
{
    Node* newNode = new Node();
    newNode->data = data;

    if (head == nullptr) 
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != head)
        current = current->next;

    current->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the end of the circular linked list
void insertAtEnd(Node*& head, int data) 
{
    Node* newNode = new Node();
    newNode->data = data;

    if (head == nullptr) 
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != head)
        current = current->next;

    current->next = newNode;
    newNode->next = head;
}

// Function to display the circular linked list
void displayList(Node* head) 
{
    if (head == nullptr)
        return;

    Node* current = head;
    do 
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

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
    cout << "Circular Linked List: ";
    displayList(head);

    // Insert nodes at the end
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    // Display the list
    cout << "Circular Linked List: ";
    displayList(head);

    return 0;
}
