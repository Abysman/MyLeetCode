//
//  main.cpp
//  106.Construct Binary Tree from Inorder and Postorder Traversal
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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || (inorder.size() != postorder.size())) return NULL;
        TreeNode* root = helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int pS, int pE) {
        if (inS > inE || pS > pE) return NULL;
        
        TreeNode* currNode = new TreeNode(postorder[pE]);
        
        for (int i = inS; i <= inE; ++i) {
            if (inorder[i] == postorder[pE]) {
                currNode->left = helper(inorder, postorder, inS, i - 1, pS, pS + i - inS - 1);
                currNode->right = helper(inorder, postorder, i + 1, inE, pS + i - inS, pE - 1);
            }
        }
        return currNode;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
