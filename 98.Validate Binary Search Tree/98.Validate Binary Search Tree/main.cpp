//
//  main.cpp
//  98.Validate Binary Search Tree
//
//  Created by Abysman on 2018/11/15.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

//  Iterative
//  Referenced from https://leetcode.com/problems/validate-binary-search-tree/discuss/32112/Learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-(Java-Solution)
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        if (!root) return true;
//        TreeNode* pre = NULL;
//        stack<TreeNode* > s;
//        while (root != NULL || !s.empty()) {
//            while (root != NULL) {
//                s.push(root);
//                root = root->left;
//            }
//            root = s.top();
//            s.pop();
//            if (pre != NULL && root->val <= pre->val) return false;
//            pre = root;
//            root = root->right;
//        }
//        return true;
//    }
//
//};


//  Recursive
//  referenced from https://leetcode.com/problems/validate-binary-search-tree/discuss/32141/C%2B%2B-simple-recursive-solution
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
