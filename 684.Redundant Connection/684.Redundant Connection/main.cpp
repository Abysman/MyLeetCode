//
//  main.cpp
//  684.Redundant Connection
//
//  Created by Abysman on 2019/1/3.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

//  union find
class Solution {
    unordered_map<int, int> m;
    int res = -1;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if (edges.empty()) return vector<int> ();
        for (int i = 0; i < edges.size(); ++i) {
            uni(edges[i][0], edges[i][1], i);
        }
        return edges[res];
    }
    
    int find(int n) {
        if (!m.count(n)) {
            m[n] = n;
        }
        if (m[n] != n) {
            m[n] = find(m[n]);
        }
        return m[n];
    }
    
    void uni(int a, int b, int index) {
        a = find(a), b= find(b);
        if (a != b) {
            m[a] = b;
        } else {
            if (index > res) res = index;
        }
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> record(edges.size() + 1);
        for (int i = 0;i < edges.size() + 1; ++i) {
            record[i] = i;
        }
        for (auto edge:edges) {
            int e1 = edge[0], e2 = edge[1];
            while (record[e1] != e1) e1 = record[e1];
            while (record[e2] != e2) e2 = record[e2];
            if (e1 == e2) return edge;
            else record[e1] = e2;
        }
        return vector<int>();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
