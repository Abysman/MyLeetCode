//
//  main.cpp
//  513.Find Bottom Left Tree Value
//
//  Created by stevenxu on 9/15/19.
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
    void findBottomLeftValue(TreeNode* root, int& maxDepth, int& leftVal, int depth) {
        if (root == NULL) {
            return;
        }
        //Go to the left and right of each node
        findBottomLeftValue(root->left, maxDepth, leftVal, depth+1);
        findBottomLeftValue(root->right, maxDepth, leftVal, depth+1);
        
        //Update leftVal and maxDepth
        if (depth > maxDepth) {
            maxDepth = depth;
            leftVal = root->val;
        }
    }
    
    //Entry function
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        //Initialize leftVal with root's value to cover the edge case with single node
        int leftVal = root->val;
        findBottomLeftValue(root, maxDepth, leftVal, 0);
        return leftVal;
    }
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> record;
        helper(root, 1, record);
        return record[record.size() - 1][0];
    }
    
    void helper(TreeNode* root, int row, vector<vector<int>>& record) {
        if (!root) return;
        if (row > record.size()) record.resize(row);
        record[row - 1].push_back(root->val);
        if (root->left) {
            helper(root->left, row + 1, record);
        }
        if (root->right) {
            helper(root->right, row + 1, record);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
