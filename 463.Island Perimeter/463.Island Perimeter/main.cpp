//
//  main.cpp
//  463.Island Perimeter
//
//  Created by Abysman on 2019/1/7.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>


//  referenced from https://leetcode.com/problems/island-perimeter/discuss/95126/C%2B%2B-solution-with-explanation
//class Solution {
//public:
//    int islandPerimeter(vector<vector<int>>& grid) {
//        int count=0, repeat=0;
//        for(int i=0;i<grid.size();i++)
//        {
//            for(int j=0; j<grid[i].size();j++)
//            {
//                if(grid[i][j]==1)
//                {
//                    count ++;
//                    if(i!=0 && grid[i-1][j] == 1) repeat++;
//                    if(j!=0 && grid[i][j-1] == 1) repeat++;
//                }
//            }
//        }
//        return 4*count-repeat*2;
//    }
//};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 0) continue;
                if (i == 0) count += 1;
                if (i == row - 1) count += 1;
                if (j == 0) count += 1;
                if (j == col - 1) count += 1;
                for (auto dir:direction) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1 && grid[x][y] == 0) {
                        count += 1;
                    }
                }
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
