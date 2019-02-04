//
//  main.cpp
//  647.Palindromic Substrings
//
//  Created by Abysman on 2019/2/4.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, len = s.size();
        for (int i = 0; i < len; ++i) {
            for (int j = 0; i - j >= 0 && i + j < len && s[i - j] == s[i + j]; ++j) res++;
            for (int j = 0; i - j - 1 >= 0 && i + j < len && s[i - j - 1] == s[i + j]; ++j) res++;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
