//
//  main.cpp
//  103.Binary Tree Zigzag Level Order Traversal
//
//  Created by Abysman on 2019/2/18.
//  Copyright © 2019 Abysman. All rights reserved.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        int level = 0;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int n = dq.size();
            vector<int> curr;
            for (int i = 0; i < n; ++i) {
                TreeNode* node;
                if (level % 2 == 0) {
                    node = dq.front();
                    dq.pop_front();
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    node = dq.back();
                    dq.pop_back();
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
                curr.push_back(node->val);
            }
            res.push_back(curr);
            level++;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
