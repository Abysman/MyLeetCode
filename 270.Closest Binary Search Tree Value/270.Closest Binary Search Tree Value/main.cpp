//
//  main.cpp
//  270.Closest Binary Search Tree Value
//
//  Created by Abysman on 2018/11/7.
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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        helper(root, target, res);
        return res;
    }
    
    void helper(TreeNode* root, double target, int& res) {
        if (!root) return;
        if (abs(root->val - target) < abs(res - target)) {
            res = root->val;
        }
        helper(root->left, target, res);
        helper(root->right, target ,res);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 3;
    std::cout << (a-2.7) << 3;
    std::cout << "Hello, World!\n";
    return 0;
}
