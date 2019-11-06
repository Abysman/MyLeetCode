//
//  main.cpp
//  738.Monotone Increasing Digits
//
//  Created by stevenxu on 11/5/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int n = s.size(), mark = n;
        for (int i = n - 1; i > 0; --i) {
            if (s[i - 1] > s[i]) {
                mark = i;
                s[i - 1] -= 1;
            }
        }
        for (int i = mark; i < n; ++i) s[i] = '9';
        return stoi(s);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
