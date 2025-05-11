#include <iostream>
#include "TreeNode.h"
using namespace std;

bool checkTree(TreeNode* p, TreeNode* q){
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p->val != q->val) return false;
    return checkTree(p->left, q->left) && checkTree(p->right, q->right);
}
bool findSameRoot(TreeNode* root, TreeNode* subRoot){
    if(!root) return false;
    if(root->val == subRoot->val && checkTree(root, subRoot)){
        return true;
    }
    return findSameRoot(root->left, subRoot) || findSameRoot(root->right, subRoot);
    
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    return findSameRoot(root, subRoot);
}
int main() {
    TreeNode* root = initSimpleTree();
    TreeNode* subRoot = new TreeNode(2);
    subRoot->left = new TreeNode(4);
    subRoot->right = new TreeNode(5);
    printTree(root);
    printTree(subRoot);
    if(isSubtree(root, subRoot)){
        cout << "Is subtree." << endl;
    } else {
        cout << "Not subtree." << endl;
    }
    deleteTree(root);
    deleteTree(subRoot);
    return 0;
}