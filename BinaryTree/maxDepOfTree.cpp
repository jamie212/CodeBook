#include "TreeNode.h"
#include <algorithm>
#include <iostream>
using namespace std;

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    TreeNode* root = initSimpleTree();
    printTree(root);
    cout << maxDepth(root) << endl;
    deleteTree(root);
    return 0;
}