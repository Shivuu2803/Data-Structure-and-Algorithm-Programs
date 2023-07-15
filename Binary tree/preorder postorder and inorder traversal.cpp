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
private:
    TreeNode* root;

    // Private helper functions for preorder, inorder, and postorder traversal
    void preorderTraversal(TreeNode* node) 
    {
        if (node != NULL) 
        {
            cout << node->val << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void inorderTraversal(TreeNode* node) {
        if (node != NULL) 
        {
            inorderTraversal(node->left);
            cout << node->val << " ";
            inorderTraversal(node->right);
        }
    }

    void postorderTraversal(TreeNode* node) 
    {
        if (node != NULL) 
        {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->val << " ";
        }
    }

public:
    // Constructor
    BinaryTree() 
    {
       this->root = NULL;
    }

    // Method to set the root node
    void setRoot(TreeNode* node)
    {
        root = node;
    }

    // Public methods for preorder, inorder, and postorder traversal
    void preorder() 
    {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    void inorder() 
    {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void postorder() 
    {
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() 
{
    BinaryTree tree;

    // Creating nodes for the binary tree
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(9);

    // Building the binary tree
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    // Set the root node
    tree.setRoot(node1);

    // Perform different traversals
    tree.preorder();
    tree.inorder();
    tree.postorder();

    // Clean up memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;

    return 0;
}
