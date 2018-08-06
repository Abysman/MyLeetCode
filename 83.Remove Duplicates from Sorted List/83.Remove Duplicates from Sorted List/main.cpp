//
//  main.cpp
//  83.Remove Duplicates from Sorted List
//
//  Created by Abysman on 2018/7/21.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* curr = head->next;
        ListNode* last = head;
        while (curr) {
            if (curr->val == last->val) {
                last->next = curr->next;
            }
            else {
                last = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
