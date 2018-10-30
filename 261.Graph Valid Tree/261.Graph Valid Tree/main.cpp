//
//  main.cpp
//  261.Graph Valid Tree
//
//  Created by Abysman on 2018/10/30.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    bool validTree(int n, std::vector<std::pair<int, int>>& edges) {
        std::vector<std::vector<int>> neighbors(n);
        for (auto e : edges) {
            neighbors[e.first].push_back(e.second);
            neighbors[e.second].push_back(e.first);
        }
        std::vector<bool> visited(n, false);
        if (hasCycle(neighbors, 0, -1, visited))
            return false;
        for (bool v : visited)
            if (!v) return false;
        return true;
    }
private:
    bool hasCycle(std::vector<std::vector<int>>& neighbors, int kid, int parent, std::vector<bool>& visited) {
        if (visited[kid]) return true;
        visited[kid] = true;
        for (auto neigh : neighbors[kid])
            if (neigh != parent && hasCycle(neighbors, neigh, kid, visited))
                return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
