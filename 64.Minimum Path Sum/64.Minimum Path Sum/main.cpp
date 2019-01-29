//
//  main.cpp
//  64.Minimum Path Sum
//
//  Created by Abysman on 2018/8/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        int m = grid.size();
//        int n = grid[0].size();
//        vector<int> cur(m, grid[0][0]);
//        for (int i = 1; i < m; i++)
//            cur[i] = cur[i - 1] + grid[i][0];
//        for (int j = 1; j < n; j++) {
//            cur[0] += grid[0][j];
//            for (int i = 1; i < m; i++)
//                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
//        }
//        return cur[m - 1];
//    }
//};

//  mine
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> tmp(n);
        vector<int> res(m, INT_MAX);
        res[0] = grid[0][0];
        for (int i = 1; i < m; ++i) res[i] = grid[i][0] + res[i - 1];
        for (int col = 1; col < n; ++col) {
            for (int row = 0; row < m; ++row) {
                if (row >= 1) res[row] = min(res[row - 1], res[row]);
                res[row] += grid[row][col];
            }
        }
        return res[m - 1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {{1,3,1},{1,5,1},{4,2,1}};
    Solution sol = Solution();
    cout << sol.minPathSum(a) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
