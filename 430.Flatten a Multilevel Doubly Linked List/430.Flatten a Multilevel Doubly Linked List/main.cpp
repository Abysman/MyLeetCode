//
//  main.cpp
//  430.Flatten a Multilevel Doubly Linked List
//
//  Created by stevenxu on 10/31/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *next, *h = head;
        for (;h != nullptr; h = h->next) {
            if (h->child) {
                Node* next = h->next;
                h->next = h->child;
                h->next->prev = h;
                h->child = nullptr;
                Node* p = h->next;
                while (p->next) p = p->next;
                p->next = next;
                if (next) next->prev = p;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
