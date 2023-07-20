#include <iostream>
#include <climits>
using namespace std;

class TreeNode 
{
    public:
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

// Function to insert a node in the binary tree
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

// Function to check if a binary tree is a valid BST
bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) 
{
    if (root == NULL) 
    {
        return true;
    }
    if (root->data <= minVal || root->data >= maxVal) 
    {
        return false;
    }
    return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
}

int main() 
{
    TreeNode* root = NULL;

    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);

    // Check if the binary tree is a valid BST
    if (isValidBST(root)) 
    {
        cout << "The binary tree is a valid BST." << endl;
    } 
    else 
    {
        cout << "The binary tree is not a valid BST." << endl;
    }

    return 0;
}
