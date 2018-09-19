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
        vector<int> tmp(grid[0].size());
        vector<vector<int>> record(grid.size(), tmp);
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (record[i][j] == 0 && grid[i][j] == '1') {
                    count += 1;
                    helper(grid, record, i, j);
                }
            }
        }
        return count;
    }
    
    void helper(vector<vector<char>>& grid, vector<vector<int>>& record, int i, int j) {
        if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1) return;
        if (grid[i][j] == '1' && record[i][j] == 0) {
            record[i][j] = 1;
            helper(grid, record, i - 1, j);
            helper(grid, record, i, j - 1);
            helper(grid, record, i + 1, j);
            helper(grid, record, i, j + 1);
        }
        else return;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
