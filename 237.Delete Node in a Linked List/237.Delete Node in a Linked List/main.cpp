//
//  main.cpp
//  237.Delete Node in a Linked List
//
//  Created by Abysman on 2018/9/20.
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
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
