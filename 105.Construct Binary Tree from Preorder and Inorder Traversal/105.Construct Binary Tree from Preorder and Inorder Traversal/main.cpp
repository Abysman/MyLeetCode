//
//  main.cpp
//  105.Construct Binary Tree from Preorder and Inorder Traversal
//
//  Created by Abysman on 2018/9/19.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

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
    unordered_map<int, int> record;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) return nullptr;
        for (int i = 0; i < inorder.size(); ++i) record[inorder[i]] = i;
        int n = preorder.size();
        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pL, int pR, int iL, int iR) {
        if ((pL > pR) || (iL > iR)) return nullptr;
        TreeNode* root = new TreeNode(preorder[pL]);
        int index = record[preorder[pL]];
        root->left = helper(preorder, inorder, pL + 1, pL + index - iL, iL, index - 1);
        root->right = helper(preorder, inorder, pL + index -iL + 1, pR, index + 1, iR);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
