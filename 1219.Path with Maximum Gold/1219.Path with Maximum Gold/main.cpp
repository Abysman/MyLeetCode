//
//  main.cpp
//  1219.Path with Maximum Gold
//
//  Created by stevenxu on 10/6/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;;

class Solution {
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        unordered_set<int> visited;
        int res = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (visited.find(i * cols + j) == visited.end() && grid[i][j] != 0 && (i == 0 || j == 0)) {
                    unordered_set<int> currVisited;
                    visited.insert(i * cols + j);
                    dfs(grid, i, j, visited, currVisited, res, 0);
                }
            }
        }
        return res;
    }
        
    void dfs(vector<vector<int>> grid, int i, int j, unordered_set<int>& visited, int& res, int curr) {
        if (i == 0 || j == 0) visited.insert(i * grid[0].size() + j);
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            res = max(res, curr);
            return;
        }
        curr += grid[i][j];
        for (auto dir: dirs) {
            dfs(grid, i + dir.first, j + dir.second, visited, res, curr);
        }
    }
    
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> tests = {{0,6,0},{5,8,7},{0,9,0}};
    Solution s = Solution();
    s.getMaximumGold(tests);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
