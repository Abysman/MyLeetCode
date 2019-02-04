//
//  main.cpp
//  708.Insert into a Cyclic Sorted List
//
//  Created by Abysman on 2019/2/3.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* next;
 
 Node() {}
 
 Node(int _val, Node* _next) {
 val = _val;
 next = _next;
 }
 };
 */
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *prev = head;
        bool inserted = false;
        if (!head) {
            head = new Node(insertVal, nullptr);
            head->next = head;
            return head;
        }
        Node* curr = head->next;
        while (true) {
            if ((prev->val <= insertVal && insertVal <= curr->val) ||
                (prev->val > curr->val && insertVal < curr->val) ||
                (prev->val > curr->val && insertVal > prev->val)) {
                prev->next = new Node(insertVal, curr);
                inserted = true;
                break;
            }
            prev = prev->next;
            curr = curr->next;
            if (prev == head) break;
        }
        if (!inserted) {
            prev->next = new Node(insertVal, curr);
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
