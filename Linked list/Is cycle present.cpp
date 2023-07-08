#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

Node* createNode(int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        Node* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool hasCycle(Node* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return false;
    }
    
    Node* slowPtr = head;
    Node* fastPtr = head;
    
    while (fastPtr != NULL && fastPtr->next != NULL) 
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        
        if (slowPtr == fastPtr) 
        {
            return true;
        }
    }
    
    return false;
}

int main() 
{
    Node* head = NULL;
    
    // Create a linked list with a cycle
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    
    // Create a cycle by connecting the last node to the second node
    head->next->next->next->next->next = head->next;
    
    // Check if the linked list contains a cycle
    if (hasCycle(head)) 
    {
        cout << "The linked list contains a cycle." << endl;
    } 
    else 
    {
        cout << "The linked list does not contain a cycle." << endl;
    }
    
    return 0;
}
