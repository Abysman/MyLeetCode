//
//  main.cpp
//  003.Min path sum of binary tree(Amazon)
//
//  Created by Abysman on 2019/1/29.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minPathSum(TreeNode* root) {
    if (root == NULL) return 0;
    int sum = root->val;
    if (root->left && root->right) return sum + std::min(minPathSum(root->left), minPathSum(root->right));
    if (root->left) return sum + minPathSum(root->left);
    return sum + minPathSum(root->right);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(7);
    TreeNode* root1 = new TreeNode(3);
    TreeNode* root2 = new TreeNode(10);
    TreeNode* root3 = new TreeNode(1);
    TreeNode* root4 = new TreeNode(8);
    TreeNode* root5 = new TreeNode(0);
    root->left = root1;
    root->right = root2;
    root1->left = root3;
    root2->left = root4;
    root3->left = root5;
    std::cout << minPathSum(root) << "\n";
    
    std::cout << "Hello, World!\n";
    return 0;
}
