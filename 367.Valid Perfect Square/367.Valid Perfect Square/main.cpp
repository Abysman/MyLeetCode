//
//  main.cpp
//  367.Valid Perfect Square
//
//  Created by Abysman on 2018/8/29.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 0, h = num / 2;
        if (num == 0 || num == 1 || num == 9 || num == 16) return true;
        while (l <= h) {
            long mid = l + (h - l) / 2;
            if (mid * mid > long(num)) h = mid - 1;
            else if (mid * mid < long(num)) l = mid + 1;
            else return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
