//
//  main.cpp
//  230.Kth Smallest Element in a BST
//
//  Created by Abysman on 2018/8/27.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            if (s.top()) {
                count += 1;
                curr = s.top();
                s.pop();
                if (count  == k) return curr->val;
                curr = curr->right;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
