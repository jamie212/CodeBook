#include "TreeNode.h"

void inOrder(TreeNode* root){
    if(!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
void preOrder(TreeNode* root){
    if(!root) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(TreeNode* root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main(){
    TreeNode* root = initSimpleTree();
    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;
    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;
    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;
    // Clean up memory
    deleteTree(root);
    return 0;
}