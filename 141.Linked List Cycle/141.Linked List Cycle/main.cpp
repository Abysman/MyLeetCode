//
//  main.cpp
//  141.Linked List Cycle
//
//  Created by Abysman on 2018/8/26.
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

//public boolean hasCycle(ListNode head) {
//    if(head==null) return false;
//    ListNode walker = head;
//    ListNode runner = head;
//    while(runner.next!=null && runner.next.next!=null) {
//        walker = walker.next;
//        runner = runner.next.next;
//        if(walker==runner) return true;
//    }
//    return false;
//}

//  mine
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* front = head->next;
        ListNode* back = head;
        while (front != back) {
            if (front) {
                front = front->next;
            }
            if (front) {
                front = front->next;
            }
            if (back) {
                back = back->next;
            }
        }
        if (front == NULL) return false;
        else return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
