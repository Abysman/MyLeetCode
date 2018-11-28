//
//  main.cpp
//  404.Sum of Left Leaves
//
//  Created by Abysman on 2018/11/28.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>
// referenced from https://leetcode.com/problems/sum-of-left-leaves/discuss/88951/3-line-recursive-c%2B%2B-solution-no-need-to-explain
//int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
//    if (!root) return 0;
//    if (!root->left && !root->right) return isleft ? root->val : 0;
//    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
//}

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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = helper(root);
        return res;
    }
    
    int helper(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right) sum += root->left->val;
            else sum += helper(root->left);
        }
        sum += helper(root->right);
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
