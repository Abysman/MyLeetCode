//
//  main.cpp
//  200.Number of Islands
//
//  Created by Abysman on 2018/9/19.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size(), count = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    count += 1 ;
                    helper(grid, i, j);
                }
            }
        }
        return count;
    }
    
    void helper(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            helper(grid, i - 1, j);
            helper(grid, i, j - 1);
            helper(grid, i + 1, j);
            helper(grid, i, j + 1);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
