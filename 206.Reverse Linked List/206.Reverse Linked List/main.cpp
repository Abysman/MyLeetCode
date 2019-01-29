//
//  main.cpp
//  206.Reverse Linked List
//
//  Created by Abysman on 2018/4/15.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> s = {0, 1, 2};
    return 0;
}
