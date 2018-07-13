//
//  main.cpp
//  21.Merge Two Sorted Lists
//
//  Created by Abysman on 2018/7/12.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* newLists = new ListNode(-100);
        ListNode* curr3 = newLists;
        int newVal;
        
        while (curr1 || curr2) {
            if (curr1 == NULL) {
                newVal = curr2->val;
                curr2 = curr2->next;
                ListNode *newNode = new ListNode(newVal);
                curr3->next = newNode;
                curr3 = newNode;
                continue;
            }
            if (curr2 == NULL) {
                newVal = curr1->val;
                curr1 = curr1->next;
                ListNode *newNode = new ListNode(newVal);
                curr3->next = newNode;
                curr3 = newNode;
                continue;
            }
            
            if (curr1->val >= curr2->val) {
                newVal = curr2->val;
                curr2 = curr2->next;
            }
            
            else if (curr2->val > curr1->val) {
                newVal = curr1->val;
                curr1 = curr1->next;
            }
            
            ListNode *newNode = new ListNode(newVal);
            curr3->next = newNode;
            curr3 = newNode;
        }
        
        if (newLists->next) {
            return newLists->next;
        }
        else {
            return NULL;
        }
    }
};

/* Recursive version
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
*/



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
