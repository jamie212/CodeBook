// Diameter: length of the longest path between any two nodes
#include "TreeNode.h"
#include <algorithm>
#include <iostream>
using namespace std;

int diameterOfBinaryTree(TreeNode* root, int& maxDiameter) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = diameterOfBinaryTree(root->left, maxDiameter);
    int rightDepth = diameterOfBinaryTree(root->right, maxDiameter);
    maxDiameter = max(maxDiameter, leftDepth + rightDepth);
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    TreeNode* root = initSimpleTree(); 
    printTree(root); 

    int maxDiameter = 0;
    diameterOfBinaryTree(root, maxDiameter);
    cout << maxDiameter << endl;
    deleteTree(root); 
    return 0;
}
