//lowest common ancesstor

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

// Function to find the LCA of two nodes in a BST
TreeNode* findLCA(TreeNode* root, int node1, int node2) 
{
    if (root == NULL) 
    {
        return NULL;
    }
    if (node1 < root->data && node2 < root->data) 
    {
        return findLCA(root->left, node1, node2);
    } 
    else if (node1 > root->data && node2 > root->data) 
    {
        return findLCA(root->right, node1, node2);
    } 
    else 
    {
        return root;
    }
}

// Main function
int main() 
{
    TreeNode* root = NULL;

    // Insert nodes into the BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    int node1 = 20;
    int node2 = 40;

    // Find the LCA of the given nodes
    TreeNode* lca = findLCA(root, node1, node2);

    cout << "LCA: ";
    if (lca != NULL)
    {
        cout << lca->data;
    } 
    else 
    {
        cout << "NULL";
    }
    cout << endl;

    return 0;
}
