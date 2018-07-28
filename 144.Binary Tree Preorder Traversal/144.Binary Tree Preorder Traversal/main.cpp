//
//  main.cpp
//  144.Binary Tree Preorder Traversal
//
//  Created by Abysman on 2018/7/28.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        sol(root, res);
        return res;
    }
    
    //  iterative
    vector<int> preorderTraversal_iterative(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> res;
        stack<TreeNode* > TreeNodeStack;
        TreeNodeStack.push(root);
        while (!TreeNodeStack.empty()) {
            TreeNode* curr = TreeNodeStack.top();
            res.push_back(curr->val);
            TreeNodeStack.pop();
            if (!curr->right) TreeNodeStack.push(curr->right);
            if (!curr->left) TreeNodeStack.push(curr->left);
        }
        return res;
    }
    
    // recursive
    void sol(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        sol(root->left, res);
        sol(root->right, res);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
