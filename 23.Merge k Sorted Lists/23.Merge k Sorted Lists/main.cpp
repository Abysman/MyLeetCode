//
//  main.cpp
//  23.Merge k Sorted Lists
//
//  Created by Abysman on 2018/8/15.
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
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct comp{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* curr;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for (int i = 0; i < lists.size(); ++i) {
            curr = lists[i];
            if (curr) {
                pq.push(curr);
            }
        }
        if (pq.empty()) return NULL;
        ListNode* head = pq.top();
        curr = head;
        pq.pop();
        
        if (curr->next) {
            pq.push(curr->next);
        }
        
        while (!pq.empty()) {
            ListNode* next = pq.top();
            curr->next = next;
            pq.pop();
            curr = next;
            if (next->next) {
                pq.push(next->next);
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
