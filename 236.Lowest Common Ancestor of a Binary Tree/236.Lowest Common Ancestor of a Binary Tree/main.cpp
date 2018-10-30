//
//  main.cpp
//  236.Lowest Common Ancestor of a Binary Tree
//
//  Created by Abysman on 2018/10/30.
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if (!root || !p || !q) {
        return NULL;
    }
    
    if (root == p || root == q) {
        return root;
    }
    
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    
    if (l && r) {
        return root;
    }
    
    return l? l : r;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        TreeNode* res = helper(root, p, q);
        return res;
    }
    
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p) return p;
        if (root == q) return q;
        TreeNode* res1 = helper(root->left, p, q);
        TreeNode* res2 = helper(root->right, p, q);
        if (res1 != NULL && res2 != NULL) {
            return root;
        }
        else if (res1 != NULL) return res1;
        else if (res2 != NULL) return res2;
        else return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
