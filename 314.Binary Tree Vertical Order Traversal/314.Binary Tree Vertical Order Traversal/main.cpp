//
//  main.cpp
//  314.Binary Tree Vertical Order Traversal
//
//  Created by Abysman on 2019/2/14.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;;

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        unordered_map<TreeNode*, int> m1;
        map<int, vector<int>> m2;
        m1[root] = 0;
        m2[0].push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            int currVerticalId = m1[curr];
            if (curr->left) {
                m1[curr->left] = currVerticalId - 1;
                m2[currVerticalId - 1].push_back(curr->left->val);
                q.push(curr->left);
            }
            if (curr->right) {
                m1[curr->right] = currVerticalId + 1;
                m2[currVerticalId + 1].push_back(curr->right->val);
                q.push(curr->right);
            }
        }
        
        for (auto r: m2) {
            vector<int> tmp;
            for (auto n: r.second) tmp.push_back(n);
            res.push_back(tmp);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a;
    
    std::cout << "Hello, World!\n";
    return 0;
}
