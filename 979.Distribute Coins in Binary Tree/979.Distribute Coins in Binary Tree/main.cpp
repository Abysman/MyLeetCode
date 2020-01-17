//
//  main.cpp
//  979.Distribute Coins in Binary Tree
//
//  Created by stevenxu on 1/16/20.
//  Copyright © 2020 stevenxu. All rights reserved.
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
    int distributeCoins(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* root, int &res) {
        if (root == nullptr) return 0;
        int left = helper(root->left, res), right = helper(root->right, res);
        res += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
