//
//  main.cpp
//  120.Triangle
//
//  Created by stevenxu on 9/9/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> res = triangle.back();
        int rows = triangle.size();
        for (int i = rows - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                res[j] = min(res[j], res[j + 1]) + triangle[i][j];
            }
        }
        return res[0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
