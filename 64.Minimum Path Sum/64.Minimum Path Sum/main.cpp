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
        if (grid.empty()) return 0;
        vector<vector<int>> res(grid.size(), vector<int> (grid[0].size(), 0));
        res[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) res[i][j] = res[i][j - 1] + grid[i][j];
                else if (j == 0) res[i][j] = res[i - 1][j] + grid[i][j];
                else {
                    res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
                }
            }
        }
        return res[grid.size() - 1][grid[0].size() - 1];
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
