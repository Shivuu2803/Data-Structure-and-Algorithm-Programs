#include <iostream>

using namespace std;

struct TreeNode 
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new tree node
TreeNode* createNode(int value) 
{
    TreeNode* newNode = new TreeNode;
    if (!newNode) 
    {
        cout << "Memory allocation failed!" << endl;
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
TreeNode* insertNode(TreeNode* root, int value) 
{
    if (root == NULL) 
    {
        return createNode(value);
    }
    if (value < root->data) 
    {
        root->left = insertNode(root->left, value);
    } 
    else if (value > root->data) 
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to find the kth smallest element in a BST
int kthSmallest(TreeNode* root, int k) 
{
    // Perform in-order traversal
    if (root == NULL) 
    {
        return -1; // Invalid case
    }
    int count = 0;
    int result = -1;
    TreeNode* current = root;
    
    while (current != NULL) 
    {
        if (current->left == NULL) 
        {
            count++;
            if (count == k) 
            {
                result = current->data;
            }
            current = current->right;
        } 
        else 
        {
            TreeNode* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) 
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) 
            {
                predecessor->right = current;
                current = current->left;
            } 
            else 
            {
                predecessor->right = NULL;
                count++;
                if (count == k) 
                {
                    result = current->data;
                }
                current = current->right;
            }
        }
    }
    
    return result;
}

// Main function
int main() 
{
    TreeNode* root = NULL;

    // Insert nodes into the BST
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);

    // Find the kth smallest element
    int k = 3;
    int kthSmallestElement = kthSmallest(root, k);

    if (kthSmallestElement != -1) 
    {
        cout << "The " << k << "th smallest element is: " << kthSmallestElement << endl;
    } 
    else
    {
        cout << "Invalid value of k." << endl;
    }

    return 0;
}
