//
//  main.cpp
//  1214.Two Sum BSTs
//
//  Created by stevenxu on 11/1/19.
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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> tree1, tree2;
        inorderTraverse(root1, tree1);
        inorderTraverse(root2, tree2);
        int i = 0, j = tree2.size() - 1;
        while (i < tree1.size() && j >= 0) {
            int currSum = tree1[i] + tree2[j];
            if (currSum == target) return true;
            if (currSum < target) i++;
            else j--;
        }
        return false;
    }
    
    void inorderTraverse(TreeNode* root1, vector<int>& tree1) {
        if (root1 == nullptr) return;
        inorderTraverse(root1->left, tree1);
        tree1.push_back(root1->val);
        inorderTraverse(root1->right, tree1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
