//
//  main.cpp
//  156.Binary Tree Upside Down
//
//  Created by stevenxu on 11/30/19.
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr || root->left == nullptr) return root;
        TreeNode *left = root->left, *right = root->right;
        TreeNode *new_root = upsideDownBinaryTree(root->left);
        left->right = root;
        left->left = right;
        root->left = nullptr;
        root->right = nullptr;
        return new_root;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
