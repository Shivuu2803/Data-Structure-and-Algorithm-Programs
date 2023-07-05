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

// Function to detect a cycle in the linked list
bool hasCycle(Node* head) 
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
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
    Node* current = head;
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Check if the list has a cycle
    bool hasCycleList = hasCycle(head);
    if (hasCycleList)
    {
        cout << "The linked list has a cycle." << endl;
    }
    else
    {
        cout << "The linked list does not have a cycle." << endl;
    }

    // Create a cycle by connecting the last node to the second node
    Node* lastNode = head;
    while (lastNode->next != nullptr)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = head->next;

    // Check if the list has a cycle again
    hasCycleList = hasCycle(head);
    if (hasCycleList)
    {
        cout << "The linked list has a cycle." << endl;
    }
    else
    {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
