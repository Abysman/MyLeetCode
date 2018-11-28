//
//  main.cpp
//  409.Longest Palindrome
//
//  Created by Abysman on 2018/11/28.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> record;
        int res = 0;
        int flag = 0;
        for (auto t:s) {
            record[t] += 1;
        }
        for (auto it = record.begin(); it != record.end(); ++it) {
            cout << it->first << " " << it->second << "\n";
            if (it->second % 2 == 1) {
                res += it->second;
                if (flag == 1) res -= 1;
                flag = 1;
            }
            else if (it->second % 2 == 0) {
                res += it->second;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
