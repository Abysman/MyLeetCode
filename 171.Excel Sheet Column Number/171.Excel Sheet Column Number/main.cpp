//
//  main.cpp
//  171.Excel Sheet Column Number
//
//  Created by Abysman on 2018/8/3.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            int tmp = (int(s[i]) - int('A') + 1) * pow(26, s.length() - i - 1);
            res += tmp;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << int('a') - int('b') << "\n";
    return 0;
}
