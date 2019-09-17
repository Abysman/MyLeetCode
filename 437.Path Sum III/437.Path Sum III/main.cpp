//
//  main.cpp
//  437.Path Sum III
//
//  Created by stevenxu on 9/17/19.
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
//  continuous subarray equals K
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int total = 0;
        unordered_map<int, int> m;
        m[0]++;
        helper(root, sum, 0, m, total);
        return total;
    }
    
    void helper(TreeNode* root, int sum, int currSum, unordered_map<int, int>& m, int& total) {
        if (!root) return;
        currSum += root->val;
        total += m[currSum - sum];
        m[currSum] += 1;
        helper(root->left, sum, currSum, m, total);
        helper(root->right, sum, currSum, m, total);
        m[currSum] -= 1;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return pathSum(root->left, sum) + pathSum(root->right, sum) + helper(root, sum);
    }
    
    int helper(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = (root->val == sum) ? 1 : 0;
        res += helper(root->left, sum - root->val) + helper(root->right, sum - root->val);
        return res;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
