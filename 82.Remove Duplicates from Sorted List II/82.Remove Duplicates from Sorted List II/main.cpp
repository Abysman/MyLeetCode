//
//  main.cpp
//  82.Remove Duplicates from Sorted List II
//
//  Created by Abysman on 2019/1/8.
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

//  recursive
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (!head) return NULL;
//        if (!head->next) return head;
//
//        if (head->next->val != head->val) {
//            head->next = deleteDuplicates(head->next);
//            return head;
//        } else {
//            ListNode* p = head->next;
//            while (p && p->val == head->val) {
//                p = p->next;
//            }
//            return deleteDuplicates(p);
//        }
//    }
//};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr) {
            while (curr->next && curr->next->val == curr->val) {
                curr = curr->next;
            }
            if (curr != prev->next) {
                curr = curr->next;
                prev->next = curr;
                continue;
            }
            curr = curr->next;
            prev = prev->next;
        }
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
