//
//  main.cpp
//  133.Clone Graph
//
//  Created by stevenxu on 9/16/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

//  bfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        queue<Node*> q;
        unordered_map<Node*, Node*> copies;
        q.push(node);
        copies[node] = new Node(node->val, {});
        Node* curr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            for (auto neighbr: curr->neighbors) {
                if (copies.find(neighbr) == copies.end()) {
                    copies[neighbr] = new Node(neighbr->val, {});
                    q.push(neighbr);
                }
                copies[curr]->neighbors.push_back(copies[neighbr]);
            }
        }
        return copies[node];
    }
};

//  dfs
class Solution {
public:
    unordered_map<Node*, Node*> copies;
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val, {});
            for (auto neighbr: node -> neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbr));
            }
        }
        return copies[node];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
