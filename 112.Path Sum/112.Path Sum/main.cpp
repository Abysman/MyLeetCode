//
//  main.cpp
//  112.Path Sum
//
//  Created by Abysman on 2018/4/30.
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
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, sum, 0);
    }
    bool helper(TreeNode* node, int sum, int record) {
        if  (node) {
            int temp = record + node->val;
            if (node->left == NULL && node->right == NULL) {
                if (temp == sum) {
                    return true;
                }
                return false;
            }
            else return helper(node->left, sum, temp) || helper(node->right, sum, temp);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
