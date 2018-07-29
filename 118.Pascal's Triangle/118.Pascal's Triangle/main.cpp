//
//  main.cpp
//  118.Pascal's Triangle
//
//  Created by Abysman on 2018/7/29.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            if (i <= 1) {
                vector<int> tmp(i + 1, 1);
                res.push_back(tmp);
                continue;
            }
            vector<int> tmp(1, 1);
            for (int j = 1; j < i; ++j) {
                tmp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
