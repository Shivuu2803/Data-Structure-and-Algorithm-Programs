#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
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

// Binary Tree class
class BinaryTree 
{
public:
    TreeNode* root;

public:
    // Constructor
   BinaryTree() 
    {
       this->root = NULL;
    }

    // Function to check if the binary tree is balanced
    bool isBalanced() 
    {
        return isBalanced(root);
    }

public:
    // Recursive function to check if the binary tree is balanced
    bool isBalanced(TreeNode* node) 
    {
        if (node == NULL) 
        {
            return true;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (std::abs(leftHeight - rightHeight) > 1) 
        {
            return false;
        }

        return isBalanced(node->left) && isBalanced(node->right);
    }

    // Recursive function to calculate the height of a node
    int height(TreeNode* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main() 
{
    // Create a balanced binary tree
    BinaryTree balancedTree;
    balancedTree.root = new TreeNode(1);
    balancedTree.root->left = new TreeNode(2);
    balancedTree.root->right = new TreeNode(3);
    balancedTree.root->left->left = new TreeNode(4);
    balancedTree.root->left->right = new TreeNode(5);

    // Check if the balanced tree is balanced
    bool isBalanced = balancedTree.isBalanced();

    cout << "Is the binary tree balanced? " << (isBalanced ? "Yes" : "No") << endl;

    // Clean up memory
    delete balancedTree.root->left->left;
    delete balancedTree.root->left->right;
    delete balancedTree.root->left;
    delete balancedTree.root->right;
    delete balancedTree.root;

    // Create an unbalanced binary tree
    BinaryTree unbalancedTree;
    unbalancedTree.root = new TreeNode(1);
    unbalancedTree.root->left = new TreeNode(2);
    unbalancedTree.root->left->left = new TreeNode(3);

    // Check if the unbalanced tree is balanced
    isBalanced = unbalancedTree.isBalanced();

    cout << "Is the binary tree balanced? " << (isBalanced ? "Yes" : "No") << endl;

    // Clean up memory
    delete unbalancedTree.root->left->left;
    delete unbalancedTree.root->left;
    delete unbalancedTree.root;

    return 0;
}
