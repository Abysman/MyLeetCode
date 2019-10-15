//
//  main.cpp
//  6.ZigZag Conversion
//
//  Created by stevenxu on 10/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        int len = s.size();
        vector<string> tmp(numRows);
        string res = "";
        for (int i = 0, step = 1, row = 0; i < len; ++i) {
            tmp[row] += s[i];
            if (row == 0) step = 1;
            else if (row == numRows - 1) step = -1;
            row += step;
        }
        for (int i = 0; i < numRows; ++i) res += tmp[i];
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
