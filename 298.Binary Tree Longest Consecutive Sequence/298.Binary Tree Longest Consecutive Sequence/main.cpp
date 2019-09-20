//
//  main.cpp
//  298.Binary Tree Longest Consecutive Sequence
//
//  Created by stevenxu on 9/20/19.
//  Copyright © 2019 stevenxu. All rights reserved.
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
    int longestConsecutive(TreeNode* root) {
        return helper(root, NULL, 0);
    }
    
    int helper(TreeNode* root, TreeNode* prev, int curr) {
        if (!root) return curr;
        curr = (prev && root->val == prev->val + 1) ? curr + 1 : 1;
        return max(curr, max(helper(root->left, root, curr), helper(root->right, root, curr)));
    }
};


class Solution {
    int res = 0;
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        helper(root, INT_MIN, 1);
        return res;
    }
    
    void helper(TreeNode* root, int prev, int curr) {
        if (root) {
            if (!root->left && !root->right) res = max(res, curr);
            curr = (root->val == prev + 1) ? curr + 1 : 1;
            res = max(curr, res);
            helper(root->left, root->val, curr);
            helper(root->right, root->val, curr);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
