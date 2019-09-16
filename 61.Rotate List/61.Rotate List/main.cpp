//
//  main.cpp
//  61.Rotate List
//
//  Created by stevenxu on 9/16/19.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *newHead, *tail;
        newHead = tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = newHead;
        if (k %= len) {
            for (int i = 0; i < len - k; ++i) tail = tail->next;
        }
        newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
