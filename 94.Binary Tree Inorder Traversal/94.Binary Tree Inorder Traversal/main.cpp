//
//  main.cpp
//  94.Binary Tree Inorder Traversal
//
//  Created by Abysman on 2018/8/3.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return vector<int> ();
        vector<int> res;
        stack<TreeNode* > nodeStack;
        TreeNode* curr = root;
        
        while (curr != NULL || !nodeStack.empty()) {
            while (curr) {
                nodeStack.push(curr);
                curr = curr->left;
            }
            TreeNode* tmp = nodeStack.top();
            res.push_back(tmp->val);
            nodeStack.pop();
            curr = tmp->right;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
