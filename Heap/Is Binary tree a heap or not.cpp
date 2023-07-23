#include <iostream>
#include <queue>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isComplete(Node* root, int index, int node_count) 
{
    // Base case: an empty tree is considered as a complete binary tree
    if (root == NULL)
    {
        return true;
    }

    // The current node should have an index less than the total number of nodes
    if (index >= node_count)
    {
        return false;
    }

    // Recursively check the completeness property for left and right subtrees
    return isComplete(root->left, 2 * index + 1, node_count) && 
           isComplete(root->right, 2 * index + 2, node_count);
}

bool isHeap(Node* root) 
{
    // Count the total number of nodes in the binary tree
    int node_count = 0;
    // Traverse the binary tree using a queue to count nodes
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) 
    {
        Node* current = q.front();
        q.pop();
        if (current != NULL)
        {
            node_count++;
            q.push(current->left);
            q.push(current->right);
        }
    }

    // Check if the binary tree is a complete binary tree
    if (!isComplete(root, 0, node_count))
    {
        return false;
    }

    // Base case: an empty tree is considered as a heap
    if (root == NULL)
    {
        return true;
    }

    // Check the heap property for the current node
    if (root->left != NULL && root->left->data > root->data)
    {
        return false;
    }
    if (root->right != NULL && root->right->data > root->data)
    {
        return false;
    }

    // Recursively check the heap property for left and right subtrees
    return isHeap(root->left) && isHeap(root->right);
}

//for not a heap
int main() 
{
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    // Check if the binary tree is a heap
    if (isHeap(root))
    {
        cout << "The binary tree is a heap" << endl;
    }
    else
    {
        cout << "The binary tree is not a heap" << endl;
    }

    return 0;
}

//for yes its a heap
// int main() 
// {
//     Node* root = createNode(90);
//     root->left = createNode(80);
//     root->right = createNode(70);
//     root->left->left = createNode(60);
//     root->left->right = createNode(50);
//     root->right->left = createNode(40);
//     root->right->right = createNode(30);

//     // Check if the binary tree is a heap
//     if (isHeap(root))
//     {
//         cout << "The binary tree is a heap" << endl;
//     }
//     else
//     {
//         cout << "The binary tree is not a heap" << endl;
//     }

//     return 0;
// }

