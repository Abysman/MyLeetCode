//
//  main.cpp
//  397.Integer Replacement
//
//  Created by stevenxu on 12/27/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX) return 32;
        int count = 0;
        while (n != 1) {
            if (n & 1) {
                if (n & 2 && n != 3) {
                    n++;
                } else {
                    n--;
                }
            } else {
                n >>= 1;
            }
            count++;
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
