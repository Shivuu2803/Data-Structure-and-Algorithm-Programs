#include <iostream>
#include <vector>
using namespace std;

class Node 
{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-order traversal of the BST and store values in a temporary array
void inorderTraversal(Node* root, vector<int>& values) 
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, values);
    values.push_back(root->data);
    inorderTraversal(root->right, values);
}

// Modify the BST to convert it to a min heap
void modifyBST(Node* root, const vector<int>& values, int& index) 
{
    if (root == nullptr)
    {
        return;
    }

    modifyBST(root->left, values, index);
    root->data = values[index++];
    modifyBST(root->right, values, index);
}

// Heapify a subtree rooted at index i in the given min heap
void heapify(Node* root) 
{
    if (root == nullptr)
    {
        return;
    }

    Node* smallest = root;
    Node* left = root->left;
    Node* right = root->right;

    if (left != nullptr && left->data < smallest->data)
    {
        smallest = left;
    }

    if (right != nullptr && right->data < smallest->data)
    {
        smallest = right;
    }

    if (smallest != root) 
    {
        swap(root->data, smallest->data);
        heapify(smallest);
    }
}

// Convert BST to min heap
void convertBSTToMinHeap(Node* root) 
{
    vector<int> values;
    inorderTraversal(root, values);

    int index = 0;
    modifyBST(root, values, index);
    heapify(root);
}

// In-order traversal of the min heap (for testing purposes)
void inorderTraversalMinHeap(Node* root) 
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversalMinHeap(root->left);
    cout << root->data << " ";
    inorderTraversalMinHeap(root->right);
}

int main() 
{
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    cout << "BST before conversion to min heap (in-order traversal): ";
    inorderTraversalMinHeap(root);
    cout << endl;

    // Convert the BST to min heap
    convertBSTToMinHeap(root);

    cout << "BST after conversion to min heap (in-order traversal): ";
    inorderTraversalMinHeap(root);
    cout << endl;

    return 0;
}
