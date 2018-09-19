//
//  main.cpp
//  235.Lowest Common Ancestor of a Binary Search Tree
//
//  Created by Abysman on 2018/9/19.
//  Copyright © 2018年 Abysman. All rights reserved.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while (curr) {
            if ((p->val < curr->val) && (q->val < curr->val)) {
                curr = curr->left;
            }
            else if ((p->val > curr->val) && (q->val > curr->val)) {
                curr = curr->right;
            }
            else return curr;
        }
        return curr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
