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

    // Function to check if a binary tree is a sum tree
    bool isSumTree() 
    {
        return isSumTree(root);
    }

private:
    // Recursive function to check if a binary tree is a sum tree
    bool isSumTree(TreeNode* node) 
    {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) 
        {
            return true;
        }

        // Check if the current node satisfies the sum tree property
        int leftSum = node->left ? node->left->val : 0;
        int rightSum = node->right ? node->right->val : 0;

        if (node->val == leftSum + rightSum && isSumTree(node->left) && isSumTree(node->right)) 
        {
            return true;
        }

        return false;
    }
};

int main() 
{
    BinaryTree sumTree;
    sumTree.root = new TreeNode(26);
    sumTree.root->left = new TreeNode(10);
    sumTree.root->right = new TreeNode(3);
    sumTree.root->left->left = new TreeNode(4);
    sumTree.root->left->right = new TreeNode(6);
    sumTree.root->right->right = new TreeNode(3);

    // Check if the tree is a sum tree
    bool isSumTree = sumTree.isSumTree();

    cout << "Is the binary tree a sum tree? " << (isSumTree ? "Yes" : "No") << endl;

    // Clean up memory
    delete sumTree.root->left->left;
    delete sumTree.root->left->right;
    delete sumTree.root->left;
    delete sumTree.root->right->right;
    delete sumTree.root->right;
    delete sumTree.root;

    // Create a non-sum tree
    BinaryTree nonSumTree;
    nonSumTree.root = new TreeNode(10);
    nonSumTree.root->left = new TreeNode(8);
    nonSumTree.root->right = new TreeNode(2);
    nonSumTree.root->left->left = new TreeNode(3);
    nonSumTree.root->left->right = new TreeNode(5);
    nonSumTree.root->right->right = new TreeNode(2);

    // Check if the tree is a sum tree
    isSumTree = nonSumTree.isSumTree();

    cout << "Is the binary tree a sum tree? " << (isSumTree ? "Yes" : "No") << endl;

    // Clean up memory
    delete nonSumTree.root->left->left;
    delete nonSumTree.root->left->right;
    delete nonSumTree.root->left;
    delete nonSumTree.root->right->right;
    delete nonSumTree.root->right;
    delete nonSumTree.root;

    return 0;
}
