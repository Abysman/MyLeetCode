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

//  union find
class Solution {
    unordered_map<int, int> island;
    int count = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};
        for (auto rows: grid) {
            for (auto i: rows) {
                if (i == '1') count++;
            }
        }
        for (int x = 0; x < rows; ++x) {
            for (int y = 0; y < cols; ++y) {
                if (grid[x][y] == '1') {
                    for (auto dir: dirs) {
                        int nextX = x + dir.first;
                        int nextY = y + dir.second;
                        if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols &&
                            grid[nextX][nextY] == '1') {
                            uni(x * cols + y, nextX * cols + nextY);
                        }
                    }
                }
                
            }
        }
        return count;
    }
    
    int find(int n) {
        if (!island.count(n)) {
            island[n] = n;
        }
        if (island[n] != n) {
            island[n] = find(island[n]);
        }
        return island[n];
    }
    
    void uni(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            island[a] = island[b];
            count--;
        }
    }
};

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
