#include <iostream>
#include <unordered_map>
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
        this->val = value;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTreeHelper(const vector<int>& inorder, const vector<int>& postorder,
                          int inStart, int inEnd, int postStart, int postEnd,
                          unordered_map<int, int>& indexMap)
{
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    int rootValue = postorder[postEnd];
    TreeNode* root = new TreeNode(rootValue);

    int rootIndex = indexMap[rootValue];
    int leftSubtreeSize = rootIndex - inStart;

    root->left = buildTreeHelper(inorder, postorder, inStart, rootIndex - 1,
                                 postStart, postStart + leftSubtreeSize - 1, indexMap);
    root->right = buildTreeHelper(inorder, postorder, rootIndex + 1, inEnd,
                                  postStart + leftSubtreeSize, postEnd - 1, indexMap);

    return root;
}

TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder)
{
    unordered_map<int, int> indexMap;
    for (int i = 0; i < inorder.size(); i++)
        indexMap[inorder[i]] = i;

    int n = inorder.size();
    return buildTreeHelper(inorder, postorder, 0, n - 1, 0, n - 1, indexMap);
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(TreeNode* root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
