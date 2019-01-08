//
//  main.cpp
//  461.Hamming Distance
//
//  Created by Abysman on 2019/1/7.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int c = 0;
        for (c = 0; n; n >>= 1) {
            c += n & 1;
        }
        return c;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
