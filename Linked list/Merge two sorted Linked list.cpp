#include <iostream>
using namespace std;

// Node structure for a linked list
struct Node
{
    int data;
    Node* next;
};

// Function to insert a new node at the beginning of a linked list
void insertNode(Node** head, int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* list1, Node* list2) 
{
    // Check if any list is empty or not
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    Node* mergedList = nullptr;

    // Determine the head of the merged list
    if (list1->data <= list2->data) 
    {
        mergedList = list1;
        list1 = list1->next;
    } 
    else 
    {
        mergedList = list2;
        list2 = list2->next;
    }

    Node* current = mergedList;

    // Merge the remaining nodes
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data) 
        {
            current->next = list1;
            list1 = list1->next;
        } 
        else 
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != nullptr) 
    {
        current->next = list1;
    } 
    else if (list2 != nullptr) 
    {
        current->next = list2;
    }

    return mergedList;
}

void printList(Node* head) 
{
    while (head != nullptr) 
    {
        st:cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() 
{
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Insert elements into the first list
    insertNode(&list1, 9);
    insertNode(&list1, 7);
    insertNode(&list1, 5);
    insertNode(&list1, 3);
    insertNode(&list1, 1);

    // Insert elements into the second list
    insertNode(&list2, 10);
    insertNode(&list2, 8);
    insertNode(&list2, 6);
    insertNode(&list2, 4);
    insertNode(&list2, 2);

    // Print the original lists
    cout << "Original List 1: ";
    printList(list1);

    cout << "Original List 2: ";
    printList(list2);

    // Merge the lists and print the result
    Node* mergedList = mergeSortedLists(list1, list2);
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
