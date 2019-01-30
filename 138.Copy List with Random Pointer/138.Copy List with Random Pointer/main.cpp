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

//  O(1) space O(n) time
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        RandomListNode* curr = head;
        while (curr) {
            RandomListNode* copy = new RandomListNode(curr->label);
            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }
        
        curr = head;
        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        RandomListNode *copyHead = new RandomListNode(0), *currCopy;
        RandomListNode* copyIter = copyHead;
        curr = head;
        
        while (curr) {
            RandomListNode* next = curr->next->next;
            currCopy = curr->next;
            copyIter->next = currCopy;
            curr->next = next;
            copyIter = currCopy;
            curr = curr->next;
        }
        
        return copyHead->next;
    }
};

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
