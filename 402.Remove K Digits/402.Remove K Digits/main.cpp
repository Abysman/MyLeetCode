//
//  main.cpp
//  402.Remove K Digits
//
//  Created by stevenxu on 11/5/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (char c: num) {
            while (res.size() && res.back() > c && k) {
                res.pop_back();
                k--;
            }
            if (res.size() || c != '0') res.push_back(c);
        }
        while (res.size() && k--) res.pop_back();
        return res.empty() ? "0" : res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
