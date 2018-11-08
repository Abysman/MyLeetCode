//
//  main.cpp
//  286.Walls and Gates
//
//  Created by Abysman on 2018/11/7.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
class Solution {
public:
    void wallsAndGates(std::vector<std::vector<int>>& rooms) {
        int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        if (rooms.empty()) return;
        int row = rooms.size();
        int col = rooms[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rooms[i][j] == 0) {
                    helper(rooms, dir, i, j, 0);
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
