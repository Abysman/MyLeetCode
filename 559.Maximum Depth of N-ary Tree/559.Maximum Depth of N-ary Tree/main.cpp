//
//  main.cpp
//  559.Maximum Depth of N-ary Tree
//
//  Created by Abysman on 2019/1/14.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>


/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 vector<Node*> children;
 
 Node() {}
 
 Node(int _val, vector<Node*> _children) {
 val = _val;
 children = _children;
 }
 };
 */
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        queue<Node*> q;
        int maxDepth = 0;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                Node* curr = q.front();
                vector<Node*> child = curr->children;
                for (int j = 0; j < child.size(); ++j) {
                    q.push(child[j]);
                }
                q.pop();
            }
            maxDepth += 1;
        }
        return maxDepth;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
