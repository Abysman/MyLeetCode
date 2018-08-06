//
//  main.cpp
//  263.Ugly Number
//
//  Created by Abysman on 2018/8/6.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        int tmp = num;
        while (tmp % 2 == 0) {
            tmp /= 2;
        }
        while (tmp % 3 == 0) {
            tmp /= 3;
        }
        while (tmp % 5 == 0) {
            tmp /= 5;
        }
        if (tmp == 1) return true;
        else return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
