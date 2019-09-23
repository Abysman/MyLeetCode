//
//  main.cpp
//  654.Maximum Binary Tree
//
//  Created by stevenxu on 9/23/19.
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> tmp;
        for (int i = 0; i < nums.size(); ++i) {
            TreeNode* curr = new TreeNode(nums[i]);
            while (!tmp.empty() && tmp.back()->val < nums[i]) {
                curr->left = tmp.back();
                tmp.pop_back();
            }
            if (!tmp.empty()) {
                tmp.back()->right = curr;
            }
            tmp.push_back(curr);
        }
        return tmp.front();
    }
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return NULL;
        TreeNode* root = helper(nums, 0, nums.size() - 1);
        return root;
    }
    
    TreeNode* helper(vector<int> nums, int start, int end) {
        if (start > end || start < 0 || end > nums.size() - 1) return NULL;
        TreeNode* root;
        if (start == end) return new TreeNode(nums[start]);
        int maxNum = INT_MIN, pos = -1;
        for (int i = start; i <= end; ++i) {
            if (nums[i] > maxNum) {
                pos = i;
                maxNum = nums[i];
            }
        }
        root = new TreeNode(maxNum);
        root->left = helper(nums, start, pos - 1);
        root->right = helper(nums, pos + 1, end);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
