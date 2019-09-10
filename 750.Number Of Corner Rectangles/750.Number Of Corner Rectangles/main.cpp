//
//  main.cpp
//  750.Number Of Corner Rectangles
//
//  Created by stevenxu on 9/9/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        if (grid.size() <= 1) return 0;
        int res = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = i + 1; j < rows; ++j) {
                int currCount = 0;
                for (int k = 0; k < cols; ++k) {
                    currCount += grid[i][k] & grid[j][k];
                }
                res += currCount * (currCount - 1) / 2;
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
