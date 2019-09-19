//
//  main.cpp
//  250.Count Univalue Subtrees
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
    int res = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        helper(root, 0);
        return res;
    }
    
    bool helper(TreeNode* root, int givenVal) {
        if (!root) return true;
        if (!helper(root->left, root->val) | !helper(root->right, root->val)) return false;
        res++;
        return root->val == givenVal;
    }
};

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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    
    bool helper(TreeNode* root, int& res) {
        if (!root) return false;
        if (!root->left && !root->right) {
            res += 1;
            return true;
        } else {
            bool leftShouldPlusOne= helper(root->left, res);
            bool rightShouldPlusOne = helper(root->right, res);
            if (root->left && root->right && leftShouldPlusOne && rightShouldPlusOne && root->left->val == root->right->val && root->left->val == root->val) {
                res += 1;
                return true;
            } else if (leftShouldPlusOne && root->left && root->left->val == root->val && !root->right) {
                res += 1;
                return true;
            } else if (rightShouldPlusOne && root->right && root->right->val == root->val && !root->left) {
                res += 1;
                return true;
            } else return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
