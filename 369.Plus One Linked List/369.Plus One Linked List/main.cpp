//
//  main.cpp
//  369.Plus One Linked List
//
//  Created by stevenxu on 9/12/19.
//  Copyright © 2019 stevenxu. All rights reserved.
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
    ListNode* plusOne(ListNode* head) {
        int carry_out = help(head);
        ListNode* res = head;
        if (carry_out > 0) {
            res = new ListNode(carry_out);
            res->next = head;
        }
        return res;
    }
    
    int help(ListNode* head) {
        int carry_out, last_carryout = 1;
        if (head->next) {
            last_carryout = help(head->next);
        }
        carry_out = (last_carryout + head->val) / 10;
        head->val = (last_carryout + head->val) % 10;
        return carry_out;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
