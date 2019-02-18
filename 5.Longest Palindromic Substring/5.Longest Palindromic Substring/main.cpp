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
        if (s.size() < 2) return s;
        int start = 0, max_len = 1, len = s.size();
        int i = 0;
        while (i < len) {
            if (len - i <= max_len / 2) break;
            int left = i, right = i;
            while (right < len - 1 && s[right + 1] == s[right]) right++;
            i = right + 1;
            while (left > 0 && right < len - 1 && s[right + 1] == s[left - 1]) {
                left--;
                right++;
            }
            int curr_len = right - left + 1;
            if (curr_len > max_len) {max_len = curr_len; start = left;}
        }
        return s.substr(start, max_len);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
