#include <iostream>
#include <map>
#include <vector>
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
        this-> val = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void verticalTraversal(TreeNode* root, int level, map<int, vector<int>>& nodes) 
{
    if (!root)
    {
        return;
    }

    // Store the node's value in the map at the corresponding vertical level
    nodes[level].push_back(root->val);

    // Traverse left and right subtrees
    verticalTraversal(root->left, level - 1, nodes);
    verticalTraversal(root->right, level + 1, nodes);
}

// Function to print the vertical traversal of the BST
void printVerticalTraversal(TreeNode* root) 
{
    map<int, vector<int>> nodes;
    verticalTraversal(root, 0, nodes);

    // Print nodes at each vertical level
    for (const auto& entry : nodes) 
    {
        for (const auto& value : entry.second) 
        {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() 
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);

    cout << "Vertical Traversal:" << endl;
    printVerticalTraversal(root);

    // Clean up memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
