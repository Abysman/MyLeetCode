//
//  main.cpp
//  374.Guess Number Higher or Lower
//
//  Created by Abysman on 2018/11/19.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int h = n;
        int mid;
        while (true) {
            mid = l + (h - l)/2;
            if (guess(mid) == 0) return mid;
            else if (guess(mid) == -1) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
