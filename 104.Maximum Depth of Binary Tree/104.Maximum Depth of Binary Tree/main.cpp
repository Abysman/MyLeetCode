//
//  main.cpp
//  104.Maximum Depth of Binary Tree
//
//  Created by Abysman on 2018/7/23.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//  Depth-fisrt-search
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root) {
            int leftMaxDepth = maxDepth(root->left) + 1;
            int rightMaxDepth = maxDepth(root->right) + 1;
            if (leftMaxDepth > rightMaxDepth) {
                return leftMaxDepth;
            }
            return rightMaxDepth;
        }
        else {
            return 0;
        }
    }
};

//  Breadth-first-search
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode* > q;
        int depth = 0;
        q.push(root);
        while (!q.empty()) {
            depth++;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *p = q.front();
                q.pop();
                
                if(p -> left != NULL)
                    q.push(p -> left);
                if(p -> right != NULL)
                    q.push(p -> right);
            }
        }
        return depth;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
