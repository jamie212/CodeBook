#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode* left, TreeNode* right);
};

TreeNode* initSimpleTree();
void printTree(TreeNode* root);
void deleteTree(TreeNode* root);

#endif 