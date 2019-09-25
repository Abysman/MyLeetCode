//
//  main.cpp
//  1110.Delete Nodes And Return Forest
//
//  Created by stevenxu on 9/25/19.
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
    unordered_set<int> s;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        if (!root) return res;
        for (int val: to_delete) s.insert(val);
        helper(res, root, true);
        return res;
    }
    
    bool helper(vector<TreeNode*> &res, TreeNode* root, bool lastDeleted) {
        if (!root) return true;
        bool deleted = false;
        if (s.find(root->val) != s.end()) {
            lastDeleted = true;
            deleted = true;
        } else {
            if (lastDeleted) res.push_back(root);
            lastDeleted = false;
        }
        bool left = helper(res, root->left, lastDeleted);
        bool right = helper(res, root->right, lastDeleted);
        if (left) root->left = NULL;
        if (right) root->right = NULL;
        return deleted;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
