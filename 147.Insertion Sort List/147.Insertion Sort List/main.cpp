//
//  main.cpp
//  147.Insertion Sort List
//
//  Created by Abysman on 2018/10/30.
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* h = head;
        ListNode* curr = h->next;
        head->next = NULL;
        while (curr) {
            ListNode* nextNode = curr->next;
            h = head;
            if (curr->val < h->val) {
                curr->next = h;
                head = curr;
            }
            else {
                while (h->next && h->next->val < curr->val) {
                    h = h->next;
                }
                curr->next = h->next;
                h->next = curr;
            }
            curr = nextNode;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
