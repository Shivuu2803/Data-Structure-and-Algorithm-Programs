#include <iostream>
#include <queue>
#include <vector>
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

class BinaryTree
{
private:
    TreeNode* root;

public:
    // Constructor
    BinaryTree() 
    {
       this->root = NULL;
    }

    // Function to construct a binary tree from level order traversal
    void constructTree(const vector<int>& levelOrder) 
    {
        if (levelOrder.empty()) 
        {
            return;
        }

        root = new TreeNode(levelOrder[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < levelOrder.size()) 
        {
            TreeNode* curr = q.front();
            q.pop();

            if (levelOrder[i] != -1) 
            {
                curr->left = new TreeNode(levelOrder[i]);
                q.push(curr->left);
            }
            i++;

            if (i < levelOrder.size() && levelOrder[i] != -1) 
            {
                curr->right = new TreeNode(levelOrder[i]);
                q.push(curr->right);
            }
            i++;
        }
    }

    // Function to perform inorder traversal and print the binary tree
    void inorderTraversal(TreeNode* node) 
    {
        if (node != nullptr) 
        {
            inorderTraversal(node->left);
            cout << node->val << " ";
            inorderTraversal(node->right);
        }
    }

    // Wrapper function for inorder traversal
    void inorder() 
    {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main() 
{
    vector<int> levelOrder = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8};

    BinaryTree tree;

    tree.constructTree(levelOrder);

    tree.inorder();

    return 0;
}
