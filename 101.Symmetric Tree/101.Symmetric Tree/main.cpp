//
//  main.cpp
//  101.Symmetric Tree
//
//  Created by Abysman on 2018/7/23.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return sol_2(root);
    }
    
    //  iterative
    bool sol_2(TreeNode* root) {
        queue<TreeNode* > q_l;
        q_l.push(root->left);
        queue<TreeNode* > q_r;
        q_r.push(root->right);
        while (!q_l.empty() && !q_r.empty()) {
            TreeNode* node_l = q_l.front();
            TreeNode* node_r = q_r.front();
            q_l.pop();
            q_r.pop();
            if (!node_l && !node_r) continue;
            if (!node_l || !node_r) return false;
            if (node_l->val != node_r->val) return false;
            q_l.push(node_l->left);
            q_l.push(node_l->right);
            q_r.push(node_r->right);
            q_r.push(node_r->left);
        }
        return true;
    }
    
    //  recursive
    bool sol(TreeNode* a, TreeNode* b) {
        if (a && b) {
            return (a->val == b->val) && sol(a->left, b->right) && sol(a->right, b->left);
        }
        return (a==b);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
