//
//  main.cpp
//  231.Power of Two
//
//  Created by Abysman on 2018/8/6.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0 ) return false;
        int count = 0;
        while (n) {
            n = n & (n-1);
            count ++;
            if (count > 1) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
