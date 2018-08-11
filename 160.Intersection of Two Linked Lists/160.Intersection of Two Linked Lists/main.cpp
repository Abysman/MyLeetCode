//
//  main.cpp
//  160.Intersection of Two Linked Lists
//
//  Created by Abysman on 2018/8/11.
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


//  concise
//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//{
//    ListNode *p1 = headA;
//    ListNode *p2 = headB;
//
//    if (p1 == NULL || p2 == NULL) return NULL;
//
//    while (p1 != NULL && p2 != NULL && p1 != p2) {
//        p1 = p1->next;
//        p2 = p2->next;
//
//        //
//        // Any time they collide or reach end together without colliding
//        // then return any one of the pointers.
//        //
//        if (p1 == p2) return p1;
//
//        //
//        // If one of them reaches the end earlier then reuse it
//        // by moving it to the beginning of other list.
//        // Once both of them go through reassigning,
//        // they will be equidistant from the collision point.
//        //
//        if (p1 == NULL) p1 = headB;
//        if (p2 == NULL) p2 = headA;
//    }
//
//    return p1;
//}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        // if (headA == headB) return headA;
        ListNode* currA = new ListNode(0);
        ListNode* currB = new ListNode(0);
        currA->next = headA;
        currB->next = headB;
        int lengthA = 0;
        int lengthB = 0;
        while (currA) {
            currA = currA->next;
            lengthA += 1;
        }
        while (currB) {
            currB = currB->next;
            lengthB += 1;
        }
        currA = headA;
        currB = headB;
        if (lengthA >= lengthB) {
            for (int i = 0; i < abs(lengthA - lengthB); ++i) {
                currA = currA->next;
            }
        }
        else {
            for (int i = 0; i < abs(lengthA - lengthB); ++i) {
                currB = currB->next;
            }
        }
        while (currA && currB) {
            if (currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
