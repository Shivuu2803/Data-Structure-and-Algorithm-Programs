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

// Function to find the middle of the linked list
Node* findMiddle(Node* head) 
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    cout << "Linked List: ";
    displayList(head);

    // Find the middle of the list
    Node* middle = findMiddle(head);
    if (middle != nullptr)
    {
        cout << "Middle Node: " << middle->data << endl;
    }
    else
    {
        cout << "Middle Node not found!" << endl;
    }

    return 0;
}
