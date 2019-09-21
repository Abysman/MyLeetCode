//
//  main.cpp
//  549.Binary Tree Longest Consecutive Sequence II
//
//  Created by stevenxu on 9/20/19.
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
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        dfs(root, root, longest);
        return longest;
    }
    
    pair<int, int> dfs(TreeNode * node, TreeNode * parent, int & longest) {
        if ( NULL == node ) {
            return make_pair(0, 0);
        }
        auto left = dfs(node->left, node, longest);
        auto right = dfs(node->right, node, longest);
        longest = max(longest, left.first + right.second + 1);
        longest = max(longest, left.second + right.first + 1);
        int inc = 0, dec = 0;
        if ( node->val == parent->val + 1 ) {
            inc = max(left.first, right.first) + 1;
        }
        if ( node->val == parent->val - 1 ) {
            dec = max(left.second, right.second) + 1;
        }
        return make_pair(inc, dec);
    }
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int left = helper(root->left, root, true) + helper(root->right, root, false) + 1;
        int right = helper(root->left, root, false) + helper(root->right, root, true) + 1;
        int curr = max(left, right);
        int child = max(longestConsecutive(root->left), longestConsecutive(root->right));
        return max(curr, child);
    }
    
    int helper(TreeNode* root, TreeNode* prev, bool increasing) {
        if (!root) return 0;
        if (increasing && root->val == prev->val + 1 ||
            !increasing && root->val == prev->val - 1)
            return max(helper(root->left, root, increasing), helper(root->right, root, increasing)) + 1;
        else {
            return 0;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
