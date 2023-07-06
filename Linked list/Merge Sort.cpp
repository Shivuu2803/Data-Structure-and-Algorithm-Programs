#include <iostream>
using namespace std;

// Linked list node structure
struct Node 
{
    int data;
    Node* next;

    Node(int value) 
    {
        data = value;
        next = nullptr;
    }
};

// Merge two sorted linked lists
Node* merge(Node* left, Node* right) 
{
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }

    Node* result = nullptr;
    if (left->data <= right->data) 
    {
        result = left;
        result->next = merge(left->next, right);
    } else 
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Split the linked list into two halves
void split(Node* source, Node** left, Node** right) 
{
    if (source == nullptr || source->next == nullptr) 
    {
        *left = source;
        *right = nullptr;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    while (fast != nullptr) 
    {
        fast = fast->next;
        if (fast != nullptr) 
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = source;
    *right = slow->next;
    slow->next = nullptr;
}

// Merge sort for linked list
void mergeSort(Node** headRef) 
{
    Node* head = *headRef;
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node* left;
    Node* right;

    split(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = merge(left, right);
}

// Insert a node at the beginning of the linked list
void push(Node** headRef, int value) 
{
    Node* newNode = new Node(value);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Print the linked list
void printList(Node* node) 
{
    while (node != nullptr) 
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Test the merge sort implementation
int main() 
{
    Node* head = nullptr;
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 3);

    cout << "Linked list before sorting: ";
    printList(head);

    mergeSort(&head);

    cout << "Linked list after sorting: ";
    printList(head);

    return 0;
}
