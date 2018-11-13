//
//  main.cpp
//  700.Search in a Binary Search Tree
//
//  Created by Abysman on 2018/11/13.
//  Copyright © 2018 Abysman. All rights reserved.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root ) return NULL;
        TreeNode* res;
        if (val == root->val) return root;
        else if (val < root->val) res = searchBST(root->left, val);
        else if (val > root->val) res = searchBST(root->right, val);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
