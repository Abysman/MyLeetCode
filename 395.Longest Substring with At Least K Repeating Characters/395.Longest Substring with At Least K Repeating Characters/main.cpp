//
//  main.cpp
//  395.Longest Substring with At Least K Repeating Characters
//
//  Created by stevenxu on 12/4/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = (int)s.length();
        unordered_map<char, int> count;
        for (char c : s) ++count[c];
        int mid = 0;
        while (mid < n && count[s[mid]] >= k) ++mid;
        if (mid == n) return n;
        int left = longestSubstring(s.substr(0, mid), k);
        while (mid < n && count[s[mid]] < k) ++mid;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
