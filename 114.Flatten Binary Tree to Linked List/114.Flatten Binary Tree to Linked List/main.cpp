//
//  main.cpp
//  114.Flatten Binary Tree to Linked List
//
//  Created by Abysman on 2018/7/28.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        sol(root);
    }
    
    TreeNode* sol(TreeNode* root) {
        if (!root) return NULL;
        if (!root->left && !root->right) return root;
        TreeNode* nleft = sol(root->left);
        TreeNode* nright = sol(root->right);
        if (root->left && root->right) {
            nleft->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return nright;
        }
        if (root->left) {
            root->right = root->left;
            root->left = NULL;
            return nleft;
        }
        return nright;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    n1->left = n2;
    Solution s = Solution();
    s.flatten(n1);
    
    std::cout << "Hello, World!\n";
    return 0;
}
