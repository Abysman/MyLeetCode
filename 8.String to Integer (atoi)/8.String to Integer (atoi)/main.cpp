//
//  main.cpp
//  8.String to Integer (atoi)
//
//  Created by Abysman on 2019/2/9.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, base = 0, curr = 0;
        while (str[curr] == ' ') curr++;
        if (str[curr] == '+' || str[curr] == '-') sign = 1 - 2 * (str[curr++] == '-');
        while (str[curr] >= '0' && str[curr] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[curr] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            base = base * 10 + (str[curr++] - '0');
        }
        return sign * base;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
