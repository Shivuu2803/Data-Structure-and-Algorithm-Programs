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

    // Function to calculate the height of the binary tree
    int height() 
    {
        return height(root);
    }

public:
    // Recursive function to calculate the height of the binary tree
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
    // Create a binary tree
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(6);
    tree.root->right->right = new TreeNode(7);

    // Calculate the height of the binary tree
    int treeHeight = tree.height();

    cout << "Height of the binary tree: " << treeHeight << endl;

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
