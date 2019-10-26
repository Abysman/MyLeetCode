//
//  main.cpp
//  1161.Maximum Level Sum of a Binary Tree
//
//  Created by stevenxu on 10/26/19.
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
    vector<int> levels;
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        helper(root, 1);
        int res = INT_MAX, maxSum = INT_MIN;
        for (int i = 0; i < levels.size(); ++i) {
            if (levels[i] > maxSum) {
                maxSum = levels[i];
                res = i + 1;
            }
        }
        return res;
    }
    
    void helper(TreeNode* root, int currLevel) {
        if (!root) return;
        if (currLevel > levels.size()) levels.push_back(0);
        levels[currLevel - 1] += root->val;
        helper(root->left, currLevel + 1);
        helper(root->right, currLevel + 1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
