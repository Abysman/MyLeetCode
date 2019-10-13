//
//  main.cpp
//  650.2 Keys Keyboard
//
//  Created by stevenxu on 10/12/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i < n; i++)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
