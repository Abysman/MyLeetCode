//
//  main.cpp
//  326.Power of Three
//
//  Created by Abysman on 2018/9/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (int(log10(n)/ log10(3)) == (log10(n) / log10(3))) return true;
        else return false;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
