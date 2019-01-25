//
//  main.cpp
//  5.Longest Palindromic Substring
//
//  Created by Abysman on 2018/10/8.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) return s;
        int i = 0, j = len - 1, maxLen = 0, index = 0, currLen = 0;
        for (int i = 0; i < len; ++i) {
            if (len - i <= maxLen / 2) break;
            if (s[i] == s[i+1]) {
                currLen = helper(s, i, 1);
                if (currLen > maxLen) {
                    maxLen = currLen;
                    index = i;
                }
            }
            currLen = helper(s, i, 0);
            if (currLen > maxLen) {
                maxLen = currLen;
                index = i;
            }
        }
        return s.substr(index - (maxLen - 1) / 2, maxLen);
    }
    
    int helper(string s, int index, int flag) {
        int i = index - 1;
        int j = index + 1;
        int currLen = 1;
        if (flag == 1) {
            i = index;
            currLen = 0;
        }
        while (i >= 0 && j <= s.length() - 1) {
            if (s[i--] == s[j++]) currLen += 2;
            else return currLen;
        }
        return currLen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
