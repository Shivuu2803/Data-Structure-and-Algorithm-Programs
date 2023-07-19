#include <iostream>
#include <vector>
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

// Function to perform in-order traversal of a BST and store values in a vector
void inorderTraversal(TreeNode* root, vector<int>& nodes) 
{
    if (root == NULL) 
    {
        return;
    }
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->data);
    inorderTraversal(root->right, nodes);
}

// Function to merge two sorted arrays into a new sorted array
vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) 
{
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) 
    {
        if (arr1[i] <= arr2[j]) 
        {
            merged.push_back(arr1[i]);
            i++;
        } 
        else 
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) 
    {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) 
    {
        merged.push_back(arr2[j]);
        j++;
    }
    return merged;
}

// Function to construct a BST from a sorted array
TreeNode* constructBST(const vector<int>& sortedArray, int start, int end) {

    if (start > end) 
    {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    TreeNode* root = createNode(sortedArray[mid]);
    root->left = constructBST(sortedArray, start, mid - 1);
    root->right = constructBST(sortedArray, mid + 1, end);
    return root;
}

// Function to merge two BSTs
TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) 
{
    // Perform in-order traversal of both BSTs and obtain sorted arrays
    vector<int> arr1, arr2;
    inorderTraversal(root1, arr1);
    inorderTraversal(root2, arr2);

    // Merge the sorted arrays
    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);

    // Construct a new BST from the merged array
    return constructBST(mergedArray, 0, mergedArray.size() - 1);
}

// Main function
int main() 
{
    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;

    // Insert nodes into the first BST
    root1 = insertNode(root1, 50);
    root1 = insertNode(root1, 30);
    root1 = insertNode(root1, 70);
    root1 = insertNode(root1, 20);
    root1 = insertNode(root1, 40);
    root1 = insertNode(root1, 60);
    root1 = insertNode(root1, 80);

    // Insert nodes into the second BST
    root2 = insertNode(root2, 45);
    root2 = insertNode(root2, 35);
    root2 = insertNode(root2, 75);
    root2 = insertNode(root2, 25);
    root2 = insertNode(root2, 55);
    root2 = insertNode(root2, 85);

    // Merge the two BSTs
    TreeNode* mergedRoot = mergeBSTs(root1, root2);

    // Perform in-order traversal on the merged BST to verify the result
    vector<int> mergedArray;
    inorderTraversal(mergedRoot, mergedArray);

    // Print the merged BST nodes
    cout << "Merged BST nodes: ";
    for (int i = 0; i < mergedArray.size(); i++) 
    {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
