//
//  main.cpp
//  124.Binary Tree Maximum Path Sum
//
//  Created by Abysman on 2019/2/15.
//  Copyright © 2019 Abysman. All rights reserved.
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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* root, int &res) {
        if (!root) return 0;
        int left = max(0, helper(root->left, res));
        int right = max(0, helper(root->right, res));
        res = max(res, root->val + left + right);
        return max(left, right) + root->val;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
