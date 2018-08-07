//
//  main.cpp
//  110.Balanced Binary Tree
//
//  Created by Abysman on 2018/8/7.
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

//  bottom-up
class solution {
public:
    int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }
};

//  my top-down O(n^2) 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return sol(root);
    }
    
    int depth(TreeNode* root) {
        if (!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    
    bool sol(TreeNode* root) {
        if (!root) return true;
        if (isBalanced(root->left) && isBalanced(root->right)) {
            if ((depth(root->left) - depth(root->right) <= 1) && (depth(root->left) - depth(root->right) >= -1 )) {
                return true;
            }
            else return false;
        }
        else return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
