//
//  main.cpp
//  91.Decode Ways
//
//  Created by stevenxu on 9/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.size();
        vector<int> tmp(n + 1, 0);
        tmp[0] = 1;
        tmp[1] = 1;
        for (int i = 2;i < n + 1; ++i) {
            int num = stoi(s.substr(i - 2, 2));
            if (num >= 10 && num <= 26) tmp[i] += tmp[i - 2];
            if (s[i - 1] != '0') tmp[i] += tmp[i - 1];
        }
        return tmp[n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
