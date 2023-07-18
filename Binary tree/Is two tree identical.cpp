#include <iostream>
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

    // Function to check if two binary trees are identical
    bool isIdentical(BinaryTree& otherTree) 
    {
        return isIdentical(root, otherTree.root);
    }

public:
    // Recursive function to check if two binary trees are identical
    bool isIdentical(TreeNode* node1, TreeNode* node2) 
    {
        if (node1 == nullptr && node2 == nullptr) 
        {
            return true;
        }

        if (node1 == nullptr || node2 == nullptr) 
        {
            return false;
        }

        return (node1->val == node2->val) &&
            isIdentical(node1->left, node2->left) &&
            isIdentical(node1->right, node2->right);
    }
};

int main() 
{
    // Create the first binary tree
    BinaryTree tree1;
    tree1.root = new TreeNode(1);
    tree1.root->left = new TreeNode(2);
    tree1.root->right = new TreeNode(3);
    tree1.root->left->left = new TreeNode(4);
    tree1.root->left->right = new TreeNode(5);

    // Create the second binary tree
    BinaryTree tree2;
    tree2.root = new TreeNode(1);
    tree2.root->left = new TreeNode(2);
    tree2.root->right = new TreeNode(3);
    tree2.root->left->left = new TreeNode(4);
    tree2.root->left->right = new TreeNode(5);

    // Check if the two trees are identical
    bool isIdentical = tree1.isIdentical(tree2);

    cout << "Are the two binary trees identical? " << (isIdentical ? "Yes" : "No") << endl;

    // Clean up memory
    delete tree1.root->left->left;
    delete tree1.root->left->right;
    delete tree1.root->left;
    delete tree1.root->right;
    delete tree1.root;

    delete tree2.root->left->left;
    delete tree2.root->left->right;
    delete tree2.root->left;
    delete tree2.root->right;
    delete tree2.root;

    return 0;
}
