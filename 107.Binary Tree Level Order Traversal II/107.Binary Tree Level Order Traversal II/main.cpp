//
//  main.cpp
//  107.Binary Tree Level Order Traversal II
//
//  Created by Abysman on 2018/8/4.
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> res;
        sol(res, root, 0);
        return res;
    }
    
    void sol(vector<vector<int>>& res, TreeNode* root, int currDepth) {
        if (!root) return;
        if (res.size() == currDepth) {
            vector<int> currV;
            currV.push_back(root->val);
            res.insert(res.begin(), currV);
        }
        else {
            res[res.size() - currDepth - 1].push_back(root->val);
        }
        sol(res, root->left, currDepth + 1);
        sol(res, root->right, currDepth + 1);
        return;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
