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
        int maxLen = 0;
        int res = -1;
        if (len < 2) return s;
        for (int i = 0; i <= len - 1; ++i) {
            if (len - i <= maxLen / 2) break;
            if (s[i] == s[i + 1]) {
                int currLen = helper(s, i, 1);
                if (currLen > maxLen) {
                    maxLen = currLen;
                    res = i;
                }
            }
            int currLen = helper(s, i, 0);
            if (currLen > maxLen) {
                maxLen = currLen;
                res = i;
            }
        }
        return s.substr(res - (maxLen - 1) / 2, maxLen);
    }
    
    int helper(string s, int index,int flag) {
        int len = s.length(), i , j;
        i = index - 1;
        j = index + 1;
        int currLen = 1;
        if (flag == 1) {
            i = index;
            currLen = 0;
        }
        while (i >= 0 && j <= len - 1) {
            if (s[i] == s[j]) {
                currLen += 2;
                i--;
                j++;
                continue;
            }
            return currLen;
        }
        return currLen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
