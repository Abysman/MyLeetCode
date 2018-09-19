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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || (preorder.size() != inorder.size())) return NULL;
        TreeNode* root = helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        return root;
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE) {
        if (preS > preE || inS > inE) {
            return NULL;
        }
        
        TreeNode* currNode = new TreeNode(preorder[preS]);
        
        for (int i = inS; i <= inE; ++i) {
            if (inorder[i] == preorder[preS]) {
                currNode->left = helper(preorder, inorder, preS + 1, preS + i - inS, inS, i - 1);
                currNode->right = helper(preorder, inorder, preS + i - inS + 1, preE, i + 1, inE);
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
