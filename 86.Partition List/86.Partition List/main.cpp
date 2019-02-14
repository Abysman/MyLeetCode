//
//  main.cpp
//  86.Partition List
//
//  Created by Abysman on 2019/2/13.
//  Copyright © 2019 Abysman. All rights reserved.
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode *curr = head, *head1 = new ListNode(-1), *head2 = new ListNode(-1), *newHead1 = head1, *newHead2 = head2;
        while (curr) {
            ListNode* next = curr->next;
            if (curr->val < x) {
                head1->next = curr;
                head1 = curr;
            }
            else {
                head2->next = curr;
                head2 = curr;
            }
            curr = next;
        }
        head1->next = newHead2->next;
        head2->next = NULL;
        return newHead1->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
