//
//  main.cpp
//  333.Largest BST Subtree
//
//  Created by stevenxu on 11/4/19.
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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        TreeNode *minNode = nullptr, *maxNode = nullptr;
        helper(root, minNode, maxNode, res);
        return res;
    }
    
    int helper(TreeNode* root, TreeNode* &minNode, TreeNode* &maxNode, int& res) {
        if (!root) return 0;
        TreeNode *leftMinNode = nullptr, *leftMaxNode = nullptr;
        TreeNode *rightMinNode = nullptr, *rightMaxNode = nullptr;
        
        int left = helper(root->left, leftMinNode, leftMaxNode, res);
        int right = helper(root->right, rightMinNode, rightMaxNode, res);
        int curr = 0;
        
        if (left > 0) minNode = leftMinNode;
        else minNode = root;
        
        if (right > 0) maxNode = rightMaxNode;
        else maxNode = root;
        
        if (left != -1 && right != -1 && (leftMaxNode == nullptr || leftMaxNode->val < root->val) && (rightMinNode == nullptr || rightMinNode->val > root->val)) {
            curr = 1 + left + right;
            res = max(curr, res);
            return curr;
        } else {
            return -1;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
