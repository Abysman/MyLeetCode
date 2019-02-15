//
//  main.cpp
//  285.Inorder Successor in BST
//
//  Created by Abysman on 2019/2/15.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <stack>
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) return NULL;
        
        TreeNode *suc = NULL;
        while (root != NULL) {
            if (root->val <= p->val) {
                root = root->right;
            } else {
                suc = root;
                root = root->left;
            }
        }
        
        return suc;
    }
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return root;
        stack<TreeNode*> s;
        int flag = 0;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            if (flag) return root;
            s.pop();
            if (root->val == p->val) {
                if (!s.empty() && !root->right) return s.top();
                if (root->right) flag = 1;
            }
            
            root = root->right;
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    stack<int> s;
    cout << s.top();
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
