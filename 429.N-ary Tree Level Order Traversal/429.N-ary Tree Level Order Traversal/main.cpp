//
//  main.cpp
//  429.N-ary Tree Level Order Traversal
//
//  Created by Abysman on 2018/11/30.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

/*
 // Definition for a Node.
 class Node {
 public:
 int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return vector<vector<int>> ();
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        vector<int> level;
        Node* curr;
        int s;
        while (!q.empty()) {
            s = q.size();
            level.clear();
            for (int i = 0; i < s; ++i) {
                curr = q.front();
                level.push_back(curr->val);
                q.pop();
                for (auto child:curr->children) {
                    q.push(child);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
