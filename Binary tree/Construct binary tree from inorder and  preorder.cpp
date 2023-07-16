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

TreeNode* constructTree(int inorder[], int preorder[], int inStart, int inEnd, int& preIndex) 
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    int currData = preorder[preIndex++];
    TreeNode* newNode = new TreeNode(currData);

    if (inStart == inEnd)
    {
        return newNode;
    }

    int inIndex;
    for (int i = inStart; i <= inEnd; i++) 
    {
        if (inorder[i] == currData) 
        {
            inIndex = i;
            break;
        }
    }

    newNode->left = constructTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    newNode->right = constructTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return newNode;
}

TreeNode* buildTree(int inorder[], int preorder[], int size) 
{
    int preIndex = 0;
    return constructTree(inorder, preorder, 0, size - 1, preIndex);
}

void inorderTraversal(TreeNode* node) 
{
    if (node == NULL)
    {
        return;
    }

    inorderTraversal(node->left);
    cout << node->val << " ";
    inorderTraversal(node->right);
}

int main() 
{
    int inorder[] = { 4, 2, 5, 1, 6, 3 };
    int preorder[] = { 1, 2, 4, 5, 3, 6 };

    int size = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = buildTree(inorder, preorder, size);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);

    return 0;
}
