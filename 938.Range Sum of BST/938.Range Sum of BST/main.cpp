//
//  main.cpp
//  938.Range Sum of BST
//
//  Created by stevenxu on 11/20/19.
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr) return 0;
        if (root->val >= L && root->val <= R) {
            return root->val + rangeSumBST(root->left, L, root->val) + rangeSumBST(root->right, root->val, R);
        } else if (root->val < L) {
            return rangeSumBST(root->right, L, R);
        } else {
            return rangeSumBST(root->left, L, R);
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
