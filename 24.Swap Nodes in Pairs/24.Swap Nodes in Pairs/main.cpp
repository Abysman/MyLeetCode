//
//  main.cpp
//  24.Swap Nodes in Pairs
//
//  Created by Abysman on 2018/9/19.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>


//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if(head == NULL)
//            return NULL;
//        if(head->next == NULL)
//            return head;
//        
//        ListNode* next = head->next;
//        head->next = swapPairs(next->next);
//        next->next = head;
//        
//        return next;
//    }
//};
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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        ListNode* curr = head->next;
        ListNode* last = head;
        head = (curr == NULL ? last  : curr);
        while (curr) {
            ListNode* tmp = curr->next;
            
            curr->next = last;
            if (!tmp) {
                last->next = tmp;
                break;
            }
            if (tmp && tmp->next) {
                last->next = tmp->next;
            }
            else {
                last->next = tmp;
            }
            last = tmp;
            curr = last->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
