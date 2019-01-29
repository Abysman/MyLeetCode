//
//  main.cpp
//  002.Reverse Half Linkedlist(Amazon)
//
//  Created by Abysman on 2019/1/29.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* last = NULL;
    while (head) {
        ListNode* n = head->next;
        head->next = last;
        last = head;
        head = n;
    }
    return last;
}

ListNode *reverse2ndHalfOfLinkedList(ListNode *head){
    ListNode *last = head, *next = head, *pre = NULL;
    while (head && head->next) {
        pre = last;
        slow = slow->next;
        next = next->next;
    }
    if (!next) pre->next = reverseList(slow);
    else slow->next = reverseList(slow->next);
    return head;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
