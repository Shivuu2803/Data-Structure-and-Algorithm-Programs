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
    newNode->left = NULL;
    newNode->right = NULL;
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

// Function to search for a node in the BST
TreeNode* searchNode(TreeNode* root, int value) 
{
    if (root == NULL || root->data == value) 
    {
        return root;
    }
    if (value < root->data) 
    {
        return searchNode(root->left, value);
    }
    return searchNode(root->right, value);
}

// Function to find the minimum value node in the BST
TreeNode* findMinimum(TreeNode* node) 
{
    TreeNode* current = node;
    while (current && current->left != NULL) 
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int value) 
{
    if (root == NULL) 
    {
        return root;
    }
    if (value < root->data) 
    {
        root->left = deleteNode(root->left, value);
    } 
    else if (value > root->data) 
    {
        root->right = deleteNode(root->right, value);
    } 
    else 
    {
        // Node found, perform deletion
        if (root->left == NULL) 
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) 
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Node has two children
        TreeNode* temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(TreeNode* root) 
{
    if (root == NULL) 
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Main function
int main() 
{
    TreeNode* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "In-order traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    int searchValue = 40;
    TreeNode* searchResult = searchNode(root, searchValue);

}
