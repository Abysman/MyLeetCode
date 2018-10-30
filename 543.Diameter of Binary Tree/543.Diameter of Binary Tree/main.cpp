//
//  main.cpp
//  543.Diameter of Binary Tree
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

//  optimized
//*/
//class Solution {
//public:
//    int diameterOfBinaryTree(TreeNode* root) {
//        int diameter = 0;
//        height(root, diameter);
//        return diameter;
//    }
//private:
//    int height(TreeNode* node, int& diameter) {
//        if (!node) {
//            return 0;
//        }
//        int lh = height(node->left, diameter);
//        int rh = height(node->right, diameter);
//        diameter = max(diameter, lh + rh);
//        return 1 + max(lh, rh);
//    }
//};


//  mine
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root, 0);
        return res;
    }
    
    int helper(TreeNode* root, int depth) {
        if (!root) return depth - 1;
        int leftDepth = helper(root->left, depth + 1);
        int rightDepth = helper(root->right, depth + 1);
        int maxDepth = max(leftDepth, rightDepth);
        res = max(res, leftDepth + rightDepth - 2 * depth);
        return maxDepth;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
