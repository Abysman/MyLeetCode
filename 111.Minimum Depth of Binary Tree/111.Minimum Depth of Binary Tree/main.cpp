//
//  main.cpp
//  111.Minimum Depth of Binary Tree
//
//  Created by Abysman on 2018/7/27.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return sol(root);
    }
    
    int sol(TreeNode* root) {
        if (!root) {
            return INT_MAX;
        }
        if (root->left || root->right) {
            return min(sol(root->left), sol(root->right))  + 1;
        }
        return 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    root->left = a;
    Solution sol = Solution();
    cout << sol.minDepth(root);
    return 0;
}
