#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list
struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to check if a linked list is a palindrome
bool isPalindrome(ListNode* head) 
{
    // Handle empty list or single node list
    if (head == nullptr || head->next == nullptr) 
    {
        return true;
    }

    // Find the middle of the list
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    while (curr != nullptr) 
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare the first and second halves of the list
    ListNode* p1 = head;
    ListNode* p2 = prev;
    while (p2 != nullptr) 
    {
        if (p1->val != p2->val) 
        {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

// Function to print the linked list
void printList(ListNode* head) 
{
    ListNode* curr = head;
    while (curr != nullptr) 
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() 
{
    // Create a palindrome linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    // Check if the linked list is a palindrome
    bool isPal = isPalindrome(head);

    // Print the result
    if (isPal) 
    {
        cout << "The linked list is a palindrome." << endl;
    } else 
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
