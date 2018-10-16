//
//  main.cpp
//  695.Max Area of Island
//
//  Created by Abysman on 2018/10/14.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

//int maxAreaOfIsland(vector<vector<int>>& grid) {
//    int max_area = 0;
//    for(int i = 0; i < grid.size(); i++)
//        for(int j = 0; j < grid[0].size(); j++)
//            if(grid[i][j] == 1)max_area = max(max_area, AreaOfIsland(grid, i, j));
//    return max_area;
//}
//
//int AreaOfIsland(vector<vector<int>>& grid, int i, int j){
//    if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
//        grid[i][j] = 0;
//        return 1 + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
//    }
//    return 0;
//}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int curr = 0, ans = 0;
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<int> tmp(grid[0].size(), 0);
        vector<vector<int>> visited(grid.size(), tmp);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!visited[i][j]) {
                    cout << i << " " << j << "\n";
                    curr = helper(grid, visited, dir, i, j);
                    ans = max(curr, ans);
                }
            }
        }
        return ans;
    }
    
    int helper(vector<vector<int>>& grid, vector<vector<int>>& visited, const int dir[4][2], int i, int j) {
        if (visited[i][j] == 1 || grid[i][j] == 0) {
            return 0;
        }
        int area = 1;
        visited[i][j] = 1;
        int row = grid.size();
        int col = grid[0].size();
        for (int k = 0; k < 4; ++k) {
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            if (next_i >= 0 && next_i <= row - 1 && next_j >= 0 && next_j <= col - 1) {
                area += helper(grid, visited, dir, next_i, next_j);
            }
        }
        return area;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
