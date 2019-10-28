//
//  main.cpp
//  450.Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left) {
                TreeNode* res = root->right;
                delete root;
                return res;
            } else if (!root->right) {
                TreeNode* res = root->left;
                delete  root;
                return res;
            } else {
                TreeNode* curr = root->right;
                while (curr->left) {
                   curr = curr->left;
                }
                root->val = curr->val;
                root->right = deleteNode(root->right, curr->val);
            }
            
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
