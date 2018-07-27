//
//  main.cpp
//  199.Binary Tree Right Side View
//
//  Created by Abysman on 2018/7/27.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        sol(res, root, 1);
        return res;
    }
    
    void sol(vector<int>& res, TreeNode* root, int flag) {
        if (!root) return;
        if (res.size() < flag) {
            res.push_back(root->val);
        }
        sol(res, root->right, flag + 1);
        sol(res, root->left, flag + 1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
