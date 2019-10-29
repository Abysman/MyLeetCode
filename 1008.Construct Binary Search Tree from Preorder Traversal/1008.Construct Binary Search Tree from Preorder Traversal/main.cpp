//
//  main.cpp
//  1008.Construct Binary Search Tree from Preorder Traversal
//
//  Created by stevenxu on 10/29/19.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
        return helper(preorder, 0, n - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;
        TreeNode* root = new TreeNode(preorder[start]);
        if (start == end) return root;
        int index = -1;
        for (int i = start; i <= end; ++i) {
             if (preorder[i] > preorder[start]) {
                 index = i;
                 break;
             }
        }
        index = index == -1 ? end : index - 1;
        root->left = helper(preorder, start + 1, index);
        root->right = helper(preorder, index + 1, end);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
