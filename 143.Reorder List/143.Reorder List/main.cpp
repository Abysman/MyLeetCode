//
//  main.cpp
//  143.Reorder List
//
//  Created by Abysman on 2018/12/22.
//  Copyright © 2018 Abysman. All rights reserved.
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
//    void reorderList(ListNode* head) {
//        if (!head || !head->next) return;
//        ListNode* p = head;
//        ListNode* prev = NULL;
//        while (p->next) {
//            prev = p;
//            p = p->next;
//        }
//        prev->next = NULL;
//        ListNode* next = head->next;
//        reorderList(next);
//        head->next = p;
//        p->next = next;
//    }
//};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        int len = 0;
        ListNode* curr = head;
        ListNode* d = new ListNode(-1);
        d->next = head;
        ListNode* p1 = d;
        ListNode* p2 = d;
        for (;p2 && p2->next; p1 = p1->next, p2 = p2->next->next);
        ListNode* newMid = reverseList(p1->next);
        p1->next = newMid;
        for (p2 = p1->next, p1->next = NULL, p1 = head; p2;) {
            ListNode* tmp = p1->next;
            p1->next = p2;
            p2 = p2->next;
            p1->next->next = tmp;
            p1 = tmp;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = NULL;
        while (head) {
            ListNode* tmp = head->next;
            head->next = curr;
            curr = head;
            head = tmp;
        }
        return curr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
