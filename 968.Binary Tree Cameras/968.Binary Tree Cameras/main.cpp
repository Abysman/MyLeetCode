//
//  main.cpp
//  968.Binary Tree Cameras
//
//  Created by stevenxu on 1/7/20.
//  Copyright © 2020 stevenxu. All rights reserved.
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
    int res = 0;
public:
    int minCameraCover(TreeNode* root) {
        return (helper(root) == 0 ? 1 : 0) + res;
    }
    
    int helper(TreeNode* root) {
        if (root == nullptr) return 2;
        int left = helper(root->left), right = helper(root->right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
