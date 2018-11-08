//
//  main.cpp
//  276.Paint Fence
//
//  Created by Abysman on 2018/11/8.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int numWays(int n, int k) {
        if (n < 2 || k == 0) return n*k;
        int a = k, b = k * (k - 1);
        int res;
        for (int i = 2;i < n; ++i) {
            res = (a + b) * (k - 1);
            a = b;
            b = res;
        }
        return a + b;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
