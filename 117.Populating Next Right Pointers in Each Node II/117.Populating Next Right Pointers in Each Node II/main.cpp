//
//  main.cpp
//  117.Populating Next Right Pointers in Each Node II
//
//  Created by Abysman on 2019/2/15.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* left;
 Node* right;
 Node* next;
 
 Node() {}
 
 Node(int _val, Node* _left, Node* _right, Node* _next) {
 val = _val;
 left = _left;
 right = _right;
 next = _next;
 }
 };
 */

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node *tmp = new Node(-1), *currChild = tmp, *r = root;
        while (root) {
            currChild = tmp;
            tmp->next = NULL;
            while (root) {
                if (root->left) currChild = currChild->next = root->left;
                if (root->right) currChild = currChild->next = root->right;
                root = root->next;
            }
            root = tmp->next;
        }
        return r;
    }
};

//  mine
class Solution {
public:
    Node* connect(Node* root) {
        Node *tmp = new Node(0), *res = root;
        while (root) {
            Node  *curr = tmp;
            tmp->next = nullptr;
            while (root) {
                if (root->left) {
                    curr->next = root->left;
                    curr = curr->next;
                }
                if (root->right) {
                    curr->next = root->right;
                    curr = curr->next;
                }
                root = root->next;
            }
            root = tmp->next;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
