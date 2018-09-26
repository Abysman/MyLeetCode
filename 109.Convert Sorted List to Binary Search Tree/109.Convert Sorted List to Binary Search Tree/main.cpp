//
//  main.cpp
//  109.Convert Sorted List to Binary Search Tree
//
//  Created by Abysman on 2018/9/20.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>


using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//class Solution {
//public:
//    TreeNode *sortedListToBST(ListNode *head)
//    {
//        return sortedListToBST( head, NULL );
//    }
//
//private:
//    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
//    {
//        if( head == tail )
//            return NULL;
//        if( head->next == tail )    //
//        {
//            TreeNode *root = new TreeNode( head->val );
//            return root;
//        }
//        ListNode *mid = head, *temp = head;
//        while( temp != tail && temp->next != tail )    // 寻找中间节点
//        {
//            mid = mid->next;
//            temp = temp->next->next;
//        }
//        TreeNode *root = new TreeNode( mid->val );
//        root->left = sortedListToBST( head, mid );
//        root->right = sortedListToBST( mid->next, tail );
//        return root;
//    }
//};
//  mine    12ms
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len += 1;
            curr = curr->next;
        }
        TreeNode* res = helper(head, len);
        return res;
    }
    
    TreeNode* helper(ListNode* head, int num) {
        if (num == 1) return new TreeNode(head->val);
        int mid = (num - 1) / 2;
        
        ListNode* node = head;
        for (int i = 0; i < mid; ++i) {
            node = node->next;
        }
        TreeNode* curr = new TreeNode(node->val);
        if (num > 2) {
            TreeNode* left = helper(head, num - (num / 2 + 1));
            curr->left = left;
        }
        TreeNode* right = helper(node->next, num / 2);
        curr->right = right;
        return curr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
