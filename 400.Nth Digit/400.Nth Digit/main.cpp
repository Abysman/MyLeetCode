//
//  main.cpp
//  400.Nth Digit
//
//  Created by Abysman on 2019/1/10.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int findNthDigit(int n) {
        long digits = 1, num = 9;
        while (n - digits * num > 0) {
            n -= digits * num;
            num *= 10;
            digits += 1;
        }
        num = pow(10, digits - 1) + n / digits;
        if (n % digits == 0) num -= 1;
        string ns = to_string(num);
        int index = n % digits == 0 ? digits - 1 : n % digits - 1;
        return ns[index] - '0';
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
