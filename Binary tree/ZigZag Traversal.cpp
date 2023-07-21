#include <iostream>
#include <queue>
#include <stack>
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

    // Function to perform zigzag tree traversal
    void zigzagTraversal() 
    {
        if (root == NULL) 
        {
            return;
        }

        stack<TreeNode*> currentLevel;
        stack<TreeNode*> nextLevel;

        currentLevel.push(root);
        bool leftToRight = true;

        while (!currentLevel.empty()) 
        {
            TreeNode* node = currentLevel.top();
            currentLevel.pop();

            if (node) 
            {
                cout << node->val << " ";

                if (leftToRight) 
                {
                    if (node->left) 
                    {
                        nextLevel.push(node->left);
                    }
                    if (node->right)
                    {
                        nextLevel.push(node->right);
                    }
                } 
                else
                {
                    if (node->right) 
                    {
                        nextLevel.push(node->right);
                    }
                    if (node->left) 
                    {
                        nextLevel.push(node->left);
                    }
                }
            }

            if (currentLevel.empty()) 
            {
                swap(currentLevel, nextLevel);
                leftToRight = !leftToRight;
            }
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(6);
    tree.root->right->right = new TreeNode(7);

    // Perform zigzag tree traversal
    cout << "Zigzag tree traversal: ";
    tree.zigzagTraversal();
    cout << endl;

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
