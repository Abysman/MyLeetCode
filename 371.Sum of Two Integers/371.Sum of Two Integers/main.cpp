//
//  main.cpp
//  371.Sum of Two Integers
//
//  Created by stevenxu on 9/23/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        return b==0? a:getSum(a^b, (unsigned int)(a&b)<<1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
