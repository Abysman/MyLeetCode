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
        if (str.empty()) return 0;
        int len = str.size(), i = 0, flag = 1, res = 0;
        while (i < len && str[i] == ' ') i++;
        if (str[i] == '-' || str[i] == '+') flag = 1 - 2 * (str[i++] == '-');
        while (i < len && isdigit(str[i])) {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] > '7')) return flag == 1 ? INT_MAX :INT_MIN;
            res =  res * 10 + (str[i++] - '0');
        }
        return res * flag;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
