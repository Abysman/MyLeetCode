//
//  main.cpp
//  2.Add Two Numbers
//
//  Created by Abysman on 2018/6/22.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int curr_carry_out = (l1->val + l2->val) / 10;
        int result = (l1->val + l2->val) % 10;
        int last_carry_out = curr_carry_out;
        
        ListNode* currNode = new ListNode(result);
        ListNode* newNode;
        ListNode* resultNode = currNode;
        
        ListNode* curr1 = l1->next;
        ListNode* curr2 = l2->next;
        
        while (curr1 != NULL || curr2 != NULL) {
            if (curr1 == NULL) {
                result = curr2->val + last_carry_out;
                curr2 = curr2->next;
            }
            else if (curr2 == NULL) {
                result = curr1->val + last_carry_out;
                curr1 = curr1->next;
            }
            else if (curr1 != NULL && curr2 != NULL) {
                result = curr1->val + curr2->val + last_carry_out;
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            
            curr_carry_out = result / 10;
            last_carry_out = curr_carry_out;
            newNode = new ListNode(result % 10);
            
            
            currNode->next = newNode;
            currNode = newNode;
        }
        if (last_carry_out > 0) {
            newNode = new ListNode(last_carry_out);
            currNode->next = newNode;
        }
        return resultNode;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
