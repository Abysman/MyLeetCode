//
//  main.cpp
//  19.Remove Nth Node From End of List
//
//  Created by Abysman on 2018/8/1.
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

//ListNode *removeNthFromEnd(ListNode *head, int n)
//{
//    if (!head)
//        return nullptr;
//    
//    ListNode new_head(-1);
//    new_head.next = head;
//    
//    ListNode *slow = &new_head, *fast = &new_head;
//    
//    for (int i = 0; i < n; i++)
//        fast = fast->next;
//    
//    while (fast->next)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    
//    ListNode *to_de_deleted = slow->next;
//    slow->next = slow->next->next;
//    
//    delete to_be_deleted;
//    
//    return new_head.next;
//}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        ListNode* prev = head;
        ListNode* curr = head;
        for (int i = 0; i < n + 1; ++i) {
            if (!curr) {
                return head->next;
            }
            curr = curr->next;
        }
        while (curr) {
            curr = curr->next;
            prev = prev->next;
        }
        if (prev->next) {
            ListNode* next = prev->next->next;
            prev->next = next;
            return head;
        }
        else return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
