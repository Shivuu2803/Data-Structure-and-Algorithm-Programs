#include <iostream>
#include <climits>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        this->val = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Helper function to check if a binary tree is a BST
bool isBSTUtil(TreeNode* node, int minValue, int maxValue) {
    if (node == nullptr)
        return true;

    if (node->val < minValue || node->val > maxValue)
        return false;

    return isBSTUtil(node->left, minValue, node->val - 1) &&
           isBSTUtil(node->right, node->val + 1, maxValue);
}

// Function to find the largest BST in a binary tree
TreeNode* largestBSTUtil(TreeNode* node, int& maxSize, int& minValue, int& maxValue) {
    if (node == nullptr) {
        maxSize = 0;
        minValue = INT_MAX;
        maxValue = INT_MIN;
        return nullptr;
    }

    int leftSize, rightSize, leftMin, rightMin, leftMax, rightMax;
    TreeNode* largestBST = nullptr;

    bool isBST = isBSTUtil(node, INT_MIN, INT_MAX);

    if (isBST) {
        leftSize = 0;
        rightSize = 0;
        if (node->left)
            leftSize = node->left->val;
        if (node->right)
            rightSize = node->right->val;

        maxSize = 1 + leftSize + rightSize;
        largestBST = node;
    } else {
        largestBST = largestBSTUtil(node->left, leftSize, leftMin, leftMax);
        int currSize = leftSize;
        if (node->right) {
            largestBST = largestBSTUtil(node->right, rightSize, rightMin, rightMax);
            currSize += rightSize;
        }
        maxSize = currSize;
    }

    minValue = leftMin;
    maxValue = rightMax;
    return largestBST;
}

// Function to find the largest BST in a binary tree
TreeNode* largestBST(TreeNode* root) {
    int maxSize = 0, minValue, maxValue;
    return largestBSTUtil(root, maxSize, minValue, maxValue);
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);
    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(70);
    root->right->right->left = new TreeNode(65);
    root->right->right->right = new TreeNode(80);

    // Find the largest BST in the binary tree
    TreeNode* largest = largestBST(root);

    // Print the values of the largest BST
    std::cout << "Largest BST in the binary tree has root value: " << largest->val << std::endl;

    return 0;
}
