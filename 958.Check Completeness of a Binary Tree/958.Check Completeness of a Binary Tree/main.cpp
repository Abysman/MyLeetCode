//
//  main.cpp
//  958.Check Completeness of a Binary Tree
//
//  Created by stevenxu on 11/7/19.
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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        int i = 0;
        while (i < bfs.size() && bfs[i]) {
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            i++;
        }
        while (i < bfs.size() && !bfs[i])
            i++;
        return i == bfs.size();
    }
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        bool prev = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr == nullptr) {
                    prev = true;
                } else {
                    if (prev) return false;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return true;
    }
};/**
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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        bool prev = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr == nullptr) {
                    prev = true;
                } else {
                    if (prev) return false;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
