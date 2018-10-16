//
//  main.cpp
//  617.Merge Two Binary Trees
//
//  Created by Abysman on 2018/10/7.
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        TreeNode* m = new TreeNode(t1->val + t2->val);
        m->left = mergeTrees(t1->left, t2->left);
        m->right = mergeTrees(t1->right, t2->right);
        return m;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
