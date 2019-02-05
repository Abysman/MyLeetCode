//
//  main.cpp
//  63.Unique Paths II
//
//  Created by Abysman on 2019/2/4.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<int> record(m);
        record[0] = 1;
        int res = 0;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) record[i] = 1;
            else break;
        }
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                record[i] = i > 0 ? (1 - obstacleGrid[i][j]) * (record[i] + record[i - 1]) :
                (1 - obstacleGrid[i][j]) * record[i];
            }
        }
        return record[m - 1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
