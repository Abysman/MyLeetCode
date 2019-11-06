//
//  main.cpp
//  470.Implement Rand10() Using Rand7()
//
//  Created by stevenxu on 11/5/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int curr = 40;
        while (curr >= 40) curr = 7 * (rand7() - 1) + (rand7() - 1);
        return curr % 10 + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
