//
//  main.cpp
//  342.Power of Four
//
//  Created by Abysman on 2018/9/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

//bool isPowerOfFour(int num) {
//    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
//}

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (int(log10(num)/ log10(4)) == (log10(num) / log10(4))) return true;
        else return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
