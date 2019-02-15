//
//  main.cpp
//  545.Boundary of Binary Tree
//
//  Created by Abysman on 2019/2/14.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;;

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res.push_back(root->val);
        getLeftBounds(root->left, res);
        getLeaves(root->left, res);
        getLeaves(root->right, res);
        vector<int> rightBounds;
        getRightBounds(root->right, rightBounds);
        reverse(rightBounds.begin(), rightBounds.end());
        
        for (auto rl: rightBounds) {
            res.push_back(rl);
        }
        return res;
    }
    
    void getLeftBounds(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if(!root->left && !root->right) return;
        res.push_back(root->val);
        if (root->left) getLeftBounds(root->left, res);
        else getLeftBounds(root->right, res);
    }
    
    void getLeaves(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (!root->left && !root->right) res.push_back(root->val);
        getLeaves(root->left, res);
        getLeaves(root->right, res);
    }
    
    void getRightBounds(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (!root->left && !root->right) return;
        res.push_back(root->val);
        if (root->right) getRightBounds(root->right, res);
        else getRightBounds(root->left, res);
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res.push_back(root->val);
        helper(root->left, res, true, false);
        helper(root->right, res, false, true);
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& res, bool leftBound, bool rightBound) {
        if (!root) return;
        if (leftBound) res.push_back(root->val);
        if (!root->left && !root->right && !leftBound && !rightBound) res.push_back(root->val);
        helper(root->left, res, leftBound, rightBound && !root->right);
        helper(root->right, res, leftBound && !root->left, rightBound);
        if (rightBound) res.push_back(root->val);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
