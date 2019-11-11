//
//  main.cpp
//  1254.Number of Closed Islands
//
//  Created by stevenxu on 11/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool terminal;
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 0) {
                    terminal = false;
                    helper(grid, i, j);
                    if (!terminal) res++;
                }
            }
        }
        return res;
    }
    
    void helper(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            terminal = true;
            return;
        }
        if (grid[i][j] == 1) return;
        grid[i][j] = 1;
        for (auto dir: dirs) {
            int nextI = i + dir[0], nextJ = j + dir[1];
            helper(grid, nextI, nextJ);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
