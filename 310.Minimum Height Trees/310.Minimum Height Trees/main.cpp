//
//  main.cpp
//  310.Minimum Height Trees
//
//  Created by Abysman on 2018/9/17.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> neighbrs(n);
        vector<int> leafs;
        vector<int> newLeafs;
        
        for (int i = 0; i < edges.size(); ++i) {
            neighbrs[edges[i].first].insert(edges[i].second);
            neighbrs[edges[i].second].insert(edges[i].first);
        }
        
        for (int i = 0; i < n; ++i) {
            if (neighbrs[i].size() == 1 || n <= 2) {
                leafs.push_back(i);
            }
        }
        
        if (n <= 2) return leafs;
        
        while (true) {
            for (auto l:leafs) {
                for (auto n:neighbrs[l]) {
                    neighbrs[n].erase(l);
                    if (neighbrs[n].size() == 1) {
                        newLeafs.push_back(n);
                    }
                }
            }
            if (newLeafs.size() == 0) {
                return leafs;
            }
            leafs = newLeafs;
            newLeafs.clear();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
