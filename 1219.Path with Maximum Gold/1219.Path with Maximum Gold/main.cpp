//
//  main.cpp
//  1219.Path with Maximum Gold
//
//  Created by stevenxu on 10/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>


class Solution {
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int res = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1) return 0;
        if (grid[i][j] == 0) return 0;
        int res = 0;
        int temp = grid[i][j];
        grid[i][j] = 0;
        for (auto dir: dirs) {
            int nextI = i + dir[0], nextJ = j + dir[1];
            res = max(res, temp + dfs(grid, nextI, nextJ));
        }
        grid[i][j] = temp;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
