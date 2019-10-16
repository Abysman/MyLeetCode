//
//  main.cpp
//  361.Bomb Enemy
//
//  Created by stevenxu on 10/16/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        
        int res = 0;
        int row = grid.size(), col = grid[1].size();
        if(row == 0 || (col = grid[0].size()) == 0)
            return 0;
        vector<vector<int>> count(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int head = 0, tail = 0, j = 0; j < col; ++j) {
                count[i][j] = (grid[i][j] == '0' ? count[i][j] + head : 0);
                count[i][col - j - 1] = (grid[i][col - j - 1] == '0' ? count[i][col - j - 1] + tail : 0);
                head = grid[i][j] == 'W' ? 0 : (head + (grid[i][j] == 'E' ? 1 : 0));
                tail = grid[i][col - 1 - j] == 'W' ? 0 : (tail + (grid[i][col - 1 - j] == 'E' ? 1 : 0));
            }
        }
        for (int j = 0; j < col; ++j) {
            for (int head = 0, tail = 0, i = 0; i < row; ++i) {
                count[i][j] = (grid[i][j] == '0' ? count[i][j] + head : 0);
                count[row - i - 1][j] = (grid[row - i - 1][j] == '0' ? count[row - i - 1][j] + tail : 0);
                head = grid[i][j] == 'W' ? 0 : (head + (grid[i][j] == 'E' ? 1 : 0));
                tail = grid[row - 1 - i][j] == 'W' ? 0 : (tail + (grid[row - 1 - i][j] == 'E' ? 1 : 0));
            }
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                res = max(res, count[i][j]);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
