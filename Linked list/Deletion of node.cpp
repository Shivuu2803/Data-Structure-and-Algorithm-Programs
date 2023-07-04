#include <iostream>
using namespace std;

// Node structure
struct Node 
{
    int data;
    Node* next;
};

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

// Function to delete a node from the linked list
void deleteNode(Node*& head, int value) 
{
    // Check if the list is empty
    if (head == nullptr)
        return;

    // Check if the node to be deleted is the head node
    if (head->data == value) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    // Search for the node to be deleted
    while (current != nullptr && current->data != value) 
    {
        prev = current;
        current = current->next;
    }

    // If the node is found, delete it
    if (current != nullptr) 
    {
        prev->next = current->next;
        delete current;
    }
}

int main() 
{
    Node* head = nullptr; // Initially, the list is empty

    // Insert nodes at the end
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    // Display the list
    cout << "Linked List (Before deletion): ";
    displayList(head);

    // Delete a node from the list
    deleteNode(head, 3);

    // Display the list after deletion
    cout << "Linked List (After deletion): ";
    displayList(head);

    return 0;
}
