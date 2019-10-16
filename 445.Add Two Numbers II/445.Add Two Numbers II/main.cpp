//
//  main.cpp
//  445.Add Two Numbers II
//
//  Created by stevenxu on 10/16/19.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        while (l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        int carry_out = 0, curr1 = 0, curr2 = 0;
        ListNode *last = NULL, *curr;
        while (!s1.empty() || !s2.empty() || carry_out) {
            curr1 = curr2 = 0;
            if (!s1.empty()) {
                curr1 = s1.top()->val;
                s1.pop();
            }
            if (!s2.empty()) {
                curr2 = s2.top()->val;
                s2.pop();
            }
            int sum = curr1 + curr2 + carry_out;
            carry_out = sum / 10;
            curr = new ListNode(sum % 10);
            curr->next = last;
            last = curr;
        }
        return curr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
