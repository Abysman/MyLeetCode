//
//  main.cpp
//  2.Add Two Numbers
//
//  Created by Abysman on 2018/6/22.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *curr = dummy;
        int carry_out = 0;
        while (l1 || l2 || carry_out) {
            int currNum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry_out;
            ListNode* currNode = new ListNode(currNum % 10);
            curr->next = currNode;
            curr = currNode;
            carry_out = currNum / 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
