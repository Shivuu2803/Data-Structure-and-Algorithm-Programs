#include <iostream>
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

// Function to find the predecessor and successor in a BST
void findPredecessorSuccessor(TreeNode* root, TreeNode*& predecessor, TreeNode*& successor, int key) 
{
    if (root == NULL) 
    {
        return;
    }
    if (root->data == key) 
    {
        // If the key is found
        if (root->left != NULL) 
        {
            // Find the maximum value in the left subtree (predecessor)
            TreeNode* temp = root->left;
            while (temp->right != NULL) 
            {
                temp = temp->right;
            }
            predecessor = temp;
        }
        if (root->right != NULL) 
        {
            // Find the minimum value in the right subtree (successor)
            TreeNode* temp = root->right;
            while (temp->left != NULL) 
            {
                temp = temp->left;
            }
            successor = temp;
        }
        return;
    }
    if (key < root->data) 
    {
        // If key is less than the current node, move to the left subtree
        successor = root;
        findPredecessorSuccessor(root->left, predecessor, successor, key);
    } 
    else 
    {
        // If key is greater than the current node, move to the right subtree
        predecessor = root;
        findPredecessorSuccessor(root->right, predecessor, successor, key);
    }
}

int main() 
{
    TreeNode* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    int key = 60;
    TreeNode* predecessor = NULL;
    TreeNode* successor = NULL;

    // Find the predecessor and successor of the given key
    findPredecessorSuccessor(root, predecessor, successor, key);

    cout << "Predecessor: ";
    if (predecessor != NULL) 
    {
        cout << predecessor->data;
    } 
    else 
    {
        cout << "NULL";
    }
    cout << endl;

    cout << "Successor: ";
    if (successor != NULL) 
    {
        cout << successor->data;
    } 
    else 
    {
        cout << "NULL";
    }
    cout << endl;

    return 0;
}

