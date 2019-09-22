//
//  main.cpp
//  1145.Binary Tree Coloring Game
//
//  Created by stevenxu on 9/22/19.
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
    int l, r, val;
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x;
        helper(root);
        return max(max(l, r), n - l - r - 1) > n / 2;
    }
    
    int helper(TreeNode* root) {
        if (!root) return 0;
        int left = helper(root->left), right = helper(root->right);
        if (root->val == val) {
            l = left;
            r = right;
        }
        return helper(root->left) + helper(root->right) + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
