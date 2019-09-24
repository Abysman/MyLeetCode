//
//  main.cpp
//  323.Number of Connected Components in an Undirected Graph
//
//  Created by stevenxu on 9/24/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
    unordered_map<int, int> m;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; ++i) {
            m[i] = i;
        }
        int count = 0;
        for (vector<int> edge: edges) {
            if (uni(edge[1], edge[0])) count++;
        }
        return n - count;
    }
    
    int find(int n) {
        if (m.find(n) == m.end()) {
            m[n] = n;
        }
        if (m[n] != n) {
            m[n] = find(m[n]);
        }
        return m[n];
    }
    
    int uni(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            m[a] = b;
            return true;
        } else return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
