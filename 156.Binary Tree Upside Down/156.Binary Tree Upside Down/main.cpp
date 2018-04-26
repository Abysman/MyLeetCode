//
//  main.cpp
//  156.Binary Tree Upside Down
//
//  Created by Abysman on 2018/4/20.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

/*
 *  分治
 *  二分法
 */

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        return toBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* toBST(vector<int>&nums, int start, int end) {
        if (start == end) {
            return new TreeNode(nums[start]);
        }
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = toBST(nums, start, mid - 1);
        root->right = toBST(nums, mid + 1, end);
        
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol = Solution();
    vector<int> nums = {-10,-3,0,5,9};
    sol.sortedArrayToBST(nums);
    return 0;
}
