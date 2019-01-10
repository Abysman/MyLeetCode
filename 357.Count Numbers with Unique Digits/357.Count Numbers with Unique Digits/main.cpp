//
//  main.cpp
//  357.Count Numbers with Unique Digits
//
//  Created by Abysman on 2019/1/10.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 10) n = 10;
        int res = 0;
        vector<int> record(10, 9);
        record[0] = 1;
        record[1] = 9;
        record[2] = 81;
        for (int i = 3; i <= n; ++i) {
            record[i] = record[i - 1] * (11 - i);
        }
        for (int i = 0; i <= n; ++i) res += record[i];
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
