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
        ListNode *dummyhead1 = new ListNode(-1), *dummyhead2 = new ListNode(-1), *head1 = dummyhead1, *head2 = dummyhead2;
        ListNode* curr = head;
        while (curr) {
            if (curr->val >= x) {
                head2->next = curr;
                head2 = curr;
            }
            else {
                head1->next = curr;
                head1 = curr;
            }
            curr = curr->next;
        }
        head2->next = NULL;
        head1->next = dummyhead2->next;
        return dummyhead1->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
