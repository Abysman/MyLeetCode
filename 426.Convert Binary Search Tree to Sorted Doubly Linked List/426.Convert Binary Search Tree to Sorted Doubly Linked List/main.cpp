//
//  main.cpp
//  426.Convert Binary Search Tree to Sorted Doubly Linked List
//
//  Created by stevenxu on 9/14/19.
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
 
 Node() {}
 
 Node(int _val, Node* _left, Node* _right) {
 val = _val;
 left = _left;
 right = _right;
 }
 };
 */
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        else {
            auto childs = helper(root);
            Node* minNode = childs.first;
            Node* maxNode = childs.second;
            minNode->left = maxNode;
            maxNode->right = minNode;
            return minNode;
        }
    }
    
    pair<Node*, Node*> helper(Node* root) {
        pair<Node*, Node*> res;
        if (root->left) {
            auto leftChilds = helper(root->left);
            root->left = leftChilds.second;
            leftChilds.second->right = root;
            res.first = leftChilds.first;
        } else res.first = root;
        if (root->right) {
            auto rightChilds = helper(root->right);
            root->right = rightChilds.first;
            rightChilds.first->left = root;
            res.second = rightChilds.second;
        } else res.second = root;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
