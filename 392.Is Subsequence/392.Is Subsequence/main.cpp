//
//  main.cpp
//  392.Is Subsequence
//
//  Created by Abysman on 2018/11/7.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int i = 0, j = 0;
        int slen = s.length();
        int tlen = t.length();
        while (j < tlen) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        if (i == slen) return true;
        else return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
