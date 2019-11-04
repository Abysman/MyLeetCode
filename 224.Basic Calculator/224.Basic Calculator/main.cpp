//
//  main.cpp
//  224.Basic Calculator
//
//  Created by stevenxu on 11/4/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int calculate(string s) {
        stack<int> ops, nums;
        int n = s.size(), res = 0, sign = 1, curr = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                curr = curr * 10 + (c - '0');
            } else if (c == '+') {
                res += curr * sign;
                curr = 0;
                sign = 1;
            } else if (c == '-') {
                res += curr * sign;
                curr = 0;
                sign = -1;
            } else if (c == '(') {
                nums.push(res);
                ops.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += curr * sign;
                curr = 0;
                res = res * ops.top() + nums.top();
                nums.pop();
                ops.pop();
            }
        }
        res += curr * sign;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
