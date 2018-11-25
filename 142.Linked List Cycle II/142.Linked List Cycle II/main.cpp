//
//  main.cpp
//  142.Linked List Cycle II
//
//  Created by Abysman on 2018/11/25.
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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode* prev = head;
        ListNode* last = head;
        while (last->next && last->next->next) {
            prev = prev->next;
            last = last->next;
            last = last->next;
            if (prev == last) {
                prev = head;
                while (last != prev) {
                    prev = prev->next;
                    last = last->next;
                }
                return prev;
            }
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
