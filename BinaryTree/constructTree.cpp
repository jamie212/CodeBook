// construct tree from pre-order & in-order traversal
#include "TreeNode.h"
#include <vector>
#include <unordered_map>

TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) {
        return nullptr;
    }
    int rootValue = preOrder[preIndex++];
    TreeNode* root = new TreeNode(rootValue);
    if (inStart == inEnd) { // no children
        return root;
    }
    int inIndex = inOrderMap[rootValue];
    root->left = dfs(preOrder, inOrderMap, preIndex, inStart, inIndex - 1);
    root->right = dfs(preOrder, inOrderMap, preIndex, inIndex + 1, inEnd);
    return root;
}

TreeNode* constructTree(vector<int>& preOrder, vector<int>& inOrder, int& preIndex, int inStart, int inEnd) {
    unordered_map<int, int> inOrderMap;
    for (int i = 0; i < inOrder.size(); i++) {
        inOrderMap[inOrder[i]] = i;
    }
    return dfs(preOrder, inOrderMap, preIndex, inStart, inEnd);
} 

int main() {
    vector<int> preOrder = {1, 2, 4, 5, 3, 6};
    vector<int> inOrder = {4, 2, 5, 1, 3, 6};
    int preIndex = 0;
    TreeNode* root = constructTree(preOrder, inOrder, preIndex, 0, inOrder.size() - 1);
    printTree(root); 
    deleteTree(root); 
    return 0;
}