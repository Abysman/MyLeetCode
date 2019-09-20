//
//  main.cpp
//  687.Longest Univalue Path
//
//  Created by stevenxu on 9/19/19.
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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        if (root) helper(root, res);
        return res;
    }
    
    int helper(TreeNode* root, int& res) {
        int l = root->left ? helper(root->left, res) : 0;
        int r = root->right ? helper(root->right, res) : 0;
        int resl = root->left && root->left->val == root->val ? l + 1 : 0;
        int resr = root->right && root->right->val == root->val ? r + 1 : 0;
        res = max(res, resl + resr);
        return max(resl, resr);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
