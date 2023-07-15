#include <iostream>
#include <unordered_map>
using namespace std;

// Binary tree node
class TreeNode 
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value)
    {
        this->val = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// Utility function to search an element in an inorder array
int search(int arr[], int start, int end, int value) 
{
    for (int i = start; i <= end; i++) 
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

// Recursive function to construct binary tree from postorder and inorder traversals
TreeNode* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int& postIndex, unordered_map<int, int>& map) 
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    // Pick the last element from the postorder traversal as the root
    int current = postorder[postIndex--];
    TreeNode* node = new TreeNode(current);

    // If this node has no children, return
    if (inStart == inEnd)
    {
        return node;
    }

    // Find the index of the root node in the inorder traversal
    int inIndex = map[current];

    // Recursive calls to build the left and right subtrees
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex, map);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex, map);

    return node;
}

// Function to build binary tree from inorder and postorder traversals
TreeNode* buildTreeFromTraversal(int inorder[], int postorder[], int size) 
{
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
        map[inorder[i]] = i;
    }

    int postIndex = size - 1;
    return buildTree(inorder, postorder, 0, size - 1, postIndex, map);
}

// Utility function to do inorder traversal of a binary tree
void inorderTraversal(TreeNode* node) 
{
    if (node == NULL)
    {
        return;
    }

    inorderTraversal(node->left);
    cout << node->val << " ";
    inorderTraversal(node->right);
}

int main() 
{
    int inorder[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int postorder[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int size = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = buildTreeFromTraversal(inorder, postorder, size);

    cout << "Inorder traversal of the constructed tree is: ";
    inorderTraversal(root);

    return 0;
}
