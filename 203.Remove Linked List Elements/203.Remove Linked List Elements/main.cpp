//
//  main.cpp
//  203.Remove Linked List Elements
//
//  Created by Abysman on 2018/8/8.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = new ListNode(0);
        curr->next = head;
        ListNode* tmp = curr;
        while (curr) {
            while (curr->next && curr->next->val == val) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return tmp->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
