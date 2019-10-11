//
//  main.cpp
//  778.Swim in Rising Water
//
//  Created by stevenxu on 10/11/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int res = 0;
        int N = grid.size();
        priority_queue<pair<int, pair<int, int>>> record;
        record.push({-grid[0][0], {0, 0}});
        while (true) {
            auto curr = record.top();
            record.pop();
            int x = curr.second.first, y = curr.second.second;
            grid[x][y] = -1;
            res = max(res, -curr.first);
            if (x == N - 1 && y == N - 1) return res;
            for (auto dir: dirs) {
                int nextX = x + dir[0], nextY = y + dir[1];
                if (nextX >= 0 && nextX <= N - 1 && nextY >= 0 && nextY <= N - 1 && grid[nextX][nextY] != -1) {
                    record.push({-grid[nextX][nextY], {nextX, nextY}});
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
