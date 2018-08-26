//
//  main.cpp
//  257.Binary Tree Paths
//
//  Created by Abysman on 2018/8/26.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
//    if(!root->left && !root->right) {
//        result.push_back(t);
//        return;
//    }
//
//    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
//    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
//}
//
//vector<string> binaryTreePaths(TreeNode* root) {
//    vector<string> result;
//    if(!root) return result;
//
//    binaryTreePaths(result, root, to_string(root->val));
//    return result;
//}
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return vector<string> ();
        vector<string> res;
        string s = "";
        helper(root, res, s);
        return res;
    }
    
    void helper(TreeNode* root, vector<string>& res, string s) {
        if (!root) return;
        if (!root->left && !root->right) {
            s += to_string(root->val);
            res.push_back(s);
            return;
        }
        string tmp = s + to_string(root->val) + "->";
        helper(root->left, res, tmp);
        helper(root->right, res, tmp);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
