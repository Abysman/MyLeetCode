//
//  main.cpp
//  337.House Robber III
//
//  Created by stevenxu on 12/4/19.
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        auto res = helper(root);
        return max(res.first, res.second);
    }
    
    pair<int, int> helper(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto left = helper(root->left), right = helper(root->right);
        int included = root->val + left.second + right.second;
        int absent = max(left.first, left.second) + max(right.first, right.second);
        return {included, absent};
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
