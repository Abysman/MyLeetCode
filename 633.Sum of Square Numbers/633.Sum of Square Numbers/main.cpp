//
//  main.cpp
//  633.Sum of Square Numbers
//
//  Created by Abysman on 2018/8/29.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        for (int i = 0; i <= n; i++) {
            int t = sqrt(c - i * i);
            if (t * t == c - i*i) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
