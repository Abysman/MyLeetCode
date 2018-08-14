//
//  main.cpp
//  172.Factorial Trailing Zeroes
//
//  Created by Abysman on 2018/8/14.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for(long long i=5; n/i>0; i*=5){
            result += (n/i);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
