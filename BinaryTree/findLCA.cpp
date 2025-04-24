#include "TreeNode.h"
#include <algorithm>
#include <iostream>
using namespace std;

TreeNode* findLCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    if (!root || root == n1 || root == n2) {
        return root;
    }
    TreeNode* left = findLCA(root->left, n1, n2);   
    TreeNode* right = findLCA(root->right, n1, n2);
    if (left && right) {
        return root; 
    }
    return left ? left : right;
}
int main() {
    TreeNode* root = initSimpleTree();
    printTree(root);
    TreeNode* n1 = root->left; // 2
    TreeNode* n2 = root->right; // 3
    TreeNode* lca = findLCA(root, n1, n2);
    if (lca) {
        cout << "LCA of " << n1->val << " and " << n2->val << " is: " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }
    deleteTree(root);
    return 0;
}