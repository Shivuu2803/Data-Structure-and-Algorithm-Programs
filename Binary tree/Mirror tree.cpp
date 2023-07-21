#include <iostream>
using namespace std;

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

// Function to mirror a binary tree
void mirrorTree(TreeNode* root)
{
    if (root == NULL) 
    {
        return;
    }

    // Swap left and right subtrees at the current node
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Function to print the binary tree in inorder traversal
void inorderTraversal(TreeNode* root)
{
    if (root == NULL) 
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Print the original binary tree
    cout << "Original tree (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    // Mirror the binary tree
    mirrorTree(root);

    // Print the mirrored binary tree
    cout << "Mirrored tree (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    // Free memory by deleting the tree
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
