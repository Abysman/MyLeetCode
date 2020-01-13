//
//  main.cpp
//  1319.Number of Operations to Make Network Connected
//
//  Created by stevenxu on 1/13/20.
//  Copyright © 2020 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > connections.size()) return -1;
        vector<vector<int>> neighbrs(n);
        for (int i = 0; i < connections.size(); ++i) {
            int u = connections[i][0], v = connections[i][1];
            neighbrs[u].push_back(v);
            neighbrs[v].push_back(u);
        }

        vector<bool> visited(n);
        int numComponenets = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            helper(i, visited, neighbrs);
            numComponenets++;
        }
        return numComponenets - 1;
    }
    
    void helper(int start, vector<bool>& visited, vector<vector<int>>& neighbrs) {
        visited[start] = true;
        for (int neighbr: neighbrs[start]) {
            if (visited[neighbr]) continue;
            helper(neighbr, visited, neighbrs);
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
