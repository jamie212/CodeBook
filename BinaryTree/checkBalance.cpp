#include "TreeNode.h"

int height(TreeNode* node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(TreeNode* root) {
    if (!root) return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    TreeNode* root = initSimpleTree();
    printTree(root);
    if(isBalanced(root)){
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    deleteTree(root);
    return 0;
}