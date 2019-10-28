//
//  main.cpp
//  145.Binary Tree Postorder Traversal
//
//  Created by stevenxu on 10/28/19.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* last;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            TreeNode* curr = s.top();
            if (curr->right && last != curr->right) {
                root = curr->right;
            } else {
                res.push_back(curr->val);
                last = curr;
                s.pop();
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
