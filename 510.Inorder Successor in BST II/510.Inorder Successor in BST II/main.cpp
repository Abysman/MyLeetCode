//
//  main.cpp
//  510.Inorder Successor in BST II
//
//  Created by stevenxu on 11/7/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node == nullptr) return nullptr;
        Node* res = node;
        if (res->right) {
            res = res->right;
            while (res->left) res = res->left;
        } else {
            while (res->parent && res->parent->right == res) {
                res = res->parent;
            }
            res = res->parent;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
