//
//  main.cpp
//  50.Pow(x, n)
//
//  Created by Abysman on 2018/9/20.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 && n <= 0 || x == 1 || n == 0) return 1;
        if (n == 1) return x;
        unsigned int p;
        
        if (n < 0) {
            p = -n;
            x = 1.0 / x;
        }
        else p = n;
        double res = myPow(x, p / 2);
        return (n % 2 == 0 ? res * res : res * res * x);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
