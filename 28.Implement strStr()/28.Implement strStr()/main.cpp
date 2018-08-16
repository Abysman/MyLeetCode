//
//  main.cpp
//  28.Implement strStr()
//
//  Created by Abysman on 2018/8/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> calc_next(string s) {
        int i = 0, j = -1;
        vector<int> next(s.length() + 1, 0);
        next[0] = -1;
        while (i < s.length()) {
            if (j == -1 || s[i] == s[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else {
                j = next[j];
            }
        }
        return next;
    }
    
    int strStr(string haystack, string needle) {
        vector<int> next = calc_next(needle);
        int i = 0, j = 0;
        int h_length = haystack.length();
        int n_length = needle.length();
        while (i < h_length && j < n_length) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
            
        }
        if (j == needle.length()) {
            return i - j;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string haystack = "mississippi";
    string needle = "issipi";
    Solution sol = Solution();
    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}
