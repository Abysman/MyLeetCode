//
//  main.cpp
//  138.Copy List with Random Pointer
//
//  Created by Abysman on 2018/9/8.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        map<RandomListNode*, RandomListNode*> m;
        RandomListNode* curr = head->next;
        RandomListNode* res = new RandomListNode(head->label);
        m[head] = res;
        RandomListNode* node = res;
        while (curr) {
            RandomListNode* tmp = new RandomListNode(curr->label);
            m[curr] = tmp;
            node->next = tmp;
            node = node->next;
            curr = curr->next;
        }
        curr = head;
        node = res;
        while (curr) {
            node->random = m[curr->random];
            node = node->next;
            curr = curr->next;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
