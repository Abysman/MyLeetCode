//
//  main.cpp
//  006.Subtree with Maximum Average(LintCode)
//
//  Created by Abysman on 2019/2/3.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode* res;
    double currMax;
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        if (!root) return root;
        currMax = INT_MIN;
        int num = 0;
        helper(root, num);
        return res;
    }
    
    double helper(TreeNode* root, int &num) {
        if (!root) return 0;
        int numl = 0, numr = 0;
        double avgl = helper(root->left, numl);
        double avgr = helper(root->right, numr);
        
        num = 1 + numl + numr;
        double avg = (avgl * numl + avgr * numr + root->val) / num;
        if (!res || avg > currMax) {
            res = root;
            currMax = avg;
        }
        return avg;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
