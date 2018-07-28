//
//  main.cpp
//  102.Binary Tree Level Order Traversal
//
//  Created by Abysman on 2018/7/28.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <queue>
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
//  dfs
//vector<vector<int>> ret;
//
//void buildVector(TreeNode *root, int depth)
//{
//    if(root == NULL) return;
//    if(ret.size() == depth)
//        ret.push_back(vector<int>());
//
//    ret[depth].push_back(root->val);
//    buildVector(root->left, depth + 1);
//    buildVector(root->right, depth + 1);
//}
//
//vector<vector<int> > levelOrder(TreeNode *root) {
//    buildVector(root, 0);
//    return ret;
//}



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        queue<TreeNode*> nodeQueue;
        vector<vector<int>> res;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            int n = nodeQueue.size();
            vector<int> curr_res;
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = nodeQueue.front();
                if (curr->left) nodeQueue.push(curr->left);
                if (curr->right) nodeQueue.push(curr->right);
                curr_res.push_back(curr->val);
                nodeQueue.pop();
            }
            res.push_back(curr_res);
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
