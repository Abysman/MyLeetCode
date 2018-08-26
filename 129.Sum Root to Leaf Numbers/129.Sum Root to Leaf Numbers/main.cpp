//
//  main.cpp
//  129.Sum Root to Leaf Numbers
//
//  Created by Abysman on 2018/8/26.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
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
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        vector<string> record;
        int res = 0;
        string s = "";
        helper(record, root, s);
        for (int i = 0; i < record.size(); ++i) {
            res += stoi(record[i]);
        }
        return res;
    }
    
    void helper(vector<string>& record, TreeNode* root, string s) {
        if (!root) return;
        string tmp =  s;
        tmp.push_back(root->val + '0');
        
        if (!root->left && !root->right) {
            record.push_back(tmp);
            return;
        }
        helper(record, root->left, tmp);
        helper(record, root->right, tmp);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "123";
    int b = 4;
    s += (b+'0');
    cout << s + (5 + '0')<< "\n";
    
    cout << s;
    std::cout << "Hello, World!\n";
    return 0;
}
