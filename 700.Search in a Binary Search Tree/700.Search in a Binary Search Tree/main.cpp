//
//  main.cpp
//  700.Search in a Binary Search Tree
//
//  Created by Abysman on 2018/11/13.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void test(int& x){
    x+=1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int x =3;
    test(x);
    std::cout << x;
    return 0;
}
