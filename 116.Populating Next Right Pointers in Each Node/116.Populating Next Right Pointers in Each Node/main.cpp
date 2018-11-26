//
//  main.cpp
//  116.Populating Next Right Pointers in Each Node
//
//  Created by Abysman on 2018/11/25.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode* curr = NULL;
        TreeLinkNode* prev = root;
        while (prev) {
            curr = prev;
            if (curr->left) {
                while (curr) {
                    curr->left->next = curr->right;
                    if (curr->next) curr->right->next = curr->next->left;
                    curr = curr->next;
                }
            }
            prev = prev->left;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
