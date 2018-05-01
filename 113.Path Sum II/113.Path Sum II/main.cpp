//
//  main.cpp
//  113.Path Sum II
//
//  Created by Abysman on 2018/5/1.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> path;
        vector<int> record;
        helper(root, path, sum, record, 0);
        return path;
    }
    
    void helper(TreeNode* curr_node, vector<vector<int>> &path, int sum, vector<int> &record, int record_sum) {
        if (curr_node) {
            int temp = record_sum + curr_node->val;
            record.push_back(curr_node->val);
            if (curr_node->left == NULL && curr_node->right == NULL) {
                if (temp == sum) {
                    path.push_back(record);
                }
            }
            vector<int> record_copy(record.begin(), record.end());
            helper(curr_node->left, path, sum, record, temp);
            helper(curr_node->right, path, sum, record_copy ,temp);
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> b = {1,2,3,4};
    h(b);
    return 0;
}
