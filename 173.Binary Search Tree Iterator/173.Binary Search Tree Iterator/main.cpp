//
//  main.cpp
//  173.Binary Search Tree Iterator
//
//  Created by Abysman on 2018/9/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    
public:
    stack<TreeNode* > s;
    BSTIterator(TreeNode *root) {
        if (!root) return;
        TreeNode* curr = root;
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        if (s.empty()) return NULL;
        else {
            TreeNode* node = s.top();
            s.pop();
            if (node->right) {
                TreeNode* tmp = node->right;
                while (tmp) {
                    s.push(tmp);
                    tmp = tmp->left;
                }
            }
            return node->val;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
