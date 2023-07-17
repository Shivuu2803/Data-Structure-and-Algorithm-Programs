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

    // Function to calculate the diameter of the binary tree
    int diameter() 
    {
        return diameter(root);
    }

public:
    // Recursive function to calculate the diameter of the binary tree
    int diameter(TreeNode* node) 
    {
        if (node == NULL) 
        {
            return 0;
        }

        // Calculate the height of the left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Calculate the diameter recursively for left and right subtrees
        int leftDiameter = diameter(node->left);
        int rightDiameter = diameter(node->right);

        // Return the maximum of the following:
        // 1. Diameter of the left subtree
        // 2. Diameter of the right subtree
        // 3. Longest path passing through the root (height of left subtree + height of right subtree + 1)
        return max({ leftDiameter, rightDiameter, leftHeight + rightHeight + 1 });
    }

    // Recursive function to calculate the height of a node
    int height(TreeNode* node) 
    {
        if (node == NULL) 
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
    // Create a binary tree
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(6);
    tree.root->right->right = new TreeNode(7);

    // Calculate the diameter of the binary tree
    int treeDiameter = tree.diameter();

    cout << "Diameter of the binary tree: " << treeDiameter << endl;

    // Clean up memory
    delete tree.root->left->left;
    delete tree.root->left->right;
    delete tree.root->right->left;
    delete tree.root->right->right;
    delete tree.root->left;
    delete tree.root->right;
    delete tree.root;

    return 0;
}
