//
//  main.cpp
//  119.Pascal's Triangle II
//
//  Created by Abysman on 2018/7/29.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        vector<int> tmp(rowIndex + 1, 1);
        if (rowIndex <= 1) return res;
        for (int i = 0; i < rowIndex - 1; ++i) {
            for (int j = 1; j < i + 2; ++j) {
                res[j] = tmp[j - 1] + res[j];
            }
            for (int j = 1; j < i + 2; ++j) {
                tmp[j] = res[j];
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
